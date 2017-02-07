#include <cmath>
#include <vector>
#include <GL/gl.h>
#include <GL/glut.h>
#include "jpg_imagen.hpp"

#ifndef _OBJETO3D_H
#define _OBJETO3D_H

using namespace std;

struct Tupla3r{

	float x,y,z;
};

struct Tupla3n{

	int v1,v2,v3;
};

struct Tupla2r{

	float coor_x, coor_y;
};

struct Material{

	GLfloat * ambiente;
	GLfloat * difusa;
	GLfloat * especular;
	float brillo;
};

class Objeto3D{

protected:
    
    int num_tri;
    int num_ver;
	vector<Tupla3r> vertices;
	vector<Tupla3n> caras;
	vector<Tupla3r> normales_caras;
	vector<Tupla3r> normales_vertices;
	vector<Tupla2r> coordenadas_textura;
    int id_textura;
    Material material;
    jpg::Imagen * imagen;

public:

	void dibujar15(int );
	void dibujar20(int );
	void dibujarAjedrez();
	void calcular_normales();
	void calcular_coordenadas_textura(int);
	void cargar_imagen(const string &);
	void setMaterial(float *, float *, float *, float);
	void imprimirMaterial();
};

#endif
