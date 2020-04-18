#include <stdio.h> /*ARITMETICA DEI PUNTATORI*/

struct big
{
  double superbig[1000];
  long megabig[1001];
};

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
  printf("char: %p\tincrement: %p, difference:%d\n",smallp , smallp+1, (smallp+1)-smallp);
  printf("int: %p\tincrement: %p, difference:%d\n",mediump , mediump+1, (mediump+1)-mediump);
  printf("double: %p\tincrement: %p, difference:%d\n",largep , largep+1, (largep+1)-largep);
  printf("huge: %p\tincrement: %p, difference:%d\n",hugep , hugep+1, (hugep+1)-hugep);
}
