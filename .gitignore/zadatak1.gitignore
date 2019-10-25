
 #define _CRT_SECURE_NO_WARNINGS
 
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
 #include <ctype.h> 
 
 #define D 25
 #define duzina 1024

typedef struct {
	char ime[D];
	char prezime[D];
	int br_bod;
} _student;

 int brojac(char *);
 int unos(char *, _student*, int);
 int ispis(_student *, int, int);

int main(void)
{

	_student *p = NULL;
	char *fp = NULL;
	int n = 0, max = 0;

	fp = (char*)malloc(duzina * sizeof(char));

	if (fp == NULL)
		return -1;

	memset(fp, '\0', duzina);

	printf("Datoteka : ");
	scanf("%s", fp);

     if (strrchr(fp, '.') == NULL)
		strcat(fp, ".txt");

	n = brojac(fp);

	if (n > 0)
	{
		p = (_student*)malloc(n * sizeof(_student));

		if (p == NULL)
			return -1;

		max = unos(fp, p, n);
	    ispis(p, n, max);

	}

	  else
	{
		printf("Datoteka prazna!\n");
	}
	return 0;

}

   int brojac(char *ime)
   {
	   FILE *file = NULL;
	   int n = 0;
	   char line[duzina] = { 0 };

	   file = fopen(ime, "r");
	   if (!file)
	   {
		   printf("Datoteka nije otvorena!\n");
		   return -1;
	   }

	   while (!feof(file))
	   {
		   fgets(line, duzina, file);
		   if (strlen(line) == 0)
			   continue;
		     n++;
        }

	   fclose(file);
	   return n;

   }

   int unos(char* ime, _student *p, int n)
   {
	   int i = 0;
	   int max_bod = 0;
	   FILE *f = NULL;
	   f = fopen(ime, "r");

	   for (i = 0; i < n; i++)
	   {
		   fscanf(f, "%s %s %d", p[i].ime, p[i].prezime, &p[i].br_bod);

			   if (p[i].br_bod > max_bod)

				   max_bod = p[i].br_bod;

	   }

	   fclose(f);
	   return max_bod;

   }

   int ispis(_student *p, int n, int max)
   {
	   int i = 0;

	   printf("\t\tIme\t\tPrezime\t\tBodovi\t\tRelativni_bod\n\n");

	   for (i = 0; i < n; i++)
	   {
		   printf("\t%15s \t%15s \t%d \t%.2f\n", p[i].ime, p[i].prezime, p[i].br_bod, ((float)p[i].br_bod / max) * 100);
	   }

	   return 0;
   }



















   
