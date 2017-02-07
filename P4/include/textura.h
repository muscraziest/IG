#ifndef _TEXTURA_H
#define _TEXTURA_H

#include <cmath>
#include <vector>
#include <GL/gl.h>
#include <GL/glut.h>
#include "jpg_imagen.hpp"

class Textura{

	private:
	jpg::Imagen *pimg;
	int tamx;
	int tamy;
	unsigned char * texels;

	public:

	Textura(char * nombre);
};

#endif
