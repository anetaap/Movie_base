#include <stdio.h>
#include <string.h>
#include <stdlib.h>

extern int main();

struct movies
{
      int ID;
      char title[20];
      char review[50];
      float rate;
} film[70];

int add()
{
    FILE *fp;
    fp=fopen("movies.txt","a+");
    int i;
    char t,n;
    fseek(fp,0,SEEK_END);
    i=ftell(fp)/sizeof(film);
    fseek(fp,0,SEEK_END);
    do
    {
      printf("Podaj tytuł filmu:\n");
      scanf("%s", *&film[i].title);
      printf("\nJak ocenisz film w skali od 1 do 10?:\n");
      scanf("%f", &film[i].rate);
      printf("\nDodaj komentarz:\n");
      scanf("%s", *&film[i].review);
      film[i].ID=i+1;
      fwrite(&film[i],sizeof(film),1,fp);
      i++;
      int rozmiar=i;
      printf("\nCzy chcesz wpisac do bazy jeszcze jeden rekord? (t=tak)\n");
      scanf("%s", &t);
      }while (t=='t');

    fclose(fp);
    printf("\nAby przejsc do menu wcisnij 1, aby wyjść wciśnij dowolny klawisz\n");

    scanf("%s", &n);
    fflush(stdin);

    switch(n)
         {
         case '1' : main();
         break;
         default : exit(1);
         break;
         }
return 0;
} 