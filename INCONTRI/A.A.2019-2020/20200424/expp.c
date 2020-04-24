#include <stdio.h>

int main()
{
        /* dichiarazione */
        int a = 23;      /* variabile */
        int *p = &a;     /* puntatore a una variabile */
        int **pp = &p;   /* puntatore a un puntatore a una variabile */

        /* uso */
        printf("a: %d\n", a);
        printf("p: %p, *p: %d\n", p, *p);
        printf("pp: %p, *pp: %p, **pp: %d\n", pp, *pp, **pp);

        /* KA-BOOM */
        pp-=1000;
        printf("pp: %p, *pp: %p, **pp: %d\n", pp, *pp, **pp);
}
