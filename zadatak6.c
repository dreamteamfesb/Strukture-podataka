  
 #define _CRT_SECURE_NO_WARNINGS
 #include <stdio.h>
 #include <stdlib.h>
 #include <time.h>

struct Cvor;
typedef struct Cvor* Pok;
 
struct Cvor {
	int broj;
	Pok next;
};

int odabir(void);
int push(Pok);
int pop_stog(Pok);
int pop_red(Pok);
int ispis(Pok);
int stog(void);
int red(void);

int main()
{
	int izbor = 0;
	
	izbor = odabir();
	
	{
		if (izbor == 1)
		{
			printf("\nStog\n");
			stog();
		}

		else if (izbor == 2)
		{
			printf("\nRed\n");
			red();
		}
		else
			printf("Pogresan unos!");
	
	}
	return 0;
}

int odabir(void)
{
	int a = 0;

	printf("Stog: 1\nRed: 2\n");
	printf("Odabir: ");
	scanf("%d", &a);

	return a;
}
int stog(void)
{

	int izbor = 1, stog = 0;
	struct Cvor head_stog;
	head_stog.next = NULL;
	while (izbor == 1)
	{
			printf("\nPush: 1\nPop: 2\nIspis: 3\nIzlaz: 4\n");
			printf("Odabir : ");
			scanf("%d", &stog);
			if (stog == 1)
				push(&head_stog);
			else if (stog == 2)
				pop_stog(&head_stog);
			else if (stog == 3)
				ispis(&head_stog);
			else if (stog == 4)
				break;
            else
				printf("Netocan unos\n");
		
	}
	return 0;
}
int red(void)
{
	int izbor = 2, red = 0;
    
	struct Cvor head_red;
	head_red.next = NULL;

	while (izbor == 2)
	{
		printf("\nPush: 1\nPop: 2\nIspis: 3\nIzlaz: 4\n");
		printf("Odabir : ");
		scanf("%d", &red);
		if (red == 1)
			push(&head_red);
		else if (red == 2)
			pop_red(&head_red);
		else if (red == 3)
			ispis(&head_red);
		else if (red == 4)
			break;
		else
			printf("Netocan unos\n");
	}

	return 0;
}

int push(Pok head)
{
	int donja = 10, gornja = 100;
	int br = 0;
	Pok cvor = (Pok)malloc(sizeof(struct Cvor));

	srand(time(NULL));
	br = (rand() % (gornja - donja + 1)) + donja;

	cvor->broj = br;
	cvor->next = head->next;
	head->next = cvor;

	return 0;
}
int pop_stog(Pok head_s)
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
int pop_red(Pok head_r)
{
	Pok temp = NULL;
	Pok kraj = NULL;

	if (head_r ->next == NULL)
		printf("Red je vec prazan");
	else
	{
		temp = head_r;
		kraj = head_r->next;

		while (kraj->next != NULL)
		{
			temp = kraj;
			kraj = kraj->next;
		}

		temp->next = kraj->next;
		free(kraj);
	}
	    return 0;
}
int ispis(Pok head)
{
	if (head->next == NULL)
		printf("Lista je prazna !");
	else
	{
		head = head->next;
		printf("Ispis: ");
		while (head != NULL)
		{
			printf("%d ", head->broj);
			head = head->next;
		}
	}
		printf("\n");

		return 0;
}
