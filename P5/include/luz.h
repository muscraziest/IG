#include <GL/gl.h>
#include <GL/glut.h>

#ifndef _LUZ_H
#define _LUZ_H

class Luz{

protected:

	float * caf;
	float * cdf;
	float * csf;
	float * posf;
	int n_luz;
	int luces[8];

public:

	Luz();
	void activarLuz(int);
	void setValores(float *, float *, float *, float *);
	void apagarLuz();
};

#endif
