#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct osoba {

	char ime[20];
	char prezime[20];
	int god_rod;
	struct osoba* next;
};

int izbor(void);
osoba* Insert_poc(osoba*);
int Print(osoba*);
int Insert_kraj(osoba*);
osoba* Search(osoba*);
int Remove(osoba*);
int Insert_iza(osoba*);
int Insert_ispred(osoba*);
int Sort(osoba*);
int Insert_dat(osoba*);
int Read_dat(void);

int main()
{
	int odabir = 0;

	osoba* head = NULL;
	osoba* Student = NULL;

	while (odabir != 11)
	{
		odabir = izbor();

		if (odabir == 1)
		{
			head = Insert_poc(head);
		}
		else if (odabir == 2)
		{
			Print(head);
		}
		else if (odabir == 3)
		{
			Insert_kraj(head);
		}
		else if (odabir == 4)
		{
			Student = Search(head);
			if (Student != NULL)
				printf("Student: %s %s %d\n", Student->ime, Student->prezime, Student->god_rod);
			else
				printf("Student nije pronaden\n");
		}
		else if (odabir == 5)
		{
			Remove(head);
		}
		else if (odabir == 6)
		{
			Insert_iza(head);
		}
		else if (odabir == 7)
		{
			Insert_ispred(head);
		}
		else if (odabir == 8)
		{
			Sort(head);
		}
		else if (odabir == 9)
		{
			Insert_dat(head);
		}
		else if (odabir == 10)
		{
			Read_dat();
		}
		else
			printf("Nepostojeci broj funkcije!\n");
		
	}
	return 0;
}

int izbor(void)
{
	int i = 0;
	int odabir = 0;
	printf("\nFunkcije: \n");
	printf("Dodaj na pocetak : 1\n");
	printf("Ispisi listu: 2\n");
	printf("Dodaj na kraj: 3\n");
	printf("Trazi po prezimenu: 4\n");
	printf("Ukloni clan: 5\n");
	printf("Unos iza: 6\n");
	printf("Unos ispred: 7\n");
	printf("Sortiraj: 8\n");
	printf("Ucitaj u datoteku: 9\n");
	printf("Citaj iz datoteke: 10\n");
	printf("Izlaz iz progarama 11\n");

	printf("Odaberi broj funkcije: ");
	scanf("%d", &i);

	return i;
}

osoba* Insert_poc(osoba* head)
{
	struct osoba* temp = (osoba*)malloc(sizeof(struct osoba));

	printf("Unesite ime, prezime, godinu rodenja : ");
	scanf("%s %s %d", temp->ime, temp->prezime, &temp->god_rod);

	temp->next = head;
	head = temp;


	return head;
}
int Print(osoba* head)
{

	if (head == NULL)
		printf("Lista je prazna\n");
	else
	{
		printf("\nLista je : \n");
		while (head != NULL)
		{
			printf("%s %s %d\n", head->ime, head->prezime, head->god_rod);
			head = head->next;
		}
	}
	return 0;
}
int Insert_kraj(osoba* head)
{
	struct osoba* temp = (osoba*)malloc(sizeof(struct osoba));
	struct osoba* temp2 = head;

	printf("Ime prezime i godina rodenja: ");
	scanf("%s %s %d", temp->ime, temp->prezime, &temp->god_rod);

	temp->next = NULL;

	if (head == NULL)
	{
		head = temp;
	}

	while (temp2->next != NULL)
	{
		temp2 = temp2->next;
	}
	temp2->next = temp;

	return 0;
}
osoba* Search(osoba* head)
{
	char prez[20];
	printf("Prezime: ");
	scanf(" %s", prez);

	while ((head != NULL) && strcmp(head->prezime, prez) != 0)
		head = head->next;

	return head;
}

int Remove(osoba* head)
{
	int n = 0;
	int i = 0;

	printf("Koji element zelite obrisati: ");
	scanf("%d", &n);

	struct osoba* temp1 = head;
	for (i = 0; i < n - 2; i++)
		temp1 = temp1->next;

	struct osoba* temp2 = temp1->next;
	temp1->next = temp2->next;

	free(temp2);

	if (n == 1)
	{
		head = temp1->next;
		free(temp1);

	}
	return 0;
}
int Insert_iza(osoba* head)
{
	int n = 0;
	int i = 0;

	printf("Iza kojeg elementa: ");
	scanf("%d", &n);
	struct osoba* temp1 = head;

	if (temp1 == NULL)
	{
		printf("Prethodni clan ne moze pokazivat na NULL\n");
	}
	struct osoba* temp2 = (struct osoba*)malloc(sizeof(struct osoba));

	for (i = 0; i < n-1; i++)
		temp1 = temp1->next;

	printf("Ime, prezime, godinu rodenja: ");
	scanf("%s %s %d", temp2->ime, temp2->prezime, &temp2->god_rod);
	
    temp2->next = temp1->next;
	temp1->next = temp2;
    
	return 0;
}

int Insert_ispred(osoba* head)
{
	int i = 0, n = 0;
	printf("Ispred kojeg elementa: ");
	scanf("%d", &n);
    
	struct osoba* temp1 = head;

	for (i = 0; i < n - 2; i++)
	{
		temp1 = temp1->next;
	}
	
	Insert_poc(temp1);
    return 0;
}
int Sort(osoba* head)
{
	osoba* pret_a;
	osoba* a;
	osoba* temp;
	osoba* end = NULL;

	while (head->next != end)
	{
		pret_a = head;
		a = head->next;
		while (a->next != end)
		{
			if (strcmp(a->prezime, a->next->prezime) > 0)
			{
				temp = a->next;
				pret_a->next = temp;
				a->next = temp->next;
				temp->next = a;
				a = temp;
			}
			pret_a = a;
			a = a->next;
		}
		end = a;
	}
	return 0;
}
int Insert_dat(osoba* head)
{
	char ime[20];
	osoba* temp = head;
	FILE* file = NULL;

	printf("Datoteka: ");
	scanf(" %s", ime);

	if (strchr(ime, '.') == NULL)
		strcat(ime, ".txt");

	file = fopen(ime, "w");
	if (file == NULL)
	{
		printf("Datoteka neuspjesno otvorena\n");
		return -1;
	}
	while (temp != NULL)
	{
		fprintf(file, "%s %s %d\n", temp->ime, temp->prezime, temp->god_rod);
		temp = temp->next;
	}

	fclose(file);
	return 0;
}
int Read_dat()
{
	FILE* file = NULL;
	char ime[20];
	char c;
	struct osoba* temp = (osoba*)malloc(sizeof(struct osoba));

	printf("Ime: ");
	scanf(" %s", ime);

	if (strchr(ime, '.') == NULL)
		strcat(ime, ".txt");

	file = fopen(ime, "r");
	if (file == NULL)
	{
		printf("Datoteka neuspjesno otvorena\n");
		return -1;
	}

	
		while (!feof(file))
		
			putchar(c = getc(file));
	     	puts("\n");
	    	fclose(file);
	
	return 0;
}



			
