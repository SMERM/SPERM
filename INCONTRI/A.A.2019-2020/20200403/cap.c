#include <stdio.h>

int main()
{
  char string[] = "bella flate'";
  char *p = string;
  char s;
  while((s = *p++) != '\0')
    printf("indirizzo: %p , carattere %c , stringa : %s\n", p-1 , s, string);
}
