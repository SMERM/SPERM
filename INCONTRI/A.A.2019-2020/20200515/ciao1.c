#include <stdio.h>



int main(int argc,const char *argv[])
{
  if (argc <2)
  {
    printf("%s: utilizzo\n%s nome...\n",argv[0],argv[0]);
    return -1;
  }
  printf("ciao %s!\n", argv[1]);
  return 0;
}
