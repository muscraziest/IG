#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <GL/gl.h>
#include <GL/glut.h>
#include "escena.h"

Escena::Escena(){
    Front_plane=50;
    Back_plane=2000;
    Observer_distance = 4*Front_plane;
    Observer_angle_x = Observer_angle_y=0;
    tipo = 0; //Al inicio no dibuja ningún objeto
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
	glScalef(10.0,10.0,10.0);
	switch(practica){

		case 1:
			switch(tipo){

				case 0:
					break;
				case 1:
					objeto->dibujar20(1);
					break;
				case 2:
					objeto->dibujar20(2);
					break;
				case 3:
					objeto->dibujar20(3);
					break;
				case 4:
					objeto->dibujarAjedrez();
					break;
				case 5:
					objeto->dibujar20(5);
					break;
			}
		break;

		case 2:
			switch(tipo){

				case 0:
					break;
				case 1:
					objeto->dibujar20(1);
					break;
				case 2:
					objeto->dibujar20(2);
					break;
				case 3:
					objeto->dibujar20(3);
					break;
				case 4:
					objeto->dibujarAjedrez();
					break;
				case 5:
					objeto->dibujar20(5);
					break;
			}
		break;

		case 3:
			if(tipo != 0)
				s->dibujar20(3);
			
			break;
		case 4:
			
			if(tipo != 0){

	    		float amb[4];
				float dif[4];
				float esp[4];
				float b;

				glPushMatrix();
					glPushMatrix();
						glScalef(5.0,5.0,5.0);

						//Material gris para las tapas de la lata
						amb[0]=0.19225;
						amb[1]=0.19225;
						amb[2]=0.19225;
						amb[3]=1.0;
						dif[0]=0.50754;
						dif[1]=0.50754;
						dif[2]=0.50754;
						dif[3]=1.0;
						esp[0]=0.508273;
						esp[1]=0.508273;
						esp[2]=0.508273;
						esp[3]=1.0;
						b=40.0;

						lata_psup->setMaterial(amb,dif,esp,b);
						lata_pinf->setMaterial(amb,dif,esp,b);
						lata_psup->dibujar20(tipo);
						lata_pcue->dibujar20(tipo);
						lata_pinf->dibujar20(tipo);
					glPopMatrix();
					glPushMatrix();
						glTranslatef(0.0,1.5,3.0);
						peon1->dibujar20(tipo);
					glPopMatrix();
					glPushMatrix();
						glTranslatef(0.0,1.5,6.0);

						//Material blanco
						amb[0]=0.05;
						amb[1]=0.05;
						amb[2]=0.05;
						amb[3]=1.0;
						dif[0]=0.5;
						dif[1]=0.5;
						dif[2]=0.5;
						dif[3]=1.0;
						esp[0]=0.70;
						esp[1]=0.70;
						esp[2]=0.70;
						esp[3]=1.0;
						b=0.0;

						peon2->setMaterial(amb,dif,esp,b);
						peon2->dibujar20(tipo);
					glPopMatrix();
					glPushMatrix();
						glTranslatef(0.0,1.5,9.0);

						//Material negro
						amb[0]=0.0;
						amb[1]=0.0;
						amb[2]=0.0;
						amb[3]=1.0;
						dif[0]=0.01;
						dif[1]=0.01;
						dif[2]=0.01;
						dif[3]=1.0;
						esp[0]=0.5;
						esp[1]=0.5;
						esp[2]=0.5;
						esp[3]=1.0;
						b=30.0;

						peon3->setMaterial(amb,dif,esp,b);
						peon3->dibujar20(tipo);
					glPopMatrix();
				glPopMatrix();
			}

			break;
	}
}


void Escena::encenderLuces(){

	float af[] = {0.0,0.0,0.0,1.0};
	float df[] = {1.0,1.0,1.0,1.0};
	float sf[] = {1.0,1.0,1.0,1.0};
	float pos[] = {0.0,0.0,1.0,1.0};

	luzp->setValores(af,df,sf,pos);

	pos[3] = 0.0;

	luzd->setValores(af,df,sf,pos);
}


void Escena::dibujar() {

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT ); // Limpiar la pantalla
	change_observer(); //colocar al observador
	draw_axis(); //if (dibujarEjes) ejes->dibujar(); 
	draw_objects(); //dibujar objetos
}

