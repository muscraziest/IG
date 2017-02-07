#include "luz_direccional.h"
#include <iostream>
using namespace std;

LuzDireccional::LuzDireccional(int n){

	alfa = 0.0;
	beta = 0.0;

	activarLuz(n);
}

void LuzDireccional::aumentar_alfa(){
	++alfa;

	float af[] = {0.0,0.0,0.0,1.0};
	float df[] = {1.0,1.0,1.0,1.0};
	float sf[] = {1.0,1.0,1.0,1.0};
	float pos[]= {alfa,beta,1.0,0.0};

   	setValores(af,df,sf,pos);
}

void LuzDireccional::reducir_alfa(){
	--alfa;

	float af[] = {0.0,0.0,0.0,1.0};
	float df[] = {1.0,1.0,1.0,1.0};
	float sf[] = {1.0,1.0,1.0,1.0};
	float pos[] = {alfa,beta,1.0,0.0};

   	setValores(af,df,sf,pos);
}

void LuzDireccional::aumentar_beta(){
	++beta;

	float af[] = {0.0,0.0,0.0,1.0};
	float df[] = {1.0,1.0,1.0,1.0};
	float sf[] = {1.0,1.0,1.0,1.0};
	float pos[] = {alfa,beta,1.0,0.0};

   	setValores(af,df,sf,pos);
}

void LuzDireccional::reducir_beta(){
	--beta;

	float af[] = {0.0,0.0,0.0,1.0};
	float df[] = {1.0,1.0,1.0,1.0};
	float sf[] = {1.0,1.0,1.0,1.0};
	float pos[] = {alfa,beta,1.0,0.0};

   	setValores(af,df,sf,pos);
}
