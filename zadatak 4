#define _CRT_SECURE_NO_WARNINGS
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>

typedef struct Polinom* Pok;

 struct Polinom {
	 int koef;
	 int exp;
	 Pok next;
};

 Pok stvori_polinom( );
 int ispis_pol(Pok);
 Pok zbroj_pol(Pok, Pok, Pok);

 int main()
 {
	 Pok pol1 = NULL;
	 Pok pol2 = NULL;
	 Pok pol_zbr = NULL;

     printf("Dobrodosli u program za zbrajanje i mnozenje polinoma!!!\n");
	 printf("Unos polinoma: \n");

	 printf("Koliko clanova prvog polinoma: ");
	 pol1 = stvori_polinom ();
	 ispis_pol(pol1);
	 
	 printf("\nKoliko clanova drugog polinoma: ");
	 pol2 = stvori_polinom();
	 ispis_pol(pol2);
	 
	 printf("\nZbroj polinoma : \n");

	 pol_zbr = zbroj_pol(pol1, pol2, pol_zbr);
	 ispis_pol(pol_zbr);



	 return 0;

 }

 Pok stvori_polinom()
 {
	 int n = 0, i = 0;
	 int k = 0, e = 0;
	
	 Pok head = NULL; 
	 Pok temp = NULL; 

	 
	 scanf("%d", &n);

	 for (i = 0; i < n; i++)
	 {
		 printf("Koef %d. clana : ", i + 1);
		 scanf("%d", &k);
		 printf("Exp %d. clana : ", i + 1);
		 scanf("%d", &e);

		 if (head == NULL)
		 {
			 temp = (Pok)malloc(sizeof(struct Polinom));
			 temp->koef = k;
			 temp->exp = e;
			 head = temp;
			 temp->next = (Pok)malloc(sizeof(struct Polinom));
			 temp = temp->next;
			 temp->next = NULL;
		 }
		 else
		 { 
			 temp->koef = k;
			 temp->exp = e;

			 temp ->next = (Pok)malloc(sizeof(struct Polinom));
			
			 temp = temp->next;
			 temp->next = NULL;
		 }
     }

			
	 return head;
}

 int ispis_pol(Pok head)
 {
	 while (head->next != NULL)
	 {
		 printf("%dx^%d", head->koef, head->exp);
		 head = head->next;
		 if (head->next != NULL)
			 printf(" + ");
	 }

	 return 0;
 }

  Pok zbroj_pol(Pok P1, Pok P2, Pok P)
 {
	 P = (Pok)malloc(sizeof(struct Polinom));
	 Pok temp = (Pok)malloc(sizeof(struct Polinom));

	 while (P1 != NULL && P2 != NULL)
	 {
		 if (P1->exp > P2->exp)
		 {
			 P->exp = P1->exp;
			 P->koef = P1->koef;
			 P1 = P1->next;
		 }


		 else if (P2->exp > P1->exp)
		 {
			 P->exp = P2->exp;
			 P->koef = P2->koef;
			 P2 = P2->next;
		 }

		 else
		 {
			 P->exp = P1->exp;
			 P->koef = P1->koef + P2->koef;
			 P1 = P1->next;
			 P2 = P2->next;
		 }
		 P->next = (Pok)malloc(sizeof(struct Polinom));
		 P = P->next;
		 P->next = NULL;
		
		 while (P1->next != NULL || P2->next != NULL)
		 {
			 if (P1->next)
			 {
				 P->exp = P1->exp;
				 P->koef = P1->koef;
				 P1 = P1->next;
			 }
			 if (P2->next)
			 {
				 P->exp = P2->exp;
				 P->koef = P2->koef;
				 P2 = P2->next;
			 }
			 P->next = (Pok)malloc(sizeof(struct Polinom));
			 P = P->next;
			 P->next = NULL;
		 }
	 }

	 return P;
 }

/* Pok zbroj_pol(Pok P1, Pok P2, Pok P)
 {
	 Pok max_koef = NULL;
	 P = (Pok)malloc(sizeof(struct Polinom));
	 while (P1 != NULL && P2 != NULL)
	 {
		 max_koef = P1->next;
		 while (P1->next != NULL)

			 if (P1->next->koef > max_koef->koef)
				 max_koef = P1->next;

*/
