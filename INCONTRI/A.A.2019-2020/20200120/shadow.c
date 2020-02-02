#include <stdio.h>


int main()
{
	int local,visible;
	local=33;
	visible=local+1;
	printf("%d %d\n",local,visible);
	{
		int local;
		local=42;
		printf("%d %d\n",local,visible);
	}
	printf("%d %d\n",local,visible);
}
