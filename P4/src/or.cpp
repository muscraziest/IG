#include <cstdio>
#include <iostream>
#include <GL/gl.h>
#include <GL/glut.h>
#include "or.h"
#include <math.h>

/**************************************
Constructor que recibe como parámetros el archivo a leer y el número de divisiones
**************************************/
OR::OR(const string & file, int pasos, bool tapas){

	vector <float> vec_vertices;
	vector <int> vec_caras;
	const float PI = 3.14159;
	float angulo, radianes;
	Tupla3n triangulo;
	imagen = NULL;

	// Leemos los vértices del fichero .ply
	_file_ply::read(file.c_str(), vec_vertices, vec_caras);

	Tupla3r p_base, p_rotacion;

	// Tapa superior
	if(tapas && vec_vertices[0] != 0.0){

		p_base.x=0.0;
		p_base.y=vec_vertices[1];
		p_base.z=0.0;

		for(int i=0; i < pasos; ++i) vertices.push_back(p_base);
	}

	//Calculamos todos los vértices
	for(int i=0; i < vec_vertices.size(); i+=3){

		//Calculamos el ángulo en radianes
		radianes = (2*PI)/pasos;

		//Coordenadas del punto base del perfil
		p_base.x = vec_vertices[i];
		p_base.y = vec_vertices[i+1];
		p_base.z = vec_vertices[i+2];

		vertices.push_back(p_base);

		for(int j=1; j < pasos; ++j){

			//Coordenadas de cada rotacion
			p_rotacion.x = cos(radianes)*p_base.x + sin(radianes)*p_base.z;
			p_rotacion.y = p_base.y;
			p_rotacion.z = -sin(radianes)*p_base.x + cos(radianes)*p_base.z;

			vertices.push_back(p_rotacion);
			radianes += (2*PI)/pasos;
		}

		vertices.push_back(p_base);
	}

	//Tapa inferior
	if(tapas && vec_vertices[vec_vertices.size()-2] != 0.0){

		p_base.x=0.0;
		p_base.y=vec_vertices[vec_vertices.size()-2];
		p_base.z=0.0;

		for(int i=0; i < pasos; ++i) vertices.push_back(p_base);	
	}

	//Calculamos los triangulos
	for(int i=0; i < vertices.size() - pasos; ++i){

		triangulo.v1=i;
		triangulo.v2=i+1;
		triangulo.v3=i+pasos+1;

		caras.push_back(triangulo);

		triangulo.v1=i+pasos+1;
		triangulo.v2=i+1;
		triangulo.v3=i+pasos+2;

		caras.push_back(triangulo);		
	}

	calcular_normales();
	calcular_coordenadas_textura(pasos);
}


/**************************************
Constructor que recibe como parámetros un vector con los vértices y el número de divisiones
**************************************/
OR::OR(vector<float> vec_vertices, int pasos, bool tapas){

	const float PI = 3.14159;
	float angulo, radianes;
	Tupla3n triangulo;
	
	Tupla3r p_base, p_rotacion;

	//Comprobamos si necesitamos tapas
	if(tapas){

		p_base.x=0.0;
		p_base.y=vec_vertices[1];
		p_base.z=0.0;

		for(int i=0; i < pasos; ++i) vertices.push_back(p_base);
	}

	//Calculamos el ángulo en radianes
	angulo = 360/pasos;

	//Calculamos todos los vértices
	for(int i=0; i < vec_vertices.size(); i+=3){

		//Coordenadas del punto base del perfil
		p_base.x = vec_vertices[i];
		p_base.y = vec_vertices[i+1];
		p_base.z = vec_vertices[i+2];

		vertices.push_back(p_base);		

		for(int j=1; j < pasos; ++j){

			//Pasamos el angulo a radianes
			radianes = (angulo*PI)/180;

			//Coordenadas de cada rotacion
			p_rotacion.x = cos(radianes)*p_base.x + sin(radianes)*p_base.z;
			p_rotacion.y = p_base.y;
			p_rotacion.z = -sin(radianes)*p_base.x + cos(radianes)*p_base.z;
		
			vertices.push_back(p_rotacion);
			angulo += 360/pasos;
		}

		vertices.push_back(p_base);
	}

	if(tapas){

		p_base.x=0.0;
		p_base.y=vertices[vertices.size()-(pasos+1)].y;
		p_base.z=0.0;

		for(int i=0; i < pasos; ++i) vertices.push_back(p_base);	
	}

	//Calculamos los triangulos
	for(int i=0; i < vertices.size() - pasos; ++i){

		triangulo.v1=i;
		triangulo.v2=i+pasos+1;
		triangulo.v3=i+1;

		caras.push_back(triangulo);

		triangulo.v1=i+pasos+1;
		triangulo.v2=i+pasos+2;
		triangulo.v3=i+1;

		caras.push_back(triangulo);		
	}

	calcular_normales();
	calcular_coordenadas_textura(pasos);
}
