#include <stdio.h>

void n()
{
	static int s=0;
	printf("%d\n",s++); /* post-incremento */
	printf("%d\n",++s); /* pre-incremento  */
	
}
void main()
{
	n();
	n();
	n();
}