int Escena::teclaPulsada(unsigned char Tecla1,int x,int y) {

    std::cout << "Tecla" << Tecla1<< std::endl;

    if (Tecla1 == '1') practica = 1;
    else if(Tecla1 == '2') practica = 2;
    else if(Tecla1 == '3') practica = 3;
    else if(Tecla1 == '4') practica = 4;
    //else if(Tecla1 == '5') practica = 5;

    if(Tecla1 == 'p') tipo = 1;
    else if(Tecla1 == 'l') tipo = 2;
    else if(Tecla1 == 's') tipo = 3;
    else if(Tecla1 == 'a') tipo = 4;
    else if(Tecla1 == 'c') tipo = 5;

    switch(practica){

    	case 1:
			//glDisable(GL_LIGHTING);

    		if (Tecla1 == 'C'){
    			objeto = new Cubo();
    			tipo = 3;
    		}

    		if (Tecla1 == 'T'){
    			objeto = new Tetraedro();
    			tipo = 3;
    		}

    		break;

    	case 2:

			//glDisable(GL_LIGHTING);

    		if(Tecla1 == 'P'){
    			char * nombre = new char[256];
	
				cout << "Introduce el nombre del archivo: " << endl;
				cin.getline(nombre,256);
		
				objeto = new Ply(nombre);
				tipo = 3;

				delete [] nombre;
    		}

    		if (Tecla1 == 'R'){
    			char * nombre = new char[256];
				int pasos;
				char s_n;
			    cout << "Introduce el nombre del archivo: " << endl;
				cin.getline(nombre,256);

				cout << "Introduce el número de pasos: " << endl;
				cin >> pasos;
				cout << "¿Cerrar tapas? [s/n]" << endl;
				cin >> s_n;

				bool tapas;
				
				if(s_n == 's') tapas = true;
				else tapas = false;

				objeto = new OR(nombre,pasos,tapas);
				tipo = 3;

				delete [] nombre;
    		}

    		break;

    	case 3:

			//glDisable(GL_LIGHTING);

	    	if(toupper(Tecla1) == 'S'){
				s = new Sonic();
				tipo = 5;
	    	}

		    if(Tecla1 == 'Z')
				s->levantar_brazo_der();    

		    if(Tecla1 == 'X')
				s->levantar_brazo_izq();    

		    if(Tecla1 == 'z')
				s->bajar_brazo_der();    

		    if(Tecla1 == 'x')
				s->bajar_brazo_izq();    
		   
		    if(Tecla1 == 'V')
				s->levantar_pierna_der();    
		    
		    if(Tecla1 == 'v')
				s->bajar_pierna_der();    
		    
		    if(Tecla1 == 'B')
				s->levantar_pierna_izq();    

		    if(Tecla1 == 'b')
				s->bajar_pierna_izq();    

		    if(Tecla1 == 'N')
				s->levantar_rodilla_der();    
		    
		    if(Tecla1 == 'n')
				s->bajar_rodilla_der();    
		    
		    if(Tecla1 == 'M')
				s->levantar_rodilla_izq();    
		    
		    if(Tecla1 == 'm')
				s->bajar_rodilla_izq();    

		    if(Tecla1 == 'K')
				s->girar_cabeza_der();    
		   
		    if(Tecla1 == 'k')
				s->girar_cabeza_izq();    

		    if(Tecla1 == 'L')
				s->girar_cabeza_arriba();

		    if(Tecla1 == 'l')
				s->girar_cabeza_abajo();
		    
		    if(Tecla1 == 'H')
				s->lanzar_anillo_izq();
		    
		    if(Tecla1 == 'h')
				s->recuperar_anillo_izq();

		    if(Tecla1 == 'J')
				s->lanzar_anillo_der();

		    if(Tecla1 == 'j')
				s->recuperar_anillo_der();

			break;

    	case 4:

			glEnable(GL_LIGHTING);
			glShadeModel(GL_SMOOTH);

			if(toupper(Tecla1) == 'P'){
	    		peon1 = new OR("./perfil",30,true);
				peon1->cargar_imagen("./text-madera.jpg");
	    		peon2 = new OR("./perfil",30,true);
	    		peon3 = peon2;
				lata_pcue = new OR("./lata-pcue",30,false);
				lata_pcue->cargar_imagen("./text-lata-1.jpg");
				lata_pinf = new OR("./lata-pinf",30,true);
				lata_psup = new OR("./lata-psup",30,true);
				luzp = new LuzPosicional(0);
				luzd = new LuzDireccional(1);
	    		tipo = 3;

	    		encenderLuces();

			}

			if(toupper(Tecla1) == 'A')
				luzd->reducir_alfa();
			if(toupper(Tecla1) == 'D')
				luzd->aumentar_alfa();
			if(toupper(Tecla1) == 'W')
				luzd->aumentar_beta();
			if(toupper(Tecla1) == 'S')
				luzd->reducir_beta();
			if(Tecla1 == 'z')
				luzp->apagarLuz();
			if(Tecla1 == 'Z')
				luzp->activarLuz(0);
			if(Tecla1 == 'x')
				luzd->apagarLuz();
			if(Tecla1 == 'X')
				luzd->activarLuz(1);
    		break;
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

	//std::cout << Observer_distance << std::endl;
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
