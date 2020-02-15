#include <stdio.h>

int fun(int a, float b, char c)
{
	printf("char: %c - float: %f - int: %d\n",c,b,a);
}
int main()
{
	fun(23.333,3.14,'a');
	fun(24.444,2.78,'b');
	fun(42.222,1.414,'c');
}

