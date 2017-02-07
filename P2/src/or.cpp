#include <cstdio>
#include <iostream>
#include <GL/gl.h>
#include <GL/glut.h>
#include "or.h"
#include <math.h>

/**************************************
Constructor que recibe como parámetros el archivo a leer y el número de divisiones
**************************************/
OR::OR(char * file, int pasos, bool tapas){

	vector <float> vec_vertices;
	vector <int> vec_caras;
	_file_ply file_ply;
	const float PI = 3.14159;
	float angulo, radianes;
	Tupla3n triangulo;

	// Leemos los vértices del fichero .ply
	file_ply.open(file);
	file_ply.read(vec_vertices,vec_caras);
	file_ply.close();

	Tupla3r p_base, p_rotacion;

	// Tapa superior
	if(tapas && vec_vertices[0] != 0.0){

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
		p_base.x = vec_vertices[i]*10;
		p_base.y = vec_vertices[i+1]*10;
		p_base.z = vec_vertices[i+2]*10;

		vertices.push_back(p_base);		

		for(int j=0; j < pasos; ++j){

			//Pasamos el angulo a radianes
			radianes = (angulo*PI)/180;

			//Coordenadas de cada rotacion
			p_rotacion.x = cos(radianes)*p_base.x + sin(radianes)*p_base.z;
			p_rotacion.y = p_base.y;
			p_rotacion.z = -sin(radianes)*p_base.x + cos(radianes)*p_base.z;
		
			vertices.push_back(p_rotacion);
			angulo += 360/pasos;
		}
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
		triangulo.v2=i+pasos;
		triangulo.v3=i+1;

		caras.push_back(triangulo);

		triangulo.v1=i+pasos;
		triangulo.v2=i+pasos+1;
		triangulo.v3=i+1;

		caras.push_back(triangulo);		
	}

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

		for(int j=0; j < pasos; ++j){

			//Pasamos el angulo a radianes
			radianes = (angulo*PI)/180;

			//Coordenadas de cada rotacion
			p_rotacion.x = cos(radianes)*p_base.x + sin(radianes)*p_base.z;
			p_rotacion.y = p_base.y;
			p_rotacion.z = -sin(radianes)*p_base.x + cos(radianes)*p_base.z;
		
			vertices.push_back(p_rotacion);
			angulo += 360/pasos;
		}
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
		triangulo.v2=i+pasos;
		triangulo.v3=i+1;

		caras.push_back(triangulo);

		triangulo.v1=i+pasos;
		triangulo.v2=i+pasos+1;
		triangulo.v3=i+1;

		caras.push_back(triangulo);		
	}

}
