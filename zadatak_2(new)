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
osoba* Insert_poc(osoba* );
int Print(osoba* );
int Insert_kraj(osoba*);
osoba* Search(osoba*);
int Remove(osoba*);

int main()
{
	int odabir = 0;

	osoba* head = NULL;
	osoba* Student = NULL;
	
	while (odabir != 6)
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



	

