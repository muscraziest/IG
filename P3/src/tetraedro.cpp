#include <tetraedro.h>
#include <cstdio>
#include <iostream>
#include <GL/gl.h>
#include <GL/glut.h>
#include <math.h>

/***************************************
Constructor
***************************************/
Tetraedro::Tetraedro(float size=1){

	num_tri = 4;
	num_ver = 4;

	Tupla3n ind;
	Tupla3r ver;

	//Introducimos los vértices
	//V0
	ver.x = 0;
	ver.y = 0;
	ver.z = 0;
	vertices.push_back(ver);

	//V1
	ver.x = size;
	ver.y = 0;
	ver.z = size;
	vertices.push_back(ver);

	//V2
	ver.x = size;
	ver.y = size;
	ver.z = 0;
	vertices.push_back(ver);

	//V3
	ver.x = 0;
	ver.y = size;
	ver.z = size;
	vertices.push_back(ver);
	

	//Introducimos las caras
	ind.v1 = 1;
	ind.v2 = 3;
	ind.v3 = 2;
	caras.push_back(ind);

	ind.v1 = 1;
	ind.v2 = 2;
	ind.v3 = 0;
	caras.push_back(ind);

	ind.v1 = 2;
	ind.v2 = 3;
	ind.v3 = 0;
	caras.push_back(ind);

	ind.v1 = 3;
	ind.v2 = 1;
	ind.v3 = 0;
	caras.push_back(ind);
}
