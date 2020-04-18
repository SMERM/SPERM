#include <stdio.h>              /* PUNTATORI COSTANTI */
int main()
{
  int a = 23;
  const int *pc = &a ;          /*ptr a contenuto const che punta verso a*/

  int *const cp = &a ;          /*ptr a indirizzo costante, non a contenuto*/

  /*   *pc = 24 ;  */           /*NON PERMESSO,proviamo a cambiare il contenuto*/
  /*   ++cp;      */            /*NON PERMESSO, cambio l'indirizzo*/
  ++pc;                         /*PERMESSO poiche' l'indirizzo non e' costante*/
  *cp = 24;                     /*PERMESSO poiche' il contenuto non e' costante*/

}
