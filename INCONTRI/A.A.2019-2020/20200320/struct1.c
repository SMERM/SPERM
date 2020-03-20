/*utilizzare un array di char e la struttura diviene "un array di caratteri"*/
#include <stdio.h>
struct persona
{
  char nome    [20] ;
  char cognome [20] ;
  char numero  [128];
};

/*utilizzare la struttura dopo averla definita*/
int main()
{
  struct persona giulio = {"Giulio Romano", "De Mattia", "0039-342-3232-342"};
  printf("nome : %s,\ncognome : %s,\nnumero : %s\n", giulio.nome , giulio.cognome , giulio.numero);
}
