# Incontro del 12 giugno 2020 (effettuato in remoto)

## [Video della lezione](https://youtu.be/fbU-9ON6D3s)

## Argomenti

* analisi delle funzioni di `stdlib`:
  * analisi delle funzioni presenti in `stdlib`
    * tipi di variabili presenti in `stdlib` (4)
    * macro presenti nella libreria `stdlib`
    * funzioni presenti nella libreria `stdlib`:
      * implementazione della funzione `simple_atof()` (da completare a casa)

## Codice `C`

### [macro - 1mo programma](./macro.c)

```C
#include <stdio.h>
#define GFMG 23

int main()
{
  printf("%d\n", GFMG);
  return GFMG;
}
```

```sh
$ cc -o macro macro.c
$ ./macro
23
```

### [macro - 2do programma](./macro2.c)

```C
#include <stdio.h>
#define COMPLICATA(a,b) b,a,b,a,b

int main()
{
  printf("%s %d %s\n", COMPLICATA(23,"CIAO"));
  return 0;
}
```

```sh
$ cc -o macro2 macro2.c
$ ./macro2
CIAO 23 CIAO
```

### [stdlib - programma 0](./stdlib0.c)

```C
#include <stdio.h>
#include <limits.h>
#include <stdlib.h>


int main()
{
  int f=rand();
  printf("f: %d, NULL: %p, EXIT_FAILURE; %d, EXIT_SUCCESS: %d, RAND_MAX: 0x%x, MB_CUR_MAX: %ld, MB_LEN_MAX: %ld\n",f,NULL,EXIT_FAILURE,EXIT_SUCCESS,RAND_MAX,MB_CUR_MAX,MB_LEN_MAX);
  return EXIT_SUCCESS;
}
```

```sh
$ cc -o stdlib0 stdlib0.c
$ ./stdlib0
f: 1804289383, NULL: (nil), EXIT_FAILURE; 1, EXIT_SUCCESS: 0, RAND_MAX: 0x7fffffff, MB_CUR_MAX: 1, MB_LEN_MAX: 16
```

(i risultati possono variare da macchina a macchina, da sistema operativo a
sistema operativo, e da compilatore a compilatore).

### [la funzione `atof` - main di test](./real_atof.c)

```C
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main () {
   float val;
   char str[20];

   strcpy(str, "98993489");
   val = atof(str);
   printf("String value = %s, Float value = %f\n", str, val);

   strcpy(str, "3.1459e-4");
   val = atof(str);
   printf("String value = %s, Float value = %12.10f\n", str, val);

   strcpy(str, "3.1459E-4");
   val = atof(str);
   printf("String value = %s, Float value = %12.10f\n", str, val);

   strcpy(str, " \t\n3.1459");
   val = atof(str);
   printf("String value = %s, Float value = %f\n", str, val);

   strcpy(str, "3.1459eciao");
   val = atof(str);
   printf("String value = %s, Float value = %f\n", str, val);



   strcpy(str, "sbagliato");
   val = atof(str);
   printf("String value = %s, Float value = %f\n", str, val);

   return(0);
}
```

```sh
$ cc -o real_atof real_atof.c
$ ./real_atof
String value = 98993489, Float value = 98993488.000000
String value = 3.1459e-4, Float value = 0.0003145900
String value = 3.1459E-4, Float value = 0.0003145900
String value =
3.1459, Float value = 3.145900
String value = 3.1459eciao, Float value = 3.145900
String value = sbagliato, Float value = 0.000000
```

### [la funzione `simple_atof` - template da completare a casa](./simple_atof.c)

```C
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

double simple_atof(const char*str)
{
  double result=0.0;
  /*da fare a casa*/
  return result;
}

int main () {
   float val;
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

   strcpy(str, "sbagliato");
   val = simple_atof(str);
   printf("String value = %s, Float value = %f\n", str, val);

   return(0);
}
```

La funzione `simple_atof()` è da **completare a casa**.

## Compiti per casa

* completamento della funzione `simple_atof()`
