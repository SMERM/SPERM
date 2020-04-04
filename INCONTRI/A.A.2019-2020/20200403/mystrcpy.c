#include <stdio.h>
#include <string.h>

void mystrcpy(char dest[] , char src[]);

int main()
{
  int size2 = 4096;
  char string1[] = "ma vedi mpo'";
  char string2[size2];

  mystrcpy(string2 , string1);
  printf("str 2 is %s\n", string2);
}

void mystrcpy(char dest[] , char src[])
{

  size_t i =0;
  while ((dest[i] = src[i]) != '\0')
    ++i;
}
