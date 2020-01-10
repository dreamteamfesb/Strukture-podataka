#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

struct CvorStabla;
typedef CvorStabla* Pok;
typedef CvorStabla* Pozicija;

struct CvorStabla {

	int broj;
	Pok lijevo;
	Pok desno;
};

int izbor(void);
Pok novi_element(int, Pok);
Pok stvori_cvor(int);
int ispisi_stablo(Pok);
Pok trazi_el(int, Pok);
Pok brisi_el(int, Pok);
Pok trazi_min(Pok);

int main()
{
	struct CvorStabla root;
	root.lijevo = NULL;
	root.desno = NULL;
	Pok proot = &root;
	int odabir;
	int element;
	Pozicija rez = NULL;

	printf("Element roota: ");
	scanf("%d", &root.broj);

	while (1)
	{
		odabir = izbor();
		switch (odabir)
		{
		case 1:

			printf("Broj: ");
			scanf("%d", &element);
			proot = novi_element(element, proot);
			break;
		case 2:
			ispisi_stablo(proot);
			break;
		case 3:
			printf("Broj: ");
			scanf("%d", &element);
			rez = trazi_el(element, proot);
			break;
		case 4:
			printf("Broj: ");
			scanf("%d", &element);
			brisi_el(element, proot);
			break;
		default:
			printf("Neispravno unesena vrijednost funkcije!\n");

		}
	}

	return 0;
}

int izbor(void)
{
	int odabir = 0;
	printf("Funkcije: \n");
	printf("  1. Unesi novi element\n  2. Ispisi stablo\n  3. Pronadi element\n  4. Brisi element\n");

	scanf("%d", &odabir);

	return odabir;
}

Pok novi_element(int element, Pok proot)
{
	if (proot == NULL)
		return stvori_cvor(element);

	if (element < proot->broj)
		proot->lijevo = novi_element(element, proot->lijevo);
	
	else if (element > proot->broj)
		proot->desno = novi_element(element, proot->desno);

	return proot;
}
Pok stvori_cvor(int br)
{
	Pok temp = (Pok)malloc(sizeof(struct CvorStabla));
	temp->broj = br;
	temp->lijevo = NULL;
	temp->desno = NULL;
    
	return temp;
}
int ispisi_stablo(Pok root)
{
	if(root != NULL)
	{
		printf(" %d\n", root->broj);
		ispisi_stablo(root->lijevo);
		ispisi_stablo(root->desno);
	}

	return 0;
}
Pozicija trazi_el(int broj, Pok root)
{
	if (root == NULL)
	{
		printf("Element ne postoji!\n");
		return NULL;
	}
		if (broj < root->broj)
			return trazi_el(broj, root->lijevo);
		else if (broj > root->broj)
			return trazi_el(broj, root->desno);
		else
			return root;
}
Pok brisi_el(int br, Pok root)
{
	if (root == NULL)
	{
		printf("Nema ga!\n");
		return NULL;
	}
	if (br < root->broj)
	{                                             //ovde samo stavi trazi!;
		root->lijevo = brisi_el(br, root->lijevo);
	}
	else if (br > root->broj)
	{
		root->desno = brisi_el(br, root->desno);
	}
	else
	{
		if (root->lijevo == NULL)
		{
			Pok temp = root->desno;
			free(root);
			return temp;
		}
		else if (root->desno == NULL)
		{
			Pok temp = root->lijevo;
			free(root);
			return temp;
		}
               else
	       {
		Pok temp = NULL;

		temp = trazi_min(root->desno);
		root->broj = temp->broj;
		root->desno = brisi_el(temp->broj, root->desno);
	       }
	}
	

	return root;
}

Pok trazi_min(Pok cvor)
{
	while (cvor->lijevo != NULL)
	{
		cvor = cvor->lijevo;
	}

	return cvor;
}
