#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct Cvor* Pok;


struct Cvor
{
	int broj;
	Pok next;
};

Pok Stvori_cvor(Pok);
Pok Sortirani_unos(Pok, Pok );
int Ispis_liste(Pok);
Pok Sort_Unija(Pok, Pok, Pok);
Pok Ukloni_dupli(Pok);
Pok Presjek(Pok, Pok, Pok);

int main()
{
	int n = 0, i = 0;

	Pok head_unija = NULL;
	Pok head1 = NULL;
	Pok head2 = NULL;
	Pok cvor = NULL;
	Pok head_presjek = NULL;

	printf("Broj clanova 1. liste: ");
	scanf(" %d", &n);

	i = 0;
	while (i < n)
	{
		cvor = Stvori_cvor(head1);
	    head1 = Sortirani_unos(head1, cvor);
	i++;
}

	printf("Lista 1: \n");
	Ispis_liste(head1);
	
	printf("Broj clanova 2. liste: ");
		scanf("%d", &n);
		i = 0;
		while (i < n)
		{
			cvor = Stvori_cvor(head2);
			head2 = Sortirani_unos(head2, cvor);
			i++;
		}
		printf("Lista 2: \n");
		Ispis_liste(head2);

		head_unija = Sort_Unija(head1, head2, head_unija);
		
		head_unija = Ukloni_dupli(head_unija);
		printf("Unija: ");
		Ispis_liste(head_unija);

		head_presjek = Presjek(head1, head2, head_presjek);
		printf("Presjek: ");
		Ispis_liste(head_presjek);
	


	return 0;
}

Pok Stvori_cvor(Pok head)
{
	int br = 0;
	Pok novi_cvor = (Pok)malloc(sizeof(struct Cvor));

		printf("Broj : ");
        scanf(" %d", &br);

		novi_cvor->broj = br;
		novi_cvor->next = NULL;

		return novi_cvor;

}

Pok Sortirani_unos(Pok head, Pok novi_cvor)
{
	Pok temp;

	if (head == NULL || head->broj >= novi_cvor->broj)
	{
		novi_cvor->next = head;
		head = novi_cvor;
	}

	else {

		temp = head;
		while (temp->next != NULL && temp->next->broj < novi_cvor->broj)
		{
			temp = temp->next;
		}
		novi_cvor->next = temp->next;
		temp->next = novi_cvor;
	}

	

	return head;
}

int Ispis_liste(Pok head)
{

	Pok temp = head;

	while (temp != NULL)
	{
		printf("%d ", temp->broj);
		temp = temp->next;
	}
	printf("\n");

	return 0;
}

Pok Sort_Unija(Pok head1, Pok head2, Pok head)
{
	if (head1 == NULL)
		return head2;
	else if(head2 == NULL)
		return head1;


	if (head1->broj <= head2->broj) {
		head = head1;
		head->next = Sort_Unija(head1->next, head2, head);
	}
	else {
		head = head2;
		head->next = Sort_Unija(head1, head2->next, head);
	}
	return head;
}

Pok Ukloni_dupli(Pok head)
{

	Pok temp = head;

	Pok cvor_next = NULL;

	
	if (temp == NULL)
		printf("Lista je prazna!");
	else
	{
		while (temp->next != NULL)
		{

			if (temp->broj == temp->next->broj)
			{
				cvor_next = temp->next->next;
				free(temp->next);
				temp->next = cvor_next;
			}
			else
			{
				temp = temp->next;
			}
		}
	}
	return head;
}



Pok Presjek(Pok head1, Pok head2, Pok head)
{

	Pok temp = NULL;

	while (head1 && head2)
	{
		if (head1->broj > head2->broj)
			head1 = head1->next;
		else if(head1->broj < head2->broj)
			head2 = head2->next;


			temp->broj = head1->broj;
			temp->next = head->next;
			head->next = temp;
			head = temp;

			head1 = head1->next;
			head2 = head2->next;
		}
	

	return head;
}
