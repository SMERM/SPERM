#include <stdio.h>
int main()
{
  int a[3]= {2};   /*il risultato degli altri elementi è indefinito*/
  printf("a[0] = %d\na[1] = %d\na[2] = %d\n", a[0] , a[1] , a[2]);
  return 0;
}
