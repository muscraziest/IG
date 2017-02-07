#include "textura.h"

Textura::Textura(char * nombre){

	pimg = new jpg::Imagen(nombre);
	tamx = pimg->tamX();
	tamy = pimg->tamY();
	texels = pimg->leerPixels();
}
