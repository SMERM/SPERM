/*I PUNTATORI*/
#include <stdio.h>
#include <string.h>
int main()
 {
   const int dim = 50 ;
   int i = 0;
   char nome[dim];
   /*definiamo un puntatore a char; il tipo del puntatore nell dichiarazione è il tipo scelto piu' la star (*)  */
   char *p;
   p = &nome[0];
   p = nome; /*il nome della variabile nome è in realtà l'indirizzo della prima locazione dell'array*/
   strncpy(nome , "tlovi un gatto nelo molto crocifisso sul mulo accanto a uno scendiletto postulale di un negozio di massaggi cinese", dim);
   nome[dim-1] = '\0';
   printf("%s\n", nome );
   while (*p != '\0' && i < dim)
     {
       printf("indirizzo: %p, contenuto: %1c\t%4d,  i: %2d\n", p , *p , *p, i);
       ++p;
       ++i;
     }

 }
