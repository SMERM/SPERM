#include <stdio.h>

char *mystrcpy(char *dest , const char *S );

int main()
{
  int size2 = 4096;
  char string1[] = {"ma vedi mpo'"};
  char string2[size2];
  char *o = mystrcpy(string2 , string1);
  puts(o);
  mystrcpy(string2 , string1);
  printf("str 2 is %s\n", string2);
}

char *mystrcpy(char *dest , const char *S) /* il valore di ritrono è char * cioè un puntatore a un carattere*/
{
  char *r = dest;
  while ((*dest++ = *S++) != '\0'); /*prendo il contenuto di s e lo metto in dest , poi incremento entrambi*/
  return r;
}
