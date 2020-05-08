#include <stdio.h>

struct FormaGeometrica
{
	void(*disegnati)(const struct FormaGeometrica*);
};

struct Quadrato
{
	struct FormaGeometrica fg;     /*istanza Forma Geometrica*/
};

struct Triangolo 
{
	struct FormaGeometrica fg;
};

void disegnati_fg(const struct FormaGeometrica *buttalo)
{
	printf("non disegno nulla\n");
}

void disegnati_Quadrato(const struct FormaGeometrica *buttalo)
{
	printf("disegno un quadrato\n");
}

void disegnati_Triangolo(const struct FormaGeometrica *buttalo)
{
	printf("disegno un triangolo\n");
}

int main ()
{
	struct FormaGeometrica Giulio = {disegnati_fg};
	struct Quadrato  Gabriele     = {{disegnati_Quadrato}};
	struct Triangolo Francesco    = {{disegnati_Triangolo}};
	struct FormaGeometrica*p ;
	
	p= &Giulio;
	(*(p->disegnati))(p);
	p= (struct FormaGeometrica*)&Gabriele;
	(*(p->disegnati))(p);
	p= (struct FormaGeometrica*)&Francesco;
	(*(p->disegnati))(p);
	
}


