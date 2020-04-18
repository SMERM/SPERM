#include <stdio.h> /*ARITMETICA DEI PUNTATORI*/

struct big
{
  double superbig[1000];
  long megabig[1001];
  char poco[13];
};
                      /*void ptr è un puntatore senza grandezza dichiarata*/
int main()
{
  char small;
  int medium;
  double large;
  struct big huge;
  char *smallp = &small;
  int *mediump = &medium;
  double *largep = &large;
  struct big *hugep = &huge;
  void *smallvp = smallp, *mediumvp = mediump, *largevp = largep, *hugevp = hugep;
  /*CAST = conversione del tipo di puntatore, si moltiplica puntatore per void*   */

  printf("char: %p\tincrement: %p, difference:%d\n",smallp , smallp+1, ((void*)(smallp+1))-smallvp);
  printf("int: %p\tincrement: %p, difference:%d\n",mediump , mediump+1, ((void*)(mediump+1))-mediumvp);
  printf("double: %p\tincrement: %p, difference:%d\n",largep , largep+1, ((void*)(largep+1))-largevp);
  printf("huge: %p\tincrement: %p, difference:%d\n",hugep , hugep+1, ((void*)(hugep+1))-hugevp);

}
