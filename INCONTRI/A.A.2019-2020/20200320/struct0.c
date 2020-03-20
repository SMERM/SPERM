/*STRUTTURE DATI*/
/*alcuni tipi di dati non possono essere rappresentati dai nostri TIPI (char, INT , float ecc)
cosi utilizziamo nuovi tipi composti dall'addizione dei "tipi tipici": le strutture dati.
cosa sono se non altro caratteristiche o parametri di un determinato elemento preso in considerazione?*/
/*definire una struttura; come è fatta la struttura*/
#include <stdio.h>
struct persona
{
  char nome    [20]  ;
  char cognome [20] ;
  unsigned long int numero ;
};

/*utilizzare la struttura dopo averla definita*/
int main()
{
  struct persona giulio = {"Giulio Romano", "De Mattia", 3423232342};
  printf("nome : %s,\ncognome : %s,\nnumero : %d\n", giulio.nome , giulio.cognome , giulio.numero);
}
