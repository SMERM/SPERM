#include <stdio.h>

static int ss=0;
void f21()
{
	printf("f21: %d\n",ss++);
}
void f22()
{
	printf("f22: %d\n",ss++);
}
