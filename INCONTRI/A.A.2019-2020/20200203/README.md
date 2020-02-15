# Incontro del 3 febbraio 2020

## Argomenti

* Backtracking sulla sintassi `C` prima di re-analizzare il codice `osc` già prodotto:
  * dichiarazioni delle variabili
    * attributi: `const`
    * argomenti
      * passaggio per valore
      * `const`

## Programmi scritti

### [Utilizzo dell'attributo `const`](./const.c)

```C
int main()
{
	const int x=42;
	x=23;
	return x;
}
```

Provando a compilare, succede ciò che segue:

```sh
$ cc -o const const.c
const.c: In function ‘main’:
const.c:4:3: error: assignment of read-only variable ‘x’
  x=23;
   ^
```

il che dimostra che le variabili `const` sono di fatto *immutabili*.

### [Com'erano fatte le costanti *prima* che esistessero i `const`? (esempio **sbagliato**)](./def1.c)

```C
#define x 42

int main()
{
	x=23;
	return x;
}
```

Provando a compilare, succede ciò che segue:

```sh
$ cc -o def1 def1.c
def1.c: In function ‘main’:
def1.c:5:3: error: lvalue required as left operand of assignment
  x=23;
   ^
```

Il che mostra che `x` è una variabile che viene letteralmente *sostituita* dal
precompilatore (`cpp`), il quale presenta al compilatore questa situazione:

```C
$ cc -E -o def1 def1.c
$ cat def1
# 1 "def1.c"
# 1 "<built-in>"
# 1 "<command-line>"
# 31 "<command-line>"
# 1 "/usr/include/stdc-predef.h" 1 3 4
# 32 "<command-line>" 2
# 1 "def1.c"


int main()
{
 42=23;
 return 42;
}
```

### [Com'erano fatte le costanti *prima* che esistessero i `const`? (esempio **corretto**)](./def2.c)

```C
#define x 42

int main()
{
	int y=x;
	return y;
}
```

Provando a compilare, succede ciò che segue:

```sh
$ cc -o def2 def2.c
$ ./def2
$ echo $?
42
```

### [Deviazione sul funzionamento del pre-processore `cpp`](./def4.c)

Il pre-processore opera delle sostituzioni letterali. Ad esempio:


```C
#define pippo gino
#define VariabileIntera int

int main()
{
	VariabileIntera pippo=42;
	return pippo;
}
```

che produce il seguente codice

```C
# 1 "<built-in>"
# 1 "<command-line>"
# 31 "<command-line>"
# 1 "/usr/include/stdc-predef.h" 1 3 4
# 32 "<command-line>" 2
# 1 "def4.c"



int main()
{
 int gino=42;
 return gino;
}
```

Questo codice compila senza problemi:

```C
$ cc -o def4 def4.c
$ ./def4
$ echo $?
42
```

### [Deviazione sul funzionamento del pre-processore `cpp` -- tentativo di *deadlock*](./def5.c)

Il pre-processore evita i loop processando gli elementi in stretto ordine *top-down*. Ad esempio:

```C
#define pippo gino
#define gino pippo
#define VariabileIntera int

int main()
{
	VariabileIntera pippo=42;
	return pippo;
}
```

Il preprocessore produce il codice che segue:

```sh
$ cc -E -o def5.cpp def5.c
$ cat def5.cpp
# 1 "def5.c"
# 1 "<built-in>"
# 1 "<command-line>"
# 31 "<command-line>"
# 1 "/usr/include/stdc-predef.h" 1 3 4
# 32 "<command-line>" 2
# 1 "def5.c"




int main()
{
 int pippo=42;
 return pippo;
}
```

Il codice in questione compila ed esegue:

```sh
$ cc -o def5 def5.c
$ ./def5
$ echo $?
42
```

### [Argomenti delle funzioni](./arg0.c)

Le funzioni possono prendere argomenti che funzionano come variabili volatili:

```C
#include <stdio.h>

/*
 * definizione della funzione fun che
 * accetta un argomento intero
 */
int fun(int a)
{
	printf("%d\n",a);
}
int main()
{
	fun(23); /* chiamata della funzione fun con un argomento */
	fun(24); /* chiamata della funzione fun con un altro argomento */
	fun(42); /* chiamata della funzione fun con un terzo argomento */
}
```

Il codice in questione compila ed esegue:

```sh
nicb-p302u:.../20200203$ cc -o arg0 arg0.c
nicb-p302u:.../20200203$ ./arg0
23
24
42
```

### [Argomenti multipli alle funzioni](./arg1.c)

Le funzioni possono accettare argomenti multipli.

