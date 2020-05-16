#include <stdio.h>



int main(int argc,const char *argv[])
{
  int c=1;
  if (argc <2)
  {
    printf("%s: utilizzo\n%s nome...\n",argv[0],argv[0]);
    return -1;
  }
  printf("ciao");
  while(c<argc)
  {
    printf(" %s", argv[c]);
    ++c;
  }
  printf("!\n");
  return 0;
}
