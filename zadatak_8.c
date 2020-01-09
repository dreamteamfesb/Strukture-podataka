#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX 50

 struct CvorStabla;
 typedef struct CvorStabla* Pok;

struct CvorStabla {

	char* ime_dir;
	Pok dijete;
	Pok brat;
};

 struct stog;
 typedef struct stog* pok_S;

struct stog {

	Pok Cvor;
	pok_S next;
};

int PrintPut(char*);
int IspisiDir(Pok, char*);
Pok Nazad(Pok, char*, pok_S);
int Pop(pok_S, Pok *);
Pok Idi_u_dir(Pok, char*, char*, pok_S);
int Push(pok_S, Pok);
int Stvori_dir(Pok, char*);

int main()
{
	struct CvorStabla root;
	struct stog head;
	root.dijete = NULL;
	root.brat = NULL;
	head.next = NULL;
	int pom = 0;
	Pok proot = &root;
	Pok pater = NULL;
	char* put = NULL;
	char* naredba = NULL;  
	char* uputa = NULL;    
    char* direktorij = NULL;
	
    printf("Ime root direktorija: ");
	
	root.ime_dir = (char*)malloc(sizeof(char) * MAX);
	fgets(root.ime_dir, MAX, stdin);
	
	pater = &root;

	put = (char*)malloc(MAX * sizeof(char));
	memset(put, '\0', MAX);

	strcat(put, proot->ime_dir);
	strcat(put, ":\\");
	
	uputa = (char*)malloc(MAX * sizeof(char));
	naredba = (char*)malloc(MAX * sizeof(char));
	direktorij = (char*)malloc(MAX * sizeof(char));

	
	while (strcmp(naredba, "izlaz") != 0)
	{
		memset(uputa, 0, MAX);
		memset(naredba, 0, MAX);
		memset(direktorij, 0, MAX);
		
		PrintPut(put);

		fgets(uputa, MAX, stdin);
		pom = sscanf(uputa, "%s %s", naredba, direktorij);

		if (strcmp(naredba, "dir") == 0)
		{
			if (pom != 1)
			{
				printf("Neispravno unesena naredba!");
			}
			else
				IspisiDir(pater, put);
		}
		else if (strcmp(naredba, "cd..") == 0)
		{
			if (pom != 1)
				printf("Neispravno unesena naredba!");
			else
				pater = Nazad(pater, put, &head);
		}
		else if (strcmp(naredba, "cd") == 0)
		{
			if (pom != 2)
				printf("Neispravno unesena naredba!");
			else
				pater = Idi_u_dir(pater, direktorij, put, &head);
		}
		else if (strcmp(naredba, "md") == 0)
		{
			if (pom != 2)
				printf("Neispravno unesena naredba!");
			else
				Stvori_dir(pater, direktorij);
		}

		else if (strcmp(naredba, "exit") == 0)
		{
			if (pom != 1)
				printf("Naredba unesena neispavno!");

			printf("Izlaz iz programa!");
		}
		else
			printf("\n%s nije naredba koju sadrzi ovaj program!", naredba);


	}

	return 0;
}

int PrintPut(char* p)
{
	printf("%s>", p);
    return 0;
}
int IspisiDir(Pok cvor, char* p)
{
		int brojac = 0;
		printf("Direktoriji od %s ", p);
        
		cvor = cvor->dijete;
		

		if (cvor == NULL)
		{
			printf("Nema direktorija!\n");
		}
		else
		{
			while (cvor->brat != NULL)
			{
				printf("\n\t <DIR>   %s", cvor->ime_dir);
				cvor = cvor->brat;
				brojac++;
			}

			printf("\n\t\t %d Dir(s)\n", brojac);
		}
		return 0;
	}

Pok Nazad(Pok cvor, char* put, pok_S head)
{
	int kontrola = 0;
	Pok temp = NULL;

	kontrola = Pop(head, &temp);
	if (kontrola == 0)
	{
		return cvor;
	}

	return temp;

}
int Pop(pok_S head, Pok* cvor)
{
	pok_S pom = NULL;

	if (head->next == NULL)
		return -1;

	pom = head->next;

	if (pom == NULL)
		return -1;

	head->next = pom->next;
	if (pom->Cvor == NULL)
		return -1;

	*cvor = pom->Cvor;
	free(pom);

	return 0;
}
Pok Idi_u_dir(Pok papa, char* ime, char* p, pok_S head)
{
	Pok temp = NULL;
	if (papa == NULL)
	{
		printf("Greska!");
		exit(1);
	}
	temp = papa->dijete;
	
	while (temp != NULL && strcmp(temp->ime_dir, ime) != 0)
	{
		temp = temp->brat;
	}
	if (temp == NULL)
	{
		printf("Ne postoji taj direktorij!");
		return papa;
	}
	Push(head, papa);

	strcat(p, "\\");
	strcat(p, temp->ime_dir);

	return temp;
}

int Push(pok_S head, Pok papa)
{
	pok_S temp = NULL;
	temp = (pok_S)malloc(sizeof(struct stog));

	if (temp == NULL)
	{
		printf("Memorija nije alocirana!");
		return -1;
	}
	temp->Cvor = papa;
	temp->next = head->next;
	head->next = temp;

	return 0;
}
int Stvori_dir(Pok papa, char* ime)
{
	Pok pom = (Pok)malloc(sizeof(struct CvorStabla));

	 pom->ime_dir = ime;
	 
	if (papa->dijete == NULL)
	{
		papa->dijete = pom;
		pom->brat = NULL;
		pom->dijete = NULL;
	}
	else 
	{
		Pok temp = papa->dijete;
		while (temp->brat != NULL)
		{
			temp = temp->brat;
		}
		pom->brat = temp->brat;
		temp->brat = pom;
	}
	
	return 0;
}
