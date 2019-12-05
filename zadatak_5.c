

 #define _CRT_SECURE_NO_WARNINGS
  #include <stdio.h>
  #include <stdlib.h>


struct Cvor;
typedef struct Cvor* Pok;

  struct Cvor
 {
   	int broj;
    Pok next;
};

Pok Stvori_cvor(Pok);
int Sortirani_unos(Pok, Pok);
int Ispis_liste(Pok);
Pok Sort_Unija(Pok, Pok, Pok);
int Ukloni_dupli(Pok);
int Presjek(Pok, Pok, Pok);
int Unija(Pok, Pok, Pok);

int main()
{
	int n = 0, i = 0;

	struct Cvor unija, head1, head2, presjek;
	unija.next = NULL;
    head1.next = NULL;
    head2.next = NULL;
    presjek.next = NULL;
	Pok cvor = NULL;

    printf("Broj clanova 1. liste: ");
	scanf(" %d", &n);

	i = 0;
	while (i < n)
	{
		cvor = Stvori_cvor(&head1);
		Sortirani_unos(&head1, cvor);
		i++;
	}

	printf("Lista 1: \n");
	Ispis_liste(&head1);

	printf("Broj clanova 2. liste: ");
	scanf("%d", &n);
	i = 0;
	while (i < n)
	{
		cvor = Stvori_cvor(&head2);
		Sortirani_unos(&head2, cvor);
		i++;
	}
	printf("Lista 2: \n");
	Ispis_liste(&head2);

	Sort_Unija(&head1, &head2, &unija);
        Ukloni_dupli(&unija);
	
        printf("Unija: ");
	Ispis_liste(&unija);

	Presjek(&head1, &head2, &presjek);
	if (presjek.next == NULL)
		printf("Presjek: prazan skup");
	else
	{
		printf("Presjek: ");
		Ispis_liste(&presjek);
	}


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

int Sortirani_unos(Pok head, Pok novi_cvor)
{
	Pok temp;

	if (head->next == NULL || head->next->broj >= novi_cvor->broj)
	{
		novi_cvor->next = head->next;
		head->next = novi_cvor;
	}

	else {

		temp = head->next;
		while (temp->next != NULL && temp->next->broj < novi_cvor->broj)
		{
			temp = temp->next;
		}
		novi_cvor->next = temp->next;
		temp->next = novi_cvor;
	}

     return 0;
}

int Ispis_liste(Pok head)
{

	head = head->next;

	while (head != NULL)
	{
		printf("%d ", head->broj);
		head = head->next;
	}
	printf("\n");

	return 0;
}
//2
int Unija(Pok head1, Pok head2, Pok head)
{
	Pok temp1 = head1->next;
	Pok temp2 = head2->next;
	Pok novi_cvor = NULL;

	while (temp1 != NULL)
	{
		novi_cvor = (Pok)malloc(sizeof(struct Cvor));
		novi_cvor->broj = temp1->broj;
		novi_cvor->next = head->next;
		head->next = novi_cvor;
		temp1 = temp1->next;
	}
	head = head->next;
	while (temp2 != NULL)
	{
		while (head != NULL)
		{
			if (head->broj == temp2->broj)
				head = head->next; 
			else
			{
				novi_cvor = (Pok)malloc(sizeof(struct Cvor));
				novi_cvor->broj = temp2->broj;
				novi_cvor->next = head->next;
				head->next = novi_cvor;
			}
		}
		temp2 = temp2->next;
	}

	return 0;
}
Pok Sort_Unija(Pok head1, Pok head2, Pok head)
{
	if (head1->next == NULL)
		head = head2;
	else if (head2->next == NULL)
		head = head1;

	head1 = head1->next;
	head2 = head2->next;

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

int Ukloni_dupli(Pok head)
{

	Pok temp = head->next;

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
	return 0;
}
int Presjek(Pok head1, Pok head2, Pok head)
{
	Pok temp = NULL;
	head1 = head1->next;
	head2 = head2->next;

	while (head1 != NULL && head2 != NULL)
	{
		if (head1->broj > head2->broj)
			head1 = head1->next;
		else if (head2->broj > head1->broj)
			head2 = head2->next;
		else
		{
			temp = (Pok)malloc(sizeof(struct Cvor));
			temp->broj = head1->broj;
			while (head->next != NULL)
			{
				head = head->next;
			}
			temp->next = head->next;
			head->next = temp;

			head1 = head1->next;
			head2 = head2->next;

		}
	}
	return 0;
}
//alt
int Presjek(Pok head1, Pok head2, Pok head)
{
	Pok novi_cvor = NULL;
	Pok temp1 = head1->next;
	Pok temp2 = head2->next;
	

	while (temp1 != NULL)
	{
		while (temp2 != NULL)
		{
			if (temp2->broj == temp1->broj)
			{
			    novi_cvor = (Pok)malloc(sizeof(struct Cvor));
				novi_cvor->broj = temp1->broj;
				while (head->next != NULL)
				{
					head = head->next;
				}
					novi_cvor->next = head->next;
					head->next = novi_cvor;
			}
			temp2 = temp2->next;
		}
		temp1 = temp1->next;
	}

	return 0;
}

