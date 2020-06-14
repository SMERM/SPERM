#include <stdio.h>
#include <limits.h>
#include <stdlib.h>


int main()
{
  int f=rand();
  printf("f: %d, NULL: %p, EXIT_FAILURE; %d, EXIT_SUCCESS: %d, RAND_MAX: 0x%x, MB_CUR_MAX: %ld, MB_LEN_MAX: %ld\n",f,NULL,EXIT_FAILURE,EXIT_SUCCESS,RAND_MAX,MB_CUR_MAX,MB_LEN_MAX);
  return EXIT_SUCCESS;
}
