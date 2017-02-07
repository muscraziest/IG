#include <objeto3D.h>
#include <cstdio>
#include <iostream>
#include <GL/gl.h>
#include <GL/glut.h>

using namespace std;

/***************************************
Función dibujar versión 1.5
***************************************/
void Objeto3D::dibujar15(int tipo){


	switch(tipo){

		//Sólo puntos
		case 1: 
			glColor3f(1.0,0.0,0.0);
			glPolygonMode(GL_FRONT_AND_BACK,GL_POINT);
			break;
		//Alambres
		case 2: 
			glColor3f(0.0,1.0,0.0);
			glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
			break;
		//Sólido
		case 3: 
			glColor3f(0.0,0.0,1.0);
			glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
			break;
		//Modo puntos, alambres y sólido
		case 5:
			dibujar15(1);
			dibujar15(2);
			dibujar15(3);
	}
			
	glBegin(GL_TRIANGLES);

		for(int i = 0; i < num_tri; ++i){

			//Ajedrez
			if(tipo == 4){
		   		if(i%2==0)
		   			glColor3f(1.0,0.0,0.0);
		   		else
		   			glColor3f(0.0,1.0,0.0);
		   	}

		   	Tupla3n i_vert = caras[i];

			for(int j = 0; j < 3; ++j){

 				int ind_ver = *(&(i_vert.v1)+j);
 				glVertex3fv(&(vertices[ind_ver].x));
	   		}
		} 
    glEnd();
}


/***************************************
Función dibujar versión 2.0
***************************************/
void Objeto3D::dibujar20(int tipo){

	switch(tipo){

		//Sólo puntos
		case 1: 
			glColor3f(1.0,0.0,0.0);
			glPolygonMode(GL_FRONT_AND_BACK,GL_POINT);
			break;
		//Alambres
		case 2: 
			glColor3f(0.0,1.0,0.0);
			glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
			break;
		//Sólido
		case 3: 
			glColor3f(0.0,0.0,1.0);
			glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
			break;
		//Modo puntos, alambres y sólido
		case 5:
			dibujar20(1);
			dibujar20(2);
			dibujar20(3);
	}

	glEnableClientState(GL_VERTEX_ARRAY);
	glVertexPointer(3,GL_FLOAT,0,&(vertices[0]));
	glDrawElements(GL_TRIANGLES,3*caras.size(),GL_UNSIGNED_INT,&(caras[0]));
}

/***************************************
Función dibujar ajedrez versión 2.0
***************************************/
void Objeto3D::dibujarAjedrez(){

	std::vector <Tupla3n> pares, impares;

	for(int i=0; i < caras.size(); i+=2)
		pares.push_back(caras.at(i));

	for(int i=1; i < caras.size(); i+=2)
		impares.push_back(caras.at(i));	


	glEnableClientState(GL_VERTEX_ARRAY);
	glVertexPointer(3,GL_FLOAT,0,&(vertices[0]));
	glColor3f(1.0,0.0,0.0);
	glDrawElements(GL_TRIANGLES,3*pares.size(),GL_UNSIGNED_INT,&(pares[0]));
	glColor3f(0.0,1.0,0.0);
	glDrawElements(GL_TRIANGLES,3*impares.size(),GL_UNSIGNED_INT,&(impares[0]));
}


