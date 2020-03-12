#include <stdio.h>
int varfun (int a , ...)
{
  return a;
}

int main()
{
  varfun (23,46);
  printf("%d\n", varfun (23,47,16));

}
