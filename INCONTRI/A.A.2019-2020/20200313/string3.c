#include <stdio.h> 

int main()
{
	char s[6]={71,0,71,65,89,0};
	 
	printf ("%s %s\n",s,&s[2]);
	
	return 0;
}
