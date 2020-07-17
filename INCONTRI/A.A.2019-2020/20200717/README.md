# Incontro del 17 luglio 2020 (effettuato in remoto)

<!- ## [Video della lezione]() ->

## Argomenti

* analisi delle funzioni di `stdlib`:
  * analisi delle funzioni presenti in `stdlib`
    * funzioni presenti nella libreria `stdlib`
    * realizzazione (parziale) della funzione `atof`: `simple_atof`

## [Codice `C`: `simple_atof.c`](./simple_atof.c)

```C
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TRUE 1
#define FALSE 0

double my_pow_10(int x)
{
  double result =  1;
  while(x)
  {
    if(x>0)
    {
      result *= 10;
      --x;
    }
    else
    {
      result /= 10;
      ++x;
    }
  }
  return result;
}

int simple_is_digit(char c)
{
  int result = FALSE;
  if(c >= '0' && c<= '9')
    result = TRUE;
  return result;
}

int simple_is_exp(char c)
{
  int result = FALSE;
  if(c == 'e' || c == 'E')
    result = TRUE;
  return result;
}

int simple_is_plus_or_minus(char c)
{
  int result = FALSE;
  if(c == '+' || c == '-')
    result = TRUE;
  return result;
}

int not_eol(char c)
{
  int result = FALSE;
  if(c != '\0')
    result = TRUE;
  return result;
}
typedef struct number
{
  int dot;
  int pow;
  int sign;
  double result;
  void (*handler)(const char,struct number *);
} Number;


void manage_mantissa(const char c, Number*n)
{
  double x = c-'0';
  if(n->dot == TRUE)
  {
    x *= my_pow_10(n->pow);
    n->result += x;
    n->pow -=1;
  }
  else
  {
    n->result *= 10;
    n->result += x;
  }
}

void manage_exp(const char c, Number*n)
{
  /*da fare(a casa?forse)*/
}

double simple_atof(const char*str)
{
  Number n= {FALSE,-1,1,0.0,manage_mantissa};
  const char * p = str;
  while(not_eol(*p))
  {
    while (not_eol(*p) && (*p == ' ' || *p == '\t' || *p == '\n'))
      ++p;
    if(simple_is_plus_or_minus(*p))
      n.sign = *p == '-' ? -1 : 1;
    else if(simple_is_digit(*p))
      (*n.handler)(*p , &n);
    else if(*p == '.' && n.dot == FALSE)
      n.dot = TRUE;
    else if(simple_is_exp(*p))
    {
      n.handler=manage_exp;
      n.sign=1;
      n.dot=FALSE;
    }
    else
      break;
    ++p;

  }
  return n.result;
}

int main () {
   double val;
   char str[20];

   strcpy(str, "98993489");
   val = simple_atof(str);
   printf("String value = %s, Float value = %f\n", str, val);

   strcpy(str, "3.1459e-4");
   val = simple_atof(str);
   printf("String value = %s, Float value = %12.10f\n", str, val);

   strcpy(str, "3.1459E-4");
   val = simple_atof(str);
   printf("String value = %s, Float value = %12.10f\n", str, val);

   strcpy(str, " \t\n3.1459");
   val = simple_atof(str);
   printf("String value = %s, Float value = %f\n", str, val);

   strcpy(str, "3ciao.34");
   val = simple_atof(str);
   printf("String value = %s, Float value = %f\n", str, val);

   strcpy(str, "3.1459eciao");
   val = simple_atof(str);
   printf("String value = %s, Float value = %f\n", str, val);

   strcpy(str, " \t");
   val = simple_atof(str);
   printf("String value = %s, Float value = %f\n", str, val);


   strcpy(str, "sbagliato");
   val = simple_atof(str);
   printf("String value = %s, Float value = %f\n", str, val);

   return(0);
}
```

```sh
nicb-p302u:.../20200717$ ./simple_atof
String value = 98993489, Float value = 98993489.000000
String value = 3.1459e-4, Float value = 3.1459000000
String value = 3.1459E-4, Float value = 3.1459000000
String value =
3.1459, Float value = 3.145900
String value = 3ciao.34, Float value = 3.000000
String value = 3.1459eciao, Float value = 3.145900
String value =  	, Float value = 0.000000
String value = sbagliato, Float value = 0.000000
```

La funzione è ancora realizzata parzialmente, perché in essa dev'essere ancora
scritta la funzione `manage_exp`, e quindi la notazione esponenziale non è
ancora gestita.

## Compiti per casa

* realizzare la funzione `manage_exp` per `simple_atof.c`
