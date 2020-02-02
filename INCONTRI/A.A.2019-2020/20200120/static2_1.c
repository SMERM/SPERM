#include <stdio.h>

static int ss=0;
void f11()
{
	printf("f11: %d\n",ss++);
}
void f12()
{
	printf("f12: %d\n",ss++);
}
