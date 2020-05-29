# Incontro del 29 maggio 2020 (effettuato in remoto)

## [Video della lezione](https://youtu.be/bTQzR85lHrw)

## Correzione dell'esercizio per casa

* completare la funzione `simple_printf`

## Codice `C`

```C
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>

#define MAX_CHARS (8192)

int count_arg(const char *format)
{
  int result = 0 ;
  const char *p = format;
  while (*p != '\0')
  {
    if (*p == '%')
      result += 1;
    ++p;
  }
  return result;
}

/*
 * implementiamo una versione plausibile di itoa(), considerando che
 * tale funzione non e` standard e non esiste in alcune librerie C che
 * aderiscono allo standard POSIX
 */
char *my_itoa(int n, char *buf)
{
  snprintf(buf, MAX_CHARS, "%d", n);
  return buf;
}

void scrivi_intero(char **o, int number)
{
  char buff[MAX_CHARS];
  char *b;
  b = my_itoa(number, buff);
  while (*b != '\0')
  {
    **o = *b;
    ++(*o);
    ++b;
  }

}

void simple_printf(const char *format, ...)    /*modo per dichiarare argomenti variabili*/
{
  char output[MAX_CHARS];
  va_list l;
  const char  *p = format;
  char *o = output;
  va_start(l, format);
  while (*p != '\0')
  {
    if(*p == '%' && *(p+1) == 'd')
    {
      int number = va_arg(l,int);
      scrivi_intero(&o,number);
      p+=2; /*abbiamo sia per cento che d quindi DOBBIAMO andare avanti di due*/
    }
    else
    {
      *o = *p ;
      ++o;
      ++p;
    }

  }
  va_end(l);
  printf("%s",output);
}

int main()
{
  const char * format = "test %d %d %d\n";
  printf("%d\n",count_arg(format) );
  simple_printf(format, 23, 34567809, -546);
}
```

```sh
$ cc -o simpleprintf simpleprintf.c
$ ./simpleprintf
3
test 23 34567809 -546
```

## Compiti per casa

* aggiungere a `simple_printf` la possibilità di interpolare anche
  numeri a virgola mobile (`%f`), singoli caratteri (`%c`) e stringhe (`%s`).
