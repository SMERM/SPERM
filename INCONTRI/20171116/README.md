# Incontro del 16 novembre 2017

## Argomenti

* Discussione del progetto [`osc`](../PROGETTI/osc/README.md)
  * cli interface
  * libreria dinamica wrappable
  * altre interfacce

* Prima iterazione:
  * set up della struttura (`main` + libreria)
  * strumentario ([autotools](https://www.gnu.org/software/automake/manual/html_node/Autotools-Introduction.html))
  * testing suite ([check](https://libcheck.github.io/check/doc/check_html/check_3.html))
  * doxygen documentation
  * prima versione: oscillatore calcolato, frequenza fissa, output ascii su
    terminale

* Seconda iterazione:
  * argomenti da linea di comando (opzioni + frequenza/e)
  * gestione delle opzioni (`getopt`)
  * gestione dell'output sonoro machine-independent
