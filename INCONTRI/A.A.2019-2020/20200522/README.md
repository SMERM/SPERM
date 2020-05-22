# Incontro del 22 maggio 2020 (effettuato in remoto)

## [Video della lezione](https://youtu.be/YUvCB37kKLs)

## Argomenti

* Backtracking sulla sintassi `C` prima di re-analizzare il codice `osc` già prodotto:
  * odds and ends: `typedef` e `sizeof()`
  * spiegazione completa degli argomenti variabili (definizione e utilizzo)
  * una versione semplificata di `printf` (da completare a casa)

## Codice `C`

### [Che cos'è `sizeof()`?](./sizeof0.c)

```C
/*SIZEOF*/
#include <stdio.h>
#include <string.h>

typedef struct
{
  double d;
  char c[8];
}Grosso;

int main()
{
  Grosso array[1000];
  printf("%d %d\n", sizeof(Grosso), sizeof(array));
}
```

```sh
$ cc -o sizeof0 sizeof0.c
$ ./sizeof0
16 16000
```

### [Che cos'è `typedef`? - 1mo programma](./typedef0.c)

```C
/*typedef parola chiave per la creazione di un tipo artificiale considerato come nativo del linguaggio*/
#include <stdio.h>

typedef int Giulio;

Giulio main()
{
  Giulio x = 23;
  printf("%d\n", x);
  return x;
}
```

```sh
$ cc -o typedef0 typedef0.c
$ ./typedef0
23
```

### [Che cos'è `typedef`? - 2do programma](./typedef1.c)

```C
/*typedef parola chiave per la creazione di un tipo artificiale considerato come nativo del linguaggio*/
#include <stdio.h>
#include <string.h>

typedef struct persona               /*sintassi: typedef <nome tipo originale> <nuovo nome tipo>;*/
{
  char nome[128];
  char cognome[128];
  char telefono[128];
  void (*stampa)(const struct persona*);
} Persona ;

void stampa_persona(const struct persona *p)
{
  printf("%s %s %s\n", p->nome,p->cognome,p->telefono);
}

int main()
{
  Persona agenda[128];
  Persona *p = agenda;
  strcpy(p->nome, "Giulio");
  strcpy(p->cognome, "De Mattia");
  strcpy(p->telefono, "342-3232-897");
  p->stampa = stampa_persona;
  (*p->stampa)(p);
}
```

```sh
$ cc -o typedef1 typedef1.c
$ ./typedef1
Giulio De Mattia 342-3232-897
```

### [Una versione semplificata di `printf` - *INCOMPLETO* (da completare a casa)](./simpleprintf.c)

```C
#include <stdio.h>
#include <stdarg.h>


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

void simple_printf(const char *format, ...)    /*modo per dichiarare argomenti variabili*/
{
  va_list l;
  int count = count_arg(format);
  int i = 0;
  va_start(l, format);
  for (i = 0; i < count; ++i)
  {
    /*COMPITO riempire come se riconosce solo gli int
    riconoscere dopo il percento*/
  }

}

int main()
{
  /* questo e` solo un test della funzione +count_arg+ */
  printf("%d\n",count_arg("test %d %d %d") );
}
```

```C
$ cc -o simpleprintf simpleprintf.c
$ ./simpleprintf
3
```

## Compiti per casa

* scrivere, compilare e far girare piccoli programmi per verificare l'effettiva consistenza
  degli argomenti visti in classe:
  * completare la funzione `simple_printf`
