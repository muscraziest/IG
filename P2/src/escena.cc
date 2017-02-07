#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <GL/gl.h>
#include <GL/glut.h>
#include "cubo.h"
#include "tetraedro.h"
#include "ply.h"
#include "or.h"
#include "escena.h"

Escena::Escena(){
    Front_plane=50;
    Back_plane=2000;
    Observer_distance = 4*Front_plane;
    Observer_angle_x = Observer_angle_y=0;
    tipo = 3;
    cubo = true;
    tetraedro = false;
    file = false;
    revolucion = false;
}

void Escena::inicializar(int UI_window_width,int UI_window_height) {

	glClearColor(1,1,1,1);// se indica cual sera el color para limpiar la ventana	(r,v,a,al)

	glEnable(GL_DEPTH_TEST);	// se habilita el z-bufer

	this->change_projection();
	Width=UI_window_width/10;
	Height=UI_window_height/10;
	glViewport(0,0,UI_window_width,UI_window_height);
}


//**************************************************************************
// Funcion que dibuja objetos en la escena
//***************************************************************************
void Escena::draw_objects() {
	
	glEnable(GL_CULL_FACE);

	if (cubo){

		Cubo cubo_(50.0);

		switch(tipo){
			case 1:
				cubo_.dibujar20(1);
				break;
			case 2:
				cubo_.dibujar20(2);
				break;
			case 3:
				cubo_.dibujar20(3);
				break;
			case 4:
				cubo_.dibujarAjedrez();
				break;
			case 5:
				cubo_.dibujar20(5);
				break;
		}
	}

	if (tetraedro){

		Tetraedro tetra(50.0);

		switch(tipo){
			case 1:
				tetra.dibujar20(1);
				break;
			case 2:
				tetra.dibujar20(2);
				break;
			case 3:
				tetra.dibujar20(3);
				break;
			case 4:
				tetra.dibujarAjedrez();
				break;
			case 5:
				tetra.dibujar20(5);
				break;
		}
	}


	if(file){

		Ply ply(nombre);

		switch(tipo){
			case 1:
				ply.dibujar20(1);
				break;
			case 2:
				ply.dibujar20(2);
				break;
			case 3:
				ply.dibujar20(3);
				break;
			case 4:
				ply.dibujarAjedrez();
				break;
			case 5:
				ply.dibujar20(5);
		}

	}

	if(revolucion){

		bool tapas;

		if (s_n=='s') tapas = true;
		else tapas = false;

		OR obj_r(nombre, pasos, tapas);

		switch(tipo){
			case 1:
				obj_r.dibujar20(1);
				break;
			case 2:
				obj_r.dibujar20(2);
				break;
			case 3:
				obj_r.dibujar20(3);
				break;
			case 4:
				obj_r.dibujarAjedrez();
				break;
			case 5:
				obj_r.dibujar20(5);
		}

	}
	
}

void Escena::dibujar() {

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT ); // Limpiar la pantalla
	change_observer(); //colocar al observador
	draw_axis(); //if (dibujarEjes) ejes->dibujar(); 
	draw_objects(); //dibujar objetos
}

int Escena::teclaPulsada(unsigned char Tecla1,int x,int y) {

    std::cout << "Tecla" << Tecla1<< std::endl;
    if (Tecla1 == '1') tipo = 1;
    else if(Tecla1 == '2') tipo = 2;
    else if(Tecla1 == '3') tipo = 3;
    else if(Tecla1 == '4') tipo = 4;
    else if(Tecla1 == '5') tipo = 5;

    if(toupper(Tecla1) == 'C') {
    	cubo = true;
    	tetraedro = false;
    	file = false;
    	revolucion = false;
    }
    if(toupper(Tecla1) == 'T') {
    	cubo = false;
    	tetraedro = true;
    	file = false;
    	revolucion = false;
    }
    if(toupper(Tecla1) == 'F') {

    	char * n = new char[256];

    	cout << "Introduce el nombre del archivo: " << endl;
		cin.getline(n,256);
		nombre = n;

    	cubo = false;
    	tetraedro = false;
    	file = true;
    	revolucion = false;
    }
    if(toupper(Tecla1) == 'R') {

    	char * n = new char[256];

    	cout << "Introduce el nombre del archivo: " << endl;
		cin.getline(n,256);
		nombre = n;
		cout << "Introduce el número de pasos: " << endl;
		cin >> pasos;
		cout << "¿Cerrar tapas? [s/n]" << endl;
		cin >> s_n;

    	cubo = false;
    	tetraedro = false;
    	file = false;
    	revolucion = true;
    }
    if (toupper(Tecla1)=='Q') return 1;
	else return 0;
}

void Escena::teclaEspecial(int Tecla1,int x,int y) {
switch (Tecla1){
	case GLUT_KEY_LEFT:Observer_angle_y--;break;
	case GLUT_KEY_RIGHT:Observer_angle_y++;break;
	case GLUT_KEY_UP:Observer_angle_x--;break;
	case GLUT_KEY_DOWN:Observer_angle_x++;break;
	case GLUT_KEY_PAGE_UP:Observer_distance*=1.2;break;
	case GLUT_KEY_PAGE_DOWN:Observer_distance/=1.2;break;
	}

	std::cout << Observer_distance << std::endl;
}


//**************************************************************************
// Funcion para definir la transformación de proyeccion
//***************************************************************************

void Escena::change_projection()  {
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
glFrustum(-Width,Width,-Height,Height,Front_plane,Back_plane);
}


void Escena::redimensionar(int newWidth,int newHeight) {
change_projection();
Width=newWidth/10;
Height=newHeight/10;
glViewport(0,0,newWidth,newHeight);
}


//**************************************************************************
// Funcion para definir la transformación de vista (posicionar la camara)
//***************************************************************************



void Escena::change_observer() {

// posicion del observador
glMatrixMode(GL_MODELVIEW);
glLoadIdentity();
glTranslatef(0,0,-Observer_distance);
glRotatef(Observer_angle_x,1,0,0);
glRotatef(Observer_angle_y,0,1,0);
}


//**************************************************************************
// Funcion que dibuja los ejes utilizando la primitiva grafica de lineas
//***************************************************************************

void Escena::draw_axis(){
glBegin(GL_LINES);
// eje X, color rojo
glColor3f(1,0,0);
glVertex3f(-AXIS_SIZE,0,0);
glVertex3f(AXIS_SIZE,0,0);
// eje Y, color verde
glColor3f(0,1,0);
glVertex3f(0,-AXIS_SIZE,0);
glVertex3f(0,AXIS_SIZE,0);
// eje Z, color azul
glColor3f(0,0,1);
glVertex3f(0,0,-AXIS_SIZE);
glVertex3f(0,0,AXIS_SIZE);
glEnd();
}
