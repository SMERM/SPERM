#include <stdio.h>

int fun(long int a, float b, char c)
{
	printf("char: %c - float: %55.50f - int: %20ld\n",c,b,a);
}
int main()
{
	fun(23,3.14,'a');
	fun(20024,2022.78,'b');
	fun(420000000000000,1.414,'c');
}

