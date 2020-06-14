#include <stdio.h>
#define COMPLICATA(a,b) b,a,b,a,b

int main()
{
  printf("%s %d %s\n", COMPLICATA(23,"CIAO"));
  return 0;
}
