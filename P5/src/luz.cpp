#include "luz.h"
#include <iostream>
using namespace std;

Luz::Luz(){

	luces[0] = 0;
	luces[1] = 0;
	luces[2] = 0;
	luces[3] = 0;
	luces[4] = 0;
	luces[5] = 0;
	luces[6] = 0;
	luces[7] = 0;
	n_luz = -1;
}

void Luz::activarLuz(int n){

	if(luces[n] == 0){

		n_luz = n;
		luces[n] = 1;

		switch(n){

			case 0: 
				glEnable(GL_LIGHT0);
				break;
			case 1: 
				glEnable(GL_LIGHT1);
				break;
			case 2: 
				glEnable(GL_LIGHT2);
				break;
			case 3: 
				glEnable(GL_LIGHT3);
				break;
			case 4: 
				glEnable(GL_LIGHT4);
				break;
			case 5: 
				glEnable(GL_LIGHT5);
				break;
			case 6: 
				glEnable(GL_LIGHT6);
				break;
			case 7: 
				glEnable(GL_LIGHT7);
				break;
		}
	}
}


void Luz::setValores(float * af, float * df, float * sf, float * pos){


	if(n_luz != -1){

		caf = af;
		cdf = df;
		csf = sf;
		posf = pos;

		switch(n_luz){

			case 0: 
				glLightfv(GL_LIGHT0, GL_AMBIENT, caf);
				glLightfv(GL_LIGHT0, GL_DIFFUSE, cdf);
				glLightfv(GL_LIGHT0, GL_SPECULAR, csf);
				glLightfv(GL_LIGHT0, GL_POSITION, posf);
				break;
			case 1: 
				glLightfv(GL_LIGHT1, GL_AMBIENT, caf);
				glLightfv(GL_LIGHT1, GL_DIFFUSE, cdf);
				glLightfv(GL_LIGHT1, GL_SPECULAR, csf);
				glLightfv(GL_LIGHT1, GL_POSITION, posf);
				break;
			case 2: 
				glLightfv(GL_LIGHT2, GL_AMBIENT, caf);
				glLightfv(GL_LIGHT2, GL_DIFFUSE, cdf);
				glLightfv(GL_LIGHT2, GL_SPECULAR, csf);
				glLightfv(GL_LIGHT2, GL_POSITION, posf);
				break;
			case 3: 
				glLightfv(GL_LIGHT3, GL_AMBIENT, caf);
				glLightfv(GL_LIGHT3, GL_DIFFUSE, cdf);
				glLightfv(GL_LIGHT3, GL_SPECULAR, csf);
				glLightfv(GL_LIGHT3, GL_POSITION, posf);
				break;
			case 4: 
				glLightfv(GL_LIGHT4, GL_AMBIENT, caf);
				glLightfv(GL_LIGHT4, GL_DIFFUSE, cdf);
				glLightfv(GL_LIGHT4, GL_SPECULAR, csf);
				glLightfv(GL_LIGHT4, GL_POSITION, posf);
				break;
			case 5: 
				glLightfv(GL_LIGHT5, GL_AMBIENT, caf);
				glLightfv(GL_LIGHT5, GL_DIFFUSE, cdf);
				glLightfv(GL_LIGHT5, GL_SPECULAR, csf);
				glLightfv(GL_LIGHT5, GL_POSITION, posf);
				break;
			case 6: 
				glLightfv(GL_LIGHT6, GL_AMBIENT, caf);
				glLightfv(GL_LIGHT6, GL_DIFFUSE, cdf);
				glLightfv(GL_LIGHT6, GL_SPECULAR, csf);
				glLightfv(GL_LIGHT6, GL_POSITION, posf);
				break;
			case 7: 
				glLightfv(GL_LIGHT7, GL_AMBIENT, caf);
				glLightfv(GL_LIGHT7, GL_DIFFUSE, cdf);
				glLightfv(GL_LIGHT7, GL_SPECULAR, csf);
				glLightfv(GL_LIGHT7, GL_POSITION, posf);
				break;
		}

	}

}


void Luz::apagarLuz(){

	if(n_luz != -1){

		luces[n_luz] = 0;

		switch(n_luz){

			case 0: 
				glDisable(GL_LIGHT0);
				break;
			case 1: 
				glDisable(GL_LIGHT1);
				break;
			case 2: 
				glDisable(GL_LIGHT2);
				break;
			case 3: 
				glDisable(GL_LIGHT3);
				break;
			case 4: 
				glDisable(GL_LIGHT4);
				break;
			case 5: 
				glDisable(GL_LIGHT5);
				break;
			case 6: 
				glDisable(GL_LIGHT6);
				break;
			case 7: 
				glDisable(GL_LIGHT7);
				break;
		}

	}

}

	
