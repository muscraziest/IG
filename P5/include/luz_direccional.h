#include <GL/gl.h>
#include <GL/glut.h>
#include "luz.h"

#ifndef _LUZDIRECCIONAL_H
#define _LUZDIRECCIONAL_H

class LuzDireccional:public Luz{

	private:
	float alfa;
	float beta;

	public:
	LuzDireccional(int);
	void aumentar_alfa();
	void reducir_alfa();
	void aumentar_beta();
	void reducir_beta();
};

#endif
