#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "functions.h"


int main()
{
  char n;
  printf("Witaj w swojej osobistej Bazie filmów!\n");
  printf("Masz do wyboru nastepujace mozliwosci\n");
  printf("[1]Tworzenie nowej bazy\n[2]Dodaj film do istniejącej bazy\n[3]Drukowanie bazy danych\n[4]Wyjście");
  do{
    printf("\nTwoj wybor to?\n");
    char n;
    scanf("%s", &n);
    fflush(stdin);

    switch(n)
         {
         case '1' : create();
         break;
         case '2' : add();
         break;
         case '3' : //view();
         break;
         case '4' : exit(0);
         break;
         default : printf("\nNie ma takiej opcji, wybierz jeszcze raz");
         break;
         }
  }while(n!='1'&&n!='2'&&n!='3'&&n!='4');
  return 0;
}
