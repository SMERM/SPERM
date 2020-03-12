# Incontro del 24 febbraio 2020

## Argomenti

* Backtracking sulla sintassi `C` prima di re-analizzare il codice `osc` già prodotto:
  * argomenti
    * introduzione agli argomenti variabili (senza spiegazione)
  * *arrays*

## Lavagna

![whiteboard 1](./SPERM_2020-02-24_16.13.29_1.jpg)

## Codice `C`

### [Argomenti variabili](./varfun.c)

```C
#include <stdio.h>
int varfun (int a , ...)
{
  return a;
}

int main()
{
  varfun (23,46);
  printf("%d\n", varfun (23,47,16));

}
```

```sh
$ cc -o varfun varfun.c
$ ./varfun
23
```

## Compiti per casa

* scrivere, compilare e far girare piccoli programmi per verificare l'effettiva consistenza
  degli argomenti visti in classe:
  * *arrays*: dichiarazione, dichiarazione inizializzata, utilizzo (accesso)
