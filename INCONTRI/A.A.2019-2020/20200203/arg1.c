#include <stdio.h>

int fun(int a, float b, char c)
{
	printf("char: %c - float: %f - int: %d\n",c,b,a);
}
int main()
{
	fun(23,3.14,'a');
	fun(24,2.78,'b');
	fun(42,1.414,'c');
}

