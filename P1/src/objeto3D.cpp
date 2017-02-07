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
			glPolygonMode(GL_FRONT_AND_BACK,GL_POINT);
			break;
		//Alambres
		case 2: 
			glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
			break;
		//Sólido
		case 3: 
			glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
			break;
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
			glPolygonMode(GL_FRONT_AND_BACK,GL_POINT);
			break;
		//Alambres
		case 2: 
			glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
			break;
		//Sólido
		case 3: 
			glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
			break;
	}

	glEnableClientState(GL_VERTEX_ARRAY);
	glVertexPointer(3,GL_FLOAT,0,&(vertices[0]));
	glDrawElements(GL_TRIANGLES,3*caras.size(),GL_UNSIGNED_INT,&(caras[0]));
}
