/*AGGENDINA TELEFONICA*/
/*utilizzare un array di char e la struttura diviene "un array di stringhe"*/
#include <string.h>
#include <stdio.h>
struct persona
{
  char nome    [20] ;
  char cognome [20] ;
  char numero  [128];
  char soprannome[34];
};
/*utilizzare la struttura dopo averla definita*/
int main()
{
  struct persona aggendina [2];

  strcpy(aggendina[0].nome, "Giulio");
  strcpy(aggendina[0].cognome, "De Mattia");
  strcpy(aggendina[0].numero, "342-3232-342");
  strcpy(aggendina[0].soprannome, "er patata");
  printf("nome: %s,\ncognome: %s,\nnumero: %s,\nsoprannome: %s,\n", aggendina[0].nome , aggendina[0].cognome , aggendina[0].numero , aggendina[0].soprannome);
}
