#include <stdio.h>

struct A
{
        int i;
        double d;
        char c;
};

int main()
{
        struct A s = { 23, 23e23, 'a' };
        struct A *pA = &s;
        int *pint = &s.i;
        char *pchar = &s.c;
        double *pdouble = &s.d;

        printf("sizeof di A: %d\n", sizeof(s));
        printf("pA: %p\n", pA);
        printf("pint: %p\n", pint);
        printf("pchar: %p\n", pchar);
        printf("pdouble: %p\n", pdouble);
}
