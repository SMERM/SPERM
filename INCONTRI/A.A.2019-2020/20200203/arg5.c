#include <stdio.h>

int fun(int a)
{
	a=a+5;
	printf("int: %20d\n",a);
}
int main()
{
	int x=55;
	fun(x);
	printf("fuori dalla funzione: %d\n",x);	
}

