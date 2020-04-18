#include <stdio.h>    /* PUNTATORI DI PUNTATORI DI ARRAY */

int main()
{
  int a[] = {0 , 1 , 2 , 3 , 4};
  int *p[] = {a , &a[1] , &a[2] , &a[3] , &a[4]}; /*array di puntatori*/
  int **pp =  p;

  /*ESERCIZIO: provare a incrementare e decrementare a e dare una spiegzione*/
}
