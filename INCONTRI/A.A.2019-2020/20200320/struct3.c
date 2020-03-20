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
  const int num = 2;
  struct persona aggendina [num];
  int i;

  strcpy(aggendina[0].nome, "Giulio");
  strcpy(aggendina[0].cognome, "De Mattia");
  strcpy(aggendina[0].numero, "342-3232-342");
  strcpy(aggendina[0].soprannome, "er patata");
  strcpy(aggendina[1].nome, "TRUMP");
  strcpy(aggendina[1].cognome, "DONUTS");
  strcpy(aggendina[1].numero, "342-3232-666");
  strcpy(aggendina[1].soprannome, "er CHICCO FRESCO");

  for (i = 0; i < num; ++i)
  {
    printf("nome:\t%s,\ncognome:\t%s,\nnumero:\t%s,\nsoprannome:\t%s,\n\n", aggendina[i].nome , aggendina[i].cognome , aggendina[i].numero , aggendina[i].soprannome);
  }

}
