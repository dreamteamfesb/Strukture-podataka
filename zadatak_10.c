#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "stdbool.h"
#define MAX 128


struct CvorStabla;
typedef struct CvorStabla* Pok;

struct CvorStabla {

	char znak;
	Pok lijevo;
	Pok desno;
};

struct lista;
typedef struct lista* position;

struct lista {

	Pok cvor;
	position next;
};

char* datoteka(void);
position Stvori_stog_cvor(void);
Pok Stvori_stablo_cvor(void);
Pok Stvori_Stablo(Pok, position, char*);
bool IsNumber(char);
bool IsOperator(char);
int push(Pok, position);
Pok pop(position);
int ispis_stabla(Pok, char*, FILE**);

int main()
{
	char* ime_dat = NULL;
	FILE* file = NULL;
	char* spremnik = NULL;
	int velicina = 0;
	Pok root = NULL;
	position head = NULL;
	
	/*char* prvi = NULL;
	char* drugi = NULL;
	prvi = (char*)malloc(MAX * sizeof(char));
	drugi = (char*)malloc(MAX * sizeof(char));
	fgets(prvi, MAX, stdin);
	fgets(drugi, MAX, stdin);
	*/

	spremnik = (char*)malloc(MAX * sizeof(char));
	ime_dat = datoteka();
	printf("%s\n", ime_dat);

	file = fopen(ime_dat, "r");
	if (file == NULL)
	{
		printf("Datoteka nije otvorena!\n");
		exit(1);
	}

	fgets(spremnik, MAX, file);
	printf("Spremnik sadrzi: %s\n", spremnik);

	fclose(file);

	velicina = strlen(spremnik);
	printf("Velicina spremnika: %d\n", velicina);

	head = Stvori_stog_cvor();
	root = Stvori_stablo_cvor();
	
    root = Stvori_Stablo(root, head, spremnik);
	
	file = fopen(ime_dat, "w");
	fprintf(file, "\nInfix izraz:\n");
	ispis_stabla(root, ime_dat, &file);
	fclose(file);
    
	printf("\n");




	return 0;
}

char* datoteka()
{
	char* ime = NULL;
	ime = (char*)malloc(MAX * sizeof(char));

	printf("Ime datototeke: ");
	scanf("%s", ime);
	if (strrchr(ime, '.') == NULL)
		strcat(ime, ".txt");

	return ime;
}
position Stvori_stog_cvor()
{
	position temp = NULL;
	temp = (position)malloc(sizeof(struct lista));
	if (temp == NULL)
	{
		printf("Memorija nije alocirana!\n");
		exit(1);
	}

	temp->cvor = NULL;
	temp->next = NULL;

	return temp;
}
Pok Stvori_stablo_cvor(void)
{
	Pok temp = NULL;
	temp = (Pok)malloc(sizeof(struct CvorStabla));

	if (temp == NULL)
	{
		printf("Memorija nije alocirana!\n");
		exit(1);
	}

	temp->desno = NULL;
	temp->lijevo = NULL;
	temp->znak = NULL;

	return temp;
}
Pok Stvori_Stablo(Pok root, position head, char* spremnik)
{
	Pok glava = NULL;
	Pok cvor1 = NULL;
	Pok cvor2 = NULL;
	position pomocna = NULL;
	Pok prvi = NULL;
	Pok drugi = NULL;
	char c;

	printf("U funkciji sam!\n");
	printf("%s", spremnik);
	
	while (*spremnik != '\0')
	{
		sscanf(spremnik, "%c", &c);
		printf("\nZnak je: %c", c);
		if (IsNumber(c))
		{
			cvor1 = Stvori_stablo_cvor();
			cvor1->znak = c;
			push(cvor1, head);
		}

		if (IsOperator(c))
		{
			prvi = pop(head);
			drugi = pop(head);
			cvor2 = Stvori_stablo_cvor();
			cvor2->desno = prvi;
			cvor2->lijevo = drugi;
			cvor2->znak = c;
			push(cvor2, head);
		}
             
		spremnik++;
	}
	
	printf("\n");
	glava = pop(head);

	return glava;

}
bool IsNumber(char c)
{
	if (c >= '1' && c <= '9')
		return true;
	return false;
}
bool IsOperator(char a)
{
	if (a == '+' || a == '-' || a == '*' || a == '/')
		return true;
	return false;
}
int push(Pok cvor_stabla, position head)
{
	position temp = NULL;
	position pomocna = NULL;

	if (head == NULL)
		printf("Stog je prazan!\n");

	temp = Stvori_stog_cvor();
	temp->cvor = cvor_stabla;

	pomocna = head->next;
	temp->next = pomocna;
	head->next = temp;

	return 0;

}
Pok pop(position head_stoga)
{
	Pok pomocna = NULL;
	position temp = NULL;

	if (head_stoga->next == NULL)
		printf("Stog je prazan!");
	
	temp = head_stoga->next;
	pomocna = temp->cvor;

	head_stoga->next = temp->next;
	free(temp);

	return pomocna;
}

int ispis_stabla(Pok root, char* ime, FILE** fp)
{
	
	if (root != NULL)
	{
		if (root->lijevo != NULL)
			fprintf(*fp, "(");
		
		ispis_stabla(root->lijevo, ime, fp);
		fprintf(*fp, " %c ", root->znak);
		ispis_stabla(root->desno, ime, fp);
		
		if (root->desno != NULL)
			fprintf(*fp, ")");
	}
	return 0;
}
