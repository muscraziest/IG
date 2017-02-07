#include <cubo.h>
#include <cstdio>
#include <iostream>
#include <GL/gl.h>
#include <GL/glut.h>

// cubo //////////////////////////////////////////////////////////////
//    v6----- v7
//   /|      /|
//  v2------v3|
//  | |     | |
//  | |v4---|-|v5
//  |/      |/
//  v0------v1

/**************************************
Constructor que recibe como parámetro el tamaño del lado
**************************************/
Cubo::Cubo(float size=1){

	num_ver = 8;
	num_tri = 12;

	Tupla3n ind;
	Tupla3r ver;

	//Introducimos los vértices
	//V0
	ver.x = 0;
	ver.y = 0;
	ver.z = -size;
	vertices.push_back(ver);

	//V1
	ver.x = size;
	ver.y = 0;
	ver.z = -size;
	vertices.push_back(ver);

	//V2
	ver.x = 0;
	ver.y = size;
	ver.z = -size;
	vertices.push_back(ver);
	//V3
	ver.x = size;
	ver.y = size;
	ver.z = -size;
	vertices.push_back(ver);
	//V4
	ver.x = 0;
	ver.y = 0;
	ver.z = 0;
	vertices.push_back(ver);
	//V5
	ver.x = size;
	ver.y = 0;
	ver.z = 0;
	vertices.push_back(ver);
	//V6
	ver.x = 0;
	ver.y = size;
	ver.z = 0;
	vertices.push_back(ver);
	//V7
	ver.x = size;
	ver.y = size;
	ver.z = 0;
	vertices.push_back(ver);



	//Introducimos las caras
	ind.v1 = 0;
	ind.v2 = 2;
	ind.v3 = 1;
	caras.push_back(ind);

	ind.v1 = 1;
	ind.v2 = 2;
	ind.v3 = 3;
	caras.push_back(ind);

	ind.v1 = 2;
	ind.v2 = 7;
	ind.v3 = 3;
	caras.push_back(ind);

	ind.v1 = 2;
	ind.v2 = 6;
	ind.v3 = 7;
	caras.push_back(ind);
	
	ind.v1 = 1;
	ind.v2 = 3;
	ind.v3 = 7;
	caras.push_back(ind);

	ind.v1 = 1;
	ind.v2 = 7;
	ind.v3 = 5;
	caras.push_back(ind);

	ind.v1 = 6;
	ind.v2 = 4;
	ind.v3 = 7;
	caras.push_back(ind);

	ind.v1 = 7;
	ind.v2 = 4;
	ind.v3 = 5;
	caras.push_back(ind);

	ind.v1 = 0;
	ind.v2 = 1;
	ind.v3 = 4;
	caras.push_back(ind);

	ind.v1 = 1;
	ind.v2 = 5;
	ind.v3 = 4;
	caras.push_back(ind);

	ind.v1 = 2;
	ind.v2 = 4;
	ind.v3 = 6;
	caras.push_back(ind);

	ind.v1 = 0;
	ind.v2 = 4;
	ind.v3 = 2;
	caras.push_back(ind);	
}
