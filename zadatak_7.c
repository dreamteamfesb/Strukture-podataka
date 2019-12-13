#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX 50

struct Cvor;
typedef struct Cvor* Pok;

 struct Cvor {

	int broj;
	Pok next;
};

 char* ime_datoteke(void);
 int postfix(char* , Pok);
 int push(int, Pok);
 int pop(Pok);
 int trazi(Pok, int&, int&);

 int main()
 {
	 struct Cvor Stog;
	 Stog.next = NULL;
	 int rez = 0;

	 char* dat = NULL;
	 dat = ime_datoteke( );
	 rez = postfix(dat, &Stog);

	 printf("Rezultat : %d", rez);
 
	 return 0;
 }

 char* ime_datoteke(void)
 {
	 char* ime = NULL;

	 ime = (char*)malloc(MAX * sizeof(char));

	 printf("Unesite ime datoteke: ");
	 scanf("%s", ime);

	 if (strrchr(ime, '.') == NULL)
		 strcat(ime, ".txt");

	 return ime;

 }

 int postfix(char* naziv_d, Pok Stog)
 {
	 int i = 0;
	 FILE* file = NULL;
	 char spremnik[MAX];
	 int duljina = 0;
	 int br1, br2 = 0;
	 int rezultat = 0;

	 file = fopen(naziv_d, "r");
	 
	 if (file == 0)
		 printf("Datoteka nije otvorena!");
	 exit(1);


	 while (!feof(file))
	 {
		 fscanf(file, "%s", spremnik);
	 }

	 duljina = strlen(spremnik);

	 while (i < duljina)
	 {
		 if (spremnik[i]>=1 && (spremnik[i] <= 9))
		 {
			 push(spremnik[i], Stog);
		 }
		 else
		 {
			 switch (spremnik[i])
			 {
			 case '+': 
				 trazi(Stog, br1, br2);
				 pop(Stog); pop(Stog);
				 push(br1 + br2, Stog);
				 break;
			 case '*':
				 trazi(Stog, br1, br2);
				 pop(Stog); pop(Stog);
				 push(br1*br2, Stog);
				 break;
			 case'-':
				 trazi(Stog, br1, br2);
				 pop(Stog); pop(Stog);
				 push(br1 - br2, Stog);
				 break;
			 case'/':
				 trazi(Stog, br1, br2);
				 pop(Stog); pop(Stog);
				 push(br1 / br2, Stog);
			 }
		 }
		 
		 i++;
	 }

	 fclose(file);

	 rezultat = Stog->next->broj;
	 return rezultat;
	 
 }

 int push(int br, Pok head)
 {
	 Pok cvor = (Pok)malloc(sizeof(struct Cvor));

	 cvor->broj = br;
	 cvor->next = head->next;
	 head->next = cvor;

	 return 0;
 }
 
 
 int pop(Pok head_s)
	 {
		 Pok temp = NULL;

		 if (head_s->next == NULL)
		 {
			 printf("Stog je vec prazan!\n");
		 }
		 else
		 {

			 temp = head_s->next;
			 head_s->next = temp->next;
			 free(temp);
		 }

		 return 0;
	 }
 int trazi(Pok head, int & br1, int & br2)
 {
	 Pok temp = head->next;
	 Pok prev = head;
	
	 if (head->next = NULL)
		 printf("Lista je prazna");
	 else {
		 while (temp->next != NULL)
		 {
			 prev = temp;
			 temp = temp->next;
		 }
		 if (prev == head)
			 printf("Lista ima samo jedan element");

		 br1 = prev->broj;
		 br2 = temp->broj;
	 }
	 return 0;
 }
