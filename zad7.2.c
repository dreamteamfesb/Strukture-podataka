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
 int rez(Pok);

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
	 int br = 0;
	 FILE* file = NULL;
	 char* spremnik = (char*)malloc(MAX * sizeof(char));
	 int br1, br2 = 0;
	 int rezultat = 0;
	 int num = 0;

	 file = fopen(naziv_d, "r");

	 if (file == 0)
	 {
		 printf("Datoteka nije otvorena!");
		 exit(1);
	 }
	 else
		 printf("Datoteka uspjesno otvorena!\n");

	 while (fgets(spremnik, MAX, file) != NULL)
	 {
		 printf("%s", spremnik);
	 }

	 while (*spremnik != '\0')
	 {
		 if (sscanf(spremnik, "%d %n", &br, &num) == 1)
		 {
			 push(br, Stog);
			 spremnik += num;
		 }
		 else if (sscanf(spremnik, "%d %n", &br, &num) == 0)
		 {
			 br1 = pop(Stog);
			 br2 = pop(Stog);

			 spremnik++;

			 switch (*spremnik)
			 {
			 case '+':
				 push(br1 + br2, Stog);
				 break;
			 case '-':
				 push(br1 - br2, Stog);
				 break;
			 case '*':
				 push(br1*br2, Stog);
				 break;
			 case '/':
				 if (br2 != 0)
					 push(br1 / br2, Stog);
				 break;
			 default:
				 printf("  ERROR! \n");
				 return 1;
				 break;
			 }
			 spremnik++;
		 }
	 }
	 
	 rezultat = rez(Stog);
	 return rezultat;
 }
 
   int push(int br, Pok head)
 {
	 int number = 0;
	 Pok cvor = (Pok)malloc(sizeof(struct Cvor));

	 cvor->broj = br;
	 cvor->next = head->next;
	 head->next = cvor;

	 return 0;
 }
 
 
 int pop(Pok head_s)
 {
	     int numer = 0;
		 Pok temp = NULL;

		 if (head_s->next == NULL)
		 {
			 printf("Stog je vec prazan!\n");
		 }
		 else
		 {

			 temp = head_s->next;
			 numer = temp->broj;
			 head_s->next = temp->next;
			 free(temp);
		 }

		 return numer;
	 }
 int rez(Pok head)
 {
	 int rez = 0;
	 Pok temp = head->next;
	 rez = temp->broj;
	 return rez;
 }
