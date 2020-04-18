#include <stdio.h>    /* PUNTATORI DI PUNTATORI */

int main()
{
  int a = 23;
  int *p = &a;
  int **pp =  &p;
  int ***ppp = &pp;
  printf("p:%p\t*p:%d\npp:%p\t*pp:%p\t**pp:%d\nppp:%p\t*ppp:%p\t**ppp:%p\t***ppp:%d\n", p ,*p , pp ,*pp , **pp , ppp , *ppp , **ppp , ***ppp);
}
