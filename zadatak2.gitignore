 
 
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define dulj 20
#define velicina 1024

struct student;
typedef struct student  _STUDENT;
typedef struct student *position;

struct student {
	char ime[dulj];
	char prezime[dulj];
	int godina_rod;
	position next;

};

int izbor();
int stv_list(position);
int unesi(position);
int ispis(position);
int add_first(position);
int add_end(position);
int remove(position);

position trazi(position);


int main(void)
{

	_STUDENT head;
	int c = 0;
	int j = 0;
	position stud_F = NULL;
	head.next = NULL;


	while (c != 5)
	{
		c = 0;
		c = izbor();

		if (c == 1)
		{
			add_first(&head);
		}
		else if (c == 2)
		{
			ispis(head.next);
		}
		else if (c == 3)
		{
			add_end(&head);
		}
		else if (c == 4)
		{
			stud_F = trazi(head.next);
			if (stud_F != NULL)
				printf("\nTrazeni student je: %s %s %d\n", stud_F->ime, stud_F->prezime, stud_F->godina_rod);
			else printf("\nTrazeni student nije pronaden.\n");
		}
		else if (c == 5)
		{
			continue;
		}
		else
			printf("Pogresan izbor\n");
	}
	return 0;
}

int izbor()
{
	int n = 0;

	printf("Funkcija : \n");
	printf("1. Dodaj na pocetak\n");
	printf("2. Ispis\n");
	printf("3. Dodaj na kraj\n");
	printf("4. Pronadi element(prezime)\n");
	printf("5. Izlaz\n");

	scanf(" %d", &n);
	return n;
}

int stv_list(position *head)
{
	position q = NULL;

	*head = (position)malloc(sizeof(_STUDENT));
	if (*head == NULL) return -1;

	q = *head;
	q->next = NULL;

	return 0;
}

int unesi(position p)
{
	if (p == NULL)
		return -1;

	printf("Ime, prezime, godina rodenja :\n");
	scanf(" %s %s %d", p->ime, p->prezime, &p->godina_rod);

	return 0;
}

int add_first(position p)
{
	position q = NULL;
	int k = -1;

	k = stv_list(&q);
	if (k == -1)
	{
		printf("Greska");
		return -1;
	}

	k = unesi(q);
	if (k == -1)
	{
		printf("Greska");
		return -1;
	}

	q->next = p->next;
	p->next = q;

	return 0;
}

 int add_end(position p)
{
	if (p == NULL) return NULL;

	while (p->next != NULL)
		p = p->next;

	return add_first(p);
}
 int ispis(position p)
{
	if (p == NULL)
		printf("Lista je prazna\n");
	else
	{
		printf("Lista : \n");
		while (p != NULL)
		{
			printf("%s %s %d\n", p->ime, p->prezime, p->godina_rod);
			p = p->next;
			printf("\n");
		}
	}
	return 0;
}

    position trazi(position p)
{
	char* prezime;

	prezime = (char*)malloc(velicina * sizeof(char));
	
	if (prezime == NULL) return NULL;
	
	memset(prezime, '\0', velicina);

	printf("Unesite prezime: ");
	
	scanf(" %s", prezime);

	while ((p != NULL) && strcmp(p->prezime, prezime) != 0)
		p = p->next;
	free(prezime);

	return p;
}
