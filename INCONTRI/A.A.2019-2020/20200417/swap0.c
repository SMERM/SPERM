#include <stdio.h>   /*ARGOMENTI PASSATI PER VALORE E NON PER RIFERIMENTO*/

void swap(int a, int b)
{
  int tmp = b;
  b = a;
  a = tmp;
}


int main()
{
  int a = 23 , b = 16;
  swap(a,b);
  printf("a: %d, b: %d\n", a, b);
}
