#include <objeto3D.h>
#include <cstdio>
#include <GL/gl.h>
#include <GL/glut.h>

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

	if(imagen != NULL){

		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, imagen->tamX(), imagen->tamY(), 0, GL_RGB, GL_UNSIGNED_BYTE, imagen->leerPixels());
		glLightModelf(GL_LIGHT_MODEL_COLOR_CONTROL, GL_SINGLE_COLOR);		
		//glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_NEAREST);
		glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_NEAREST);
		glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S,GL_REPEAT);
		glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T,GL_REPEAT);
		glEnable(GL_TEXTURE_2D);
		glDisable(GL_COLOR_MATERIAL);
	}

	else{
		glDisable(GL_TEXTURE_2D);

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
				break;
		}
	}

	glEnableClientState(GL_NORMAL_ARRAY);
	glNormalPointer(GL_FLOAT,0,&(normales_vertices[0]));	
	glEnable(GL_NORMALIZE);
	glEnable(GL_TEXTURE_COORD_ARRAY);
	glTexCoordPointer(2, GL_FLOAT, 0, &(coordenadas_textura[0]));
	glEnableClientState(GL_VERTEX_ARRAY);
	glVertexPointer(3,GL_FLOAT,0,&(vertices[0]));
	glDrawElements(GL_TRIANGLES,3*caras.size(),GL_UNSIGNED_INT,&(caras[0]));
	glDisableClientState(GL_VERTEX_ARRAY);
	glDisableClientState(GL_NORMAL_ARRAY);
	glDisableClientState(GL_TEXTURE_COORD_ARRAY);
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

	glDisable(GL_LIGHTING);
	glEnableClientState(GL_VERTEX_ARRAY);
	glVertexPointer(3,GL_FLOAT,0,&(vertices[0]));
	glColor3f(1.0,0.0,0.0);
	glDrawElements(GL_TRIANGLES,3*pares.size(),GL_UNSIGNED_INT,&(pares[0]));
	glColor3f(0.0,1.0,0.0);
	glDrawElements(GL_TRIANGLES,3*impares.size(),GL_UNSIGNED_INT,&(impares[0]));
}

/**************************************
Fúnción para calcular las normales de vértices y caras
**************************************/
void Objeto3D::calcular_normales(){

	Tupla3r aux, vertice_p, vertice_q, vertice_r, vector_a, vector_b, vector_normal_caras, vector_normal_vertices;
	float modulo_vector_normal_caras, modulo_vector_normal_vertices;

	normales_vertices.clear();
	normales_caras.clear();

	aux.x = 0.0;
	aux.y = 0.0;
	aux.z = 0.0;

	for(int i=0; i < vertices.size(); ++i){

		normales_vertices.push_back(aux);
	}

	//Calculamos las normales de caras
	for(int i=0; i < caras.size(); ++i){

		vertice_p = vertices[caras[i].v1];
		vertice_q = vertices[caras[i].v2];
		vertice_r = vertices[caras[i].v3];

		vector_a.x = vertice_q.x - vertice_p.x;
		vector_a.y = vertice_q.y - vertice_p.y;
		vector_a.z = vertice_q.z - vertice_p.z;

		vector_b.x = vertice_r.x - vertice_p.x;
		vector_b.y = vertice_r.y - vertice_p.y;
		vector_b.z = vertice_r.z - vertice_p.z;

		//Hacemos el producto vectorial
		vector_normal_caras.x = vector_a.y*vector_b.z - vector_b.y*vector_a.z;
		vector_normal_caras.y = (-1)*(vector_a.x*vector_b.z - vector_b.x*vector_a.z);
		vector_normal_caras.z = vector_a.x*vector_b.y - vector_b.x*vector_a.y; 

		//Normalizamos
		modulo_vector_normal_caras = sqrt(pow(vector_normal_caras.x,2)+pow(vector_normal_caras.y,2)+pow(vector_normal_caras.z,2));
		if(modulo_vector_normal_caras != 0){
			vector_normal_caras.x /= modulo_vector_normal_caras;
			vector_normal_caras.y /= modulo_vector_normal_caras;
			vector_normal_caras.z /= modulo_vector_normal_caras;
		}
		normales_caras.push_back(vector_normal_caras);

		//Vamos calculando las normales de vértices
		normales_vertices[caras[i].v1].x += vector_normal_caras.x;
		normales_vertices[caras[i].v1].y += vector_normal_caras.y;
		normales_vertices[caras[i].v1].z += vector_normal_caras.z;

		normales_vertices[caras[i].v2].x += vector_normal_caras.x;
		normales_vertices[caras[i].v2].y += vector_normal_caras.y;
		normales_vertices[caras[i].v2].z += vector_normal_caras.z;

		normales_vertices[caras[i].v3].x += vector_normal_caras.x;
		normales_vertices[caras[i].v3].y += vector_normal_caras.y;
		normales_vertices[caras[i].v3].z += vector_normal_caras.z;
		
	}

	//Normalizamos las normales de vértices
	for(int i=0; i < normales_vertices.size(); ++i){
		modulo_vector_normal_vertices = sqrt(pow(normales_vertices[i].x,2)+pow(normales_vertices[i].y,2)+pow(normales_vertices[i].z,2));
		
		if(modulo_vector_normal_vertices != 0){
			normales_vertices[i].x /= modulo_vector_normal_vertices;
			normales_vertices[i].y /= modulo_vector_normal_vertices;
			normales_vertices[i].z /= modulo_vector_normal_vertices;
		}
	}
	
}

/**************************************
Fúnción para calcular las coordenadas de textura
**************************************/
void Objeto3D::calcular_coordenadas_textura(int pasos){

	Tupla2r coordenadas;
	float y_min, y_max;

	coordenadas_textura.clear();

	y_min = vertices[0].y;
	y_max = vertices[0].y;

	for(int i=1; i < vertices.size(); ++i){
		
		if(vertices[i].y < y_min)
			y_min = vertices[i].y;

		if(vertices[i].y > y_max)
			y_max = vertices[i].y;
	}

	for(int i=0, j=0; i < vertices.size(); ++i){
	
		coordenadas.coor_x = (float)j/pasos;
		coordenadas.coor_y = (vertices[i].y - y_min) / (y_max-y_min);
		coordenadas_textura.push_back(coordenadas);
		
		if(j < pasos) ++j;
		else j=0;
	}	
}

/**************************************
Fúnción para cargar la imagen de textura
**************************************/
void Objeto3D::cargar_imagen(const string & nombre){

	//cout << "Cargando imagen" << endl;

	imagen = new jpg::Imagen(nombre);

	//cout << "Imagen cargada" << endl;

/*
	tamx = pimg->tamX();
	tamy = pimg->tamY();
	texels = pimg->leerPixels();
*/
}

/**************************************
Fúnción para cargar los valores del material 
**************************************/
void Objeto3D::setMaterial(float * amb, float * dif, float * esp, float b){

	material.ambiente = amb;
	material.difusa = dif;
	material.especular = esp;
	material.brillo = b;

	glMaterialfv(GL_FRONT,GL_AMBIENT,material.ambiente);
	glMaterialfv(GL_FRONT,GL_DIFFUSE,material.difusa);
	glMaterialfv(GL_FRONT,GL_SPECULAR,material.especular);
	glMaterialf(GL_FRONT,GL_SHININESS,material.brillo);
}