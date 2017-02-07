#include "camara.h"
#include <iostream>

using namespace std;

Camara::Camara (double * e, double * a, double * u){


	eye = e;
	at = a;
	up = u;

	gluLookAt(eye[0],eye[1],eye[2],at[0],at[1],at[2],up[0],up[1],up[2]);

}


void Camara::setPosicion (double * e, double * a, double * u){

	eye = e;
	at = a;
	up = u;

	gluLookAt(eye[0],eye[1],eye[2],at[0],at[1],at[2],up[0],up[1],up[2]);

}

void Camara::girar(int x, int y, bool examinar){

	if (examinar){
		eye[0] +=x;
		eye[1] +=y;
	}

	else {
		at[0]+=x;
		at[1]+=y;
	}

	gluLookAt(eye[0],eye[1],eye[2],at[0],at[1],at[2],up[0],up[1],up[2]);
}