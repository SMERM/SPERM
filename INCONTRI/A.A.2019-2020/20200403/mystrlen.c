#include <stdio.h>
#include <string.h>

int mystrlen( char string[]);

int main ()
{
  char string[]= "you did man ";
  int realsize = 0;

  printf("%s\n", string);

  realsize = mystrlen(string);
  printf("%d\n", realsize);
}


int mystrlen(char string[])
{

  int n = 0;
  while ( string[++n] != '\0');
  return n;
}
