# Incontro del 15 maggio 2020 (effettuato in remoto)

## [Video della lezione](https://youtu.be/vtYpwg-vrOg)

## Argomenti

* Correzione del compito dato

* Backtracking sulla sintassi `C` prima di re-analizzare il codice `osc` già prodotto:
  * l'uso dei puntatori a funzione in *object-oriented programming*
  * la stenografia `->`
  * unioni
  * argomenti alla funzione `main`: argomenti della linea di comando

## [l'uso dei puntatori a funzione in *object-oriented programming* (correzione del compito dato)](./la_mia_forma_in_classe.c)

![puntatori in *object-oriented programming*](./puntatori_OOP.png)

```C
#include <stdio.h>

struct FormaGeometrica
{
	void(*disegnati)(const struct FormaGeometrica*);
	void(*spiegati)(const struct FormaGeometrica*);														/*perche dopo gli asterischi non c'è nulla ?				*/
	char nome[8];
	const char add;
};

struct Triangolo 
{
	struct FormaGeometrica fg;
	char simpatia;
};

void disegnati_fg(const struct FormaGeometrica *buttalo)
{
	printf("\n Non disegno nulla \n");
}

void spiegati_fg(const struct FormaGeometrica *buttalo)
{   
	printf("<<\n Ora mi spiego:");
	printf(buttalo->nome);																				/*perche devo usare le frecce e non posso usare il puntino ?*/
	/*Si poteva anche scrivere in un altro modo, ovvero (*buttalo).nome */
	printf("\n>>\n");
}

void disegnati_Triangolo(const struct FormaGeometrica *buttalo)
{
	const struct Triangolo *p = (const struct Triangolo *) buttalo;
	printf("\n Disegno un triangolo con simpatia %c\n",p->simpatia);
}

int main ()
{
	struct FormaGeometrica Giulio = {disegnati_fg,spiegati_fg,"indefini"};
	struct Triangolo 	   France = {{disegnati_Triangolo,spiegati_fg,"triangol"},'k'};
	struct FormaGeometrica*p;
	
	p= &Giulio;
	(*(p->disegnati))(p);
	(*(p->spiegati))(p);
	p= (struct FormaGeometrica*) &France; 
	(*(p->disegnati))(p);
	(*(p->spiegati))(p);
	/*char test[]=(*(p->simpatia))(p);*/ 	/* fare un cast del genere significa che non posso accedere ad eventuali attributi 								*/
											/* che ha solo triangolo e non ha FormaGeometrica ? e nel caso come faccio ? devo smontare il cast e rifarlo ?  */
											/* NON per forza, posso anche attuare una soluzione come quella a linea 26										*/	
}
```

```sh
$ cc -o lmfic la_mia_forma_in_classe.c
$ ./lmfic

 Non disegno nulla
<<
 Ora mi spiego:indefini
>>

 Disegno un triangolo con simpatia k
<<
 Ora mi spiego:triangol
>>

```

## la stenografia `->`

![la stenografia `->`](./stenografia_puntatori_strutture.png)

## Unioni

![le unioni](./union.png)

### [unione.c](./unione.c)

```C
#include <stdio.h>
#include <math.h>
union A
{
  int x;
  char y;
  double z;
};

int main()
{
  union A a;
  union A *p=&a;
  a.z=M_E;
  printf("%p visto come double: %20.18f\n",p,p->z);
  printf("%p visto come char: '%c' (%d)\n",p,p->y,p->y);
  printf("%p visto come int: %d\n",p,p->x);
}
```

```sh
$ cc -o unione unione.c
$ ./unione
0x7fffd723f5e0 visto come double: 2.718281828459045091
0x7fffd723f5e0 visto come char: 'i' (105)
0x7fffd723f5e0 visto come int: -1961601175
```

## Argomenti sulla linea di comando

### [ciao0.c](./ciao0.c)

```C
#include <stdio.h>

int main(int argc,const char *argv[])
{
  printf("ciao %s!\n", argv[1]);
}
```

```sh
$ cc -o ciao0 ciao0.c
$ ./ciao0 corso
ciao corso!
```

### [ciao1.c](./ciao1.c)

```C
#include <stdio.h>

int main(int argc,const char *argv[])
{
  if (argc <2)
  {
    printf("%s: utilizzo\n%s nome...\n",argv[0],argv[0]);
    return -1;
  }
  printf("ciao %s!\n", argv[1]);
  return 0;
}
```

```sh
$ cc -o ciao1 ciao1.c
$ ./ciao1
./ciao1: utilizzo
./ciao1 nome...
$ ./ciao1 corso
ciao corso!
```

### [ciao2.c](./ciao2.c)

```C
#include <stdio.h>

int main(int argc,const char *argv[])
{
  int c=1;
  if (argc <2)
  {
    printf("%s: utilizzo\n%s nome...\n",argv[0],argv[0]);
    return -1;
  }
  printf("ciao");
  while(c<argc)
  {
    printf(" %s", argv[c]);
    ++c;
  }
  printf("!\n");
  return 0;
}
```

```sh
$ ./ciao2
./ciao2: utilizzo
./ciao2 nome...
$ ./ciao2 Francesco Giulio Gabriele Filippo Milo
ciao Francesco Giulio Gabriele Filippo Milo!
```

## Compiti per casa

* scrivere, compilare e far girare piccoli programmi per verificare l'effettiva consistenza
  degli argomenti visti in classe:
  * unioni
  * argomenti sulla linea di comando
