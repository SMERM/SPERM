/*SIZEOF*/
#include <stdio.h>
#include <string.h>

typedef struct
{
  double d;
  char c[8];
}Grosso;

int main()
{
  Grosso array[1000];
  printf("%d %d\n", sizeof(Grosso), sizeof(array));
}
