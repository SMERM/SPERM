#include <stdio.h>

int funzione_a(const int a)
{
	int (*p)(const int) = funzione_a ;
	printf("sono la funzione a e il mio valore e %p\n",p);
	return a;
}

int funzione_b(const int a)
{
	printf("sono la funzione b e il mio valore e %d\n",a);
	return a;
}

int main ()
{
	int (*p)(const int);
	p=funzione_a;
	(*p)(42);
	p=funzione_b;
	(*p)(23);
	
}
