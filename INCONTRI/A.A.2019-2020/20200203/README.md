# Incontro del 3 febbraio 2020

## Argomenti

* Backtracking sulla sintassi `C` prima di re-analizzare il codice `osc` già prodotto:
  * dichiarazioni delle variabili
    * attributi: `const`
    * argomenti
      * passaggio per valore
      * `const`
      * argomenti variabili
  * *arrays* e *strutture*
  * puntatori:
    * referenziazione e de-referenziazione
    * *handles*, puntatori multipli ecc.
  * equivalenza *arrays*/puntatori (similitudini e differenze)
  * stringhe
  * `main` *revisited*: `main` con argomenti e valore di ritorno
  * puntatori a funzioni

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
    * argomenti variabili
  * *arrays*: dichiarazione, dichiarazione inizializzata, utilizzo (accesso)
  * *strutture*: definizione, dichiarazione, dichiarazione inizializzata, utilizzo (accesso)
  * puntatori:
    * dichiarazione, utilizzo, de-referenziazione
    * puntatori multipli
  * stringhe:
    * dichiarazione, dichiarazione inizializzata, utilizzo
    * verifica dello `\0` finale
    * replica della funzione di libreria `strlen`
    * replica della funzione di libreria `strtok`
    * realizzazione della funzione `int conta_vocali(const char *);` (che ritorna il numero di vocali presenti in una stringa)
