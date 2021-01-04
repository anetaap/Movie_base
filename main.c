#include <stdio.h>
#include <string.h>
#include <stdlib.h>


typedef struct movie
{
       char title[50];
       char review[200];
       double rate;
} movie;

int main()
{
    char n;

printf("Witaj w swojej osobistej Bazie filmów!\n");
printf("Masz do wyboru nastepujace mozliwosci\n");
printf("[1] Dodanie filmu do bazy \n[2]Drukowanie bazy danych\n");
do{
printf("\nTwoj wybor to?\n");
int n;
scanf("%d", &n);
fflush(stdin);

    switch(n)
         {
         case 1 : //add();
         break;
         case 2 : //view();
         break;
         default : printf("\n nie ma takiej opcji, wybierz jeszcze raz");
         break;
         }         
  }while(n!='1'&&n!='2'&&n!='3');

}