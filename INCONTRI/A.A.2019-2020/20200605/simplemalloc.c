#include <stdio.h>

#define MEMORY_SPACE (1000000)
static char ram[MEMORY_SPACE]={'\0'};

typedef struct
{
  char * prossima;
  char * nostra;
}Memoria;

void * simple_malloc(const size_t dimension)
{
  Memoria *p = (Memoria*)ram;  /*PUNTIAMO MEMORIA ALL'INIZIO DELLA MEMORIA RAM, CON IL CAST L'ARRAY DI BYTE DIVIENE UN STRUTTURA DATI*/

  while(p->prossima != (char*)NULL)
    p = (Memoria *) p->prossima;

  p->prossima = p->nostra + dimension;
  return &p->nostra;
}

void simple_free(void * memoria)
{
  Memoria *p = (Memoria*)ram, *precedente = (Memoria*)ram;

  while(p->prossima != (char*)NULL && p->nostra != (char *)memoria)
  {
    precedente = p;
    p = (Memoria *) p->prossima;
  }
  p->nostra = (char*)NULL;
  precedente->prossima = p->prossima;

}

/*  ESERCIZIO   */
/*CREARE UN MAIN CHE FACCIA IL TEST */
