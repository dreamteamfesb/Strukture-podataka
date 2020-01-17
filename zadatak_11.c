#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define velicina 11
#define MAX 128

struct student;
typedef struct student* pozicija;
typedef struct student* lista;

struct student {
	char* ime = NULL;
	char* prezime = NULL;
	int m_broj;
	pozicija next;
};

struct hashT;
typedef struct hashT* hashTab;

struct hashT {
	int vel;
	lista* list;
};

pozicija unos_studenta(void);
int index(char*);
hashTab inicijalizacija(void);
int opcije(void);
int ubaci(int, pozicija, hashTab);

int main()
{
	hashTab A = NULL;
	int in = 0;
	int broj = 0;
	pozicija st = NULL;

	A = inicijalizacija();
	
	while (1)
	{
		opcije();
		printf("Broj: ");
		scanf("%d", &broj);
		switch (broj)
		{
		case 1: 
			st = unos_studenta();
			in = index(st->prezime);
			printf("Index je : %d\n", in);
			ubaci(in, st, A);
			break;
			
		}
	}




	return 0;
}
 
pozicija unos_studenta()
{
	char* ime = NULL;
	char* prezime  = NULL;
	int maticni_broj = 0;
	int x = 0;
	pozicija s = NULL;
	s = (pozicija)malloc(sizeof(struct student));

	ime = (char*)malloc(MAX * sizeof(char));
	prezime = (char*)malloc(MAX * sizeof(char));
	
	printf("Ime: ");
	scanf("%s", ime);
	printf("Prezime: ");
	scanf(" %s", prezime);
	printf("Maticni broj: ");
	scanf("%d", &maticni_broj);

	s->ime = ime;
	s->prezime = prezime;
	s->m_broj = maticni_broj;


	return s;
}
int index(char* prez)
{
	int code = NULL;
	int i = 0;
	while (*prez != '\0' && i < 5)
	{
		code += *prez++;
		i++;
	}

	return code % velicina;
}
hashTab inicijalizacija(void) {
	
	hashTab H  = NULL; 
	int i = 0;

	H = (hashTab)malloc(sizeof(struct hashT));
	
	if (H == NULL)
	{
		printf("Memorija nije alocirana!\n");
		return NULL;
	}

	H->vel = velicina;

	H->list = (lista*)malloc(sizeof (lista)*H->vel); 
	
	if (H->list == NULL)
	{
		printf("Memorija nije alocirana!\n");
		return NULL;
	}

	for (i = 0; i < H->vel; i++)
	{
		H->list[i] = NULL;
	}
	
     return H;
}
int opcije()
{
	printf(" 1. Unos\n");


	return 0;

}
int ubaci(int index, pozicija student, hashTab H)
{
	pozicija temp = NULL;
	pozicija prati = NULL;

	if (H->list[index] == NULL)
	{
		H->list[index] = student;
		student->next = NULL;

	}
    else
	{
		temp = H->list[index];
		
		while (strcmp(temp->prezime, student->prezime) < 0)
		{
			prati = temp;
			temp = temp->next;
		}

		student->next = temp;
		prati->next = student;
	}
	
	return 0;
}
