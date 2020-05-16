#include <stdio.h>
#include <math.h>
union A
{
  int x;
  char y;
  double z;
};

int main()
{
  union A a;
  union A *p=&a;
  a.z=M_E;
  printf("%p visto come double: %20.18f\n",p,p->z);
  printf("%p visto come char: '%c' (%d)\n",p,p->y,p->y);
  printf("%p visto come int: %d\n",p,p->x);
}
