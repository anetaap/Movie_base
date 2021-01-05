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

int view()
{
    FILE *fp;
    fp=fopen("movies.txt","r+");
    int y,j,n,i,d,g,rozmiar;
    char z;
    fseek(fp,0,SEEK_END); 
    rozmiar=ftell(fp)/sizeof(film);
    fseek(fp,0,0);
    d=0;
    g=1;
    for(int h=0;h<rozmiar;h++)
    {
      system("cls");
      fread(&film,sizeof(film),1,fp); 
      for(j=d;j<g;j++)
      {
        printf("Opis %d filmu:",j+1); 
        for (n=0;n<1;n++)
        {
          printf("\nNumer filmu:%d",film[n].ID);
          printf("\nTytuł filmu:%s",film[n].title);
          printf("\nOcena filmu:%.1f/10",film[n].rate);
          printf("\nKomentarz do filmu:%s",film[n].review);
        }
      } 
  printf("\n1-Home 2-End 3-Page Up 4-Page Down 5-Powrót do menu\n");
 do{
    scanf("%s", &z);
    y=z;                                  
    switch(y)
    {
         case '1' :
         fseek(fp,0,0);
         d=0;
         g=1;
         break;
         case '2' :
         fseek(fp,-1*sizeof(film),2);
         d=rozmiar-1;
         g=rozmiar;
         break;
         case '3' : 
         fseek(fp,(h+1)*sizeof(film),0);
         if(g>rozmiar-2&&g<rozmiar)
         {
         d=rozmiar-1;
         g=rozmiar;
         }
         else{
         d++;
         g++;
         }
         break;
         case '4' : 
         fseek(fp,-(h+1)*sizeof(film),2);
         if(d<1)
         {
         d=0;
         g=1;
         }
         else
         {
         d--;
         g--;
         }
         break;
         case '5' : main();
         break;
         default : printf("\nnie ma takiej opcji, wybierz jeszcze raz");
         break;
         }  
         }while(y!=1&&y!=2&&y!=3&&y!=4&&y!=5);        
}
  fclose(fp);
  return 0;
}