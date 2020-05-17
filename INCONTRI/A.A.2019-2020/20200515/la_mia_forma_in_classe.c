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


