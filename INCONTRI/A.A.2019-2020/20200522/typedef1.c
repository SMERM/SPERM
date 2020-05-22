/*typedef parola chiave per la creazione di un tipo artificiale considerato come nativo del linguaggio*/
#include <stdio.h>
#include <string.h>

typedef struct persona               /*sintassi: typedef <  nome tipo originale <  nuovo nome tipo*/
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