```C
#include <stdio.h>

int fun(int a, float b, char c)
{
	printf("char: %c - float: %f - int: %d\n",c,b,a);
}

int main()
{
	fun(23,3.14,'a');
	fun(24,2.78,'b');
	fun(42,1.414,'c');
}

```

Il codice in questione compila ed esegue:

```sh
$ cc -o ./arg1 arg1.c
nicb-p302u:.../20200203$ ./arg1
char: a - float: 3.140000 - int: 23
char: b - float: 2.780000 - int: 24
char: c - float: 1.414000 - int: 42
```

### [Deviazione sulla formattazione di testo con `printf`](./arg2.c)

```C
#include <stdio.h>

int fun(int a, float b, char c)
{
	printf("char: %c - float: %f - int: %d\n",c,b,a);
}
int main()
{
	fun(23.333,3.14,'a');
	fun(24.444,2.78,'b');
	fun(42.222,1.414,'c');
}
```

Il codice in questione compila ed esegue:

```sh
$ cc -o arg2 arg2.c
nicb-p302u:.../20200203$ ./arg2
char: a - float: 3.140000 - int: 23
char: b - float: 2.780000 - int: 24
char: c - float: 1.414000 - int: 42
```

Gli argomenti vengono troncati senza avviso.

### [Deviazione sulla formattazione di testo con `printf` - possibili errori](./arg3.c)

```C
#include <stdio.h>

int fun(int a, float b, char c)
{
	printf("char: %c - float: %f - int: %d\n",c,b,a);
}
int main()
{
	fun(23,3.14,'a');
	fun(20024,2.78,'b');
	fun(420000000000000,1.414,'c');
}
```

Il codice in questione compila ed esegue:

```sh
$ cc -o arg3 arg3.c
arg3.c: In function ‘main’:
arg3.c:11:6: warning: overflow in conversion from ‘long int’ to ‘int’ changes value from ‘420000000000000’ to ‘-556908544’ [-Woverflow]
  fun(420000000000000,1.414,'c');
      ^~~~~~~~~~~~~~~
nicb-p302u:.../20200203$ ./arg3
char: a - float: 3.140000 - int: 23
char: b - float: 2.780000 - int: 20024
char: c - float: 1.414000 - int: -556908544
```

### [Deviazione sulla formattazione di testo con `printf` - formattazione](./arg4.c)

```C
#include <stdio.h>

int fun(long int a, float b, char c)
{
	printf("char: %c - float: %55.50f - int: %20ld\n",c,b,a);
}
int main()
{
	fun(23,3.14,'a');
	fun(20024,2022.78,'b');
	fun(420000000000000,1.414,'c');
}
```

Il codice in questione compila ed esegue:

```sh
$ cc -o arg4 arg4.c
$ ./arg4
char: a - float:    3.14000010490417480468750000000000000000000000000000 - int:                   23
char: b - float: 2022.78002929687500000000000000000000000000000000000000 - int:                20024
char: c - float:    1.41400003433227539062500000000000000000000000000000 - int:      420000000000000
```

### [Passaggio per valore degli argomenti - 1](./arg5.c)

```C
#include <stdio.h>

int fun(int a)
{
	a=a+5;
	printf("int: %20d\n",a);
}
int main()
{
	int x=55;
	fun(x);
	printf("fuori dalla funzione: %d\n",x);
}
```

Il codice in questione dimostra che gli argomenti vengono passati per valore.
Il codice compila ed esegue:

```sh
$ cc -o arg5 arg5.c
$ ./arg5
int:                   60
fuori dalla funzione: 55
```

### [Passaggio per valore degli argomenti - 2](./arg6.c)

```C
#include <stdio.h>

int fun(const int a)
{
	int y=a;
	y+=5;
	printf("int: %20d\n",y);
}
int main()
{
	int x=55;
	fun(x);
	printf("fuori dalla funzione: %d\n",x);
}
```

Il codice in questione dimostra ulteriormente che gli argomenti vengono passati per valore.
Il codice compila ed esegue:

```sh
$ cc -o arg6 arg6.c
nicb-p302u:.../20200203$ ./arg6
int:                   60
fuori dalla funzione: 55
```

## Lavagna

![whiteboard 1](./SPERM_2020-02-03_16.10.30_1.jpg)

## Compiti per casa

* scrivere, compilare e far girare piccoli programmi per verificare l'effettiva consistenza
  degli argomenti visti in classe:
  * attributi:
    * `const`:
      * utilizzo nelle variabili
      * utilizzo negli argomenti
      * utilizzo nelle funzioni
  * argomenti:
    * passaggio per valore
