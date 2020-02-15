#include <stdio.h>

int fun(const int a)
{
	int y=a;
	y+=5;
	printf("int: %20d\n",y);
}
int main()
{
	int x=55;
	fun(x);
	printf("fuori dalla funzione: %d\n",x);	
}

