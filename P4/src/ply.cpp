#include <cstdio>
#include <iostream>
#include <GL/gl.h>
#include <GL/glut.h>
#include "ply.h"

/**************************************
Constructor que recibe como parámetro el archivo a leer
**************************************/
Ply::Ply(char * file){

	vector <float> vec_vertices;
	vector <int> vec_caras;
	imagen = NULL;

	// Leemos los vértices del fichero .ply
	_file_ply::read(file, vec_vertices, vec_caras);

	for(int i=0; i < vec_vertices.size(); i+=3){

		Tupla3r vertice;

		vertice.x = vec_vertices[i];
		vertice.y = vec_vertices[i+1];
		vertice.z = vec_vertices[i+2];

		vertices.push_back(vertice);
	}
	
	for(int i=0; i < vec_caras.size(); i+=3){

		Tupla3n cara;

		cara.v1 = vec_caras[i];
		cara.v2 = vec_caras[i+1];
		cara.v3 = vec_caras[i+2];

		caras.push_back(cara);
	}

	calcular_normales();
}
