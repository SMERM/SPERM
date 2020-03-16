#include <stdio.h> 

int main()
{
	char s[5]={'75','75','75','75','75'};
	s[0]= 71;
	s[1]= 65;
	s[2]= 89;
	s[4]= '\0'; 
	printf ("%s\n",s);
	
	return 0;
}
