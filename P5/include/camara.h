#include <GL/gl.h>
#include <GL/glut.h>
#include <GL/glu.h>

#ifndef _CAMARA_H
#define _CAMARA_H


class Camara{

private:
	double * eye;
	double * at;
	double * up;

public:

	Camara(double *, double *, double *);
	void setPosicion (double *, double *, double *);
	void girar(int, int, bool);
};

#endif
