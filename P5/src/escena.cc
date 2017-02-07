#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <GL/gl.h>
#include <GL/glut.h>
#include "escena.h"
#include "camara.h"

Escena::Escena(){
    Front_plane=50;
    Back_plane=2000;
    Observer_distance = 4*Front_plane;
    Observer_angle_x = Observer_angle_y=0;
    tipo = 0; //Al inicio no dibuja ningún objeto
    cam_i = 0;
    e[0] = 0.0;
    e[1] = 0.0;
    e[2] = 60.0;
    a[0] = 0.0;
    a[1] = 0.0;
    a[2] = 0.0;
    u[0] = 0.0;
    u[1] = 1.0;
    u[2] = 0.0;
    estadoRaton = false;
    examinar = false;
    objeto_seleccionado = -1;
    xant = 0;
    yant = 0;
    zoomFactor = 1.0;

    //Inicializamos las cámaras
    double e1[] = {0.0,0.0,60.0};
    double e2[] = {0.0,60.0,0.0};
    double e3[] = {60.0,0.0,0.0};
    double a1[] = {0.0,0.0,0.0};
    double u1[] = {0.0,1.0,0.0};
    double u2[] = {1.0,0.0,0.0};

 	//Cámara 1: Frontal
    Camara cam1(e1,a1,u1);
   	camaras.push_back(cam1);

    //Cámara 2: Planta
    Camara cam2(e2,a1,u2);
    camaras.push_back(cam2);

	//Cámara 3: Perfil
	Camara cam3(e3,a1,u1);
	camaras.push_back(cam3);
   
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
	//glScalef(10.0,10.0,10.0);
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
				s->dibujar20(tipo);
			
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
						b=1.0;

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

		case 5:

			if(tipo != 0){
				/*
				glPushMatrix();
					glPushMatrix();
						glTranslatef(5.0,3.0,-10.0);
						//glScalef(5.0,5.0,5.0);
						objeto->dibujar20(tipo);
					glPopMatrix();
					glPushMatrix();
						glTranslatef(-5.0,3.0,10.0);
						//glScalef(5.0,5.0,5.0);
						objeto->dibujar20(tipo);
					glPopMatrix();
					glPushMatrix();
						glTranslatef(-5.0,3.0,-10.0);
						//glScalef(5.0,5.0,5.0);
						objeto->dibujar20(tipo);
					glPopMatrix();
					glPushMatrix();
						glTranslatef(5.0,3.0,10.0);
						//glScalef(5.0,5.0,5.0);
						objeto->dibujar20(tipo);
					glPopMatrix();
				glPopMatrix();
				*/

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
						b=1.0;

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
    else if(Tecla1 == '5') practica = 5;

    if(Tecla1 == 'p') tipo = 1;
    else if(Tecla1 == 'l') tipo = 2;
    else if(Tecla1 == 's') tipo = 3;
    else if(Tecla1 == 'a') tipo = 4;
    else if(Tecla1 == 'c') tipo = 5;

    switch(practica){

    	case 1:
			glDisable(GL_LIGHTING);

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

			glDisable(GL_LIGHTING);

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

			glDisable(GL_LIGHTING);

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

    	case 5:

    		glEnable(GL_LIGHTING);
			glShadeModel(GL_SMOOTH);

			if(toupper(Tecla1) == 'C'){
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

    		if(!examinar){

    			zoomFactor = 1.0;

				if(toupper(Tecla1) == 'A'){

					switch(cam_i){
						case 0:
							--e[0];
							break;

						case 1:
							--e[2];
							break;

						case 2:
							--e[2];		
					}
				}
				if(toupper(Tecla1) == 'D'){

					switch(cam_i){
						case 0:
							++e[0];
							break;

						case 1:
							++e[2];
							break;

						case 2:
							++e[2];		
					}
				}

				if(toupper(Tecla1) == 'S'){

					switch(cam_i){
						case 0:
							++e[1];
							break;

						case 1:
							++e[0];
							break;

						case 2:
							++e[1];		
					}
				} 

				if(toupper(Tecla1) == 'W'){

					switch(cam_i){
						case 0:
							--e[1];
							break;

						case 1:
							--e[0];
							break;

						case 2:
							--e[1];		
					}
				} 
			}

			else{

				if(toupper(Tecla1) == 'W'){

					zoomFactor-=0.2;
					change_projection();
				}

				if(toupper(Tecla1) == 'S'){

					zoomFactor+=0.2;
					change_projection();
				}

			}

			if(toupper(Tecla1) == 'R'){

    			switch(cam_i){
    				//Frontal
    				case 0:
    					e[0] = 0.0;
    					e[1] = 0.0;
						e[2] = 60.0;
						a[0] = 0.0;
					    a[1] = 0.0;
					    a[2] = 0.0;
						u[0] = 0.0;
						u[1] = 1.0;
						camaras[cam_i].setPosicion(e,a,u);
						break;
					//Planta
					case 1:
						e[0] = 0.0;
						e[1] = 60.0;
						e[2] = 0.0;
						a[0] = 0.0;
					    a[1] = 0.0;
					    a[2] = 0.0;
						u[0] = 1.0;
						u[1] = 0.0;
						camaras[cam_i].setPosicion(e,a,u);
						break;
					//Lateral
					case 2:
						e[0] = 60.0;
			    		e[1] = 0.0;
						e[2] = 0.0;
						a[0] = 0.0;
					    a[1] = 0.0;
					    a[2] = 0.0;
						u[0] = 0.0;
						u[1] = 1.0;
						camaras[cam_i].setPosicion(e,a,u);
						break;
    			}
    		}
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
	case GLUT_KEY_F1: 
		cam_i = 0;
		e[0] = 0.0;
		e[1] = 0.0;
		e[2] = 60.0;
		u[0] = 0.0;
		u[1] = 1.0;
		break;
	case GLUT_KEY_F2: 
		cam_i = 1;
		e[0] = 0.0;
		e[1] = 60.0;
		e[2] = 0.0;
		u[0] = 1.0;
		u[1] = 0.0;
		break;
	case GLUT_KEY_F3: 
		cam_i = 2;
		e[0] = 60.0;
		e[1] = 0.0;
		e[2] = 0.0;
		u[0] = 0.0;
		u[1] = 1.0;
		break;
	}

	//std::cout << Observer_distance << std::endl;
}


//**************************************************************************
// Funcion para definir la transformación de proyeccion
//***************************************************************************

void Escena::change_projection()  {
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	if(cam_i == 0)
		glOrtho(-Width*zoomFactor,Width*zoomFactor,-Height*zoomFactor,Height*zoomFactor,Front_plane,Back_plane);
	else
		glFrustum(-Width*zoomFactor,Width*zoomFactor,-Height*zoomFactor,Height*zoomFactor,Front_plane,Back_plane);

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
	//glTranslatef(0,0,-Observer_distance);
	//glRotatef(Observer_angle_x,1,0,0);
	//glRotatef(Observer_angle_y,0,1,0);
	camaras[cam_i].setPosicion(e,a,u);
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

//**************************************************************************
// Funcion para clicar con el raton
//**************************************************************************
void Escena::clickRaton(int boton, int estado, int x, int y){

	if(boton == GLUT_RIGHT_BUTTON){
		examinar = false;
		if(estado == GLUT_DOWN){
			estadoRaton = true;
			xant = x;
			yant = y;
		}

		else{
			estadoRaton=false;
		}
	}

	if(boton == GLUT_LEFT_BUTTON){
		objeto_seleccionado = pick(x,y);

		if(objeto_seleccionado != -1){
			examinar = true;

			switch(objeto_seleccionado){

				case 1:
					a[0] = 0.0;
					a[1] = 0.0;
					a[2] = 0.0;
					break;
				case 2:
					a[0] = 0.0;
					a[1] = 3.0;
					a[2] = 3.0;
					break;
				case 3:
					a[0] = 0.0;
					a[1] = 3.0;
					a[2] = 6.0;
					break;
				case 4:
					a[0] = 0.0;
					a[1] = 3.0;
					a[2] = 9.0;
					break;
			}
		}

		else{
			a[0] = 0.0;
			a[1] = 0.0;
			a[2] = 0.0;
		}

		if(estado == GLUT_DOWN){
			estadoRaton = true;
			xant = x;
			yant = y;
		}

		else
			estadoRaton=false;
	}
}


//**************************************************************************
// Funcion para mover el raton
//**************************************************************************

void Escena::ratonMovido(int x, int y){

	if(estadoRaton == 1){

		camaras[cam_i].girar(x-xant,y-yant,examinar);
		xant = x;
		yant = y;
	}
}

//**************************************************************************
// Funciones para seleccionar
//**************************************************************************

void Escena::dibujaSeleccion(){

	glDisable(GL_DITHER);
	glDisable(GL_TEXTURE);
	glDisable(GL_LIGHTING);

	for(int i=0; i < 2; i++){
		for(int j=0; j < 2; j++){
			glPushMatrix();
				switch(i*2+j){

					case 0: 
						glColor3ub(255,0,0); 
						glTranslatef(0.0,0.0,0.0);
						lata_psup->dibujar20(tipo);
						lata_pcue->dibujar20(tipo);
						lata_pinf->dibujar20(tipo);  
						break;

					case 1: 
						glColor3ub(0,255,0); 
						glTranslatef(0.0,1.5,3.0); 
						peon1->dibujar20(tipo);
						break;

					case 2: 
						glColor3ub(0,0,255); 
						glTranslatef(0.0,1.5,6.0); 
						peon2->dibujar20(tipo);
						break;

					case 3: 
						glColor3ub(250,0,0);
						glTranslatef(0.0,1.5,9.0);
						peon3->dibujar20(tipo);
						break;
				}

			glPopMatrix();
		}
	}

	glEnable(GL_DITHER);
	glEnable(GL_TEXTURE);
	glEnable(GL_LIGHTING);
}

int Escena::pick(int x, int y){

	dibujaSeleccion();

	GLint viewport[4];
	GLubyte pixel[3];

	glGetIntegerv(GL_VIEWPORT,viewport);

	glReadPixels(x,viewport[3]-y,1,1,GL_RGB,GL_UNSIGNED_BYTE,(void *)pixel);

	if(pixel[0] == 255)
		return 1;
	else if (pixel[1] == 255)
		return 2;
	else if (pixel[2] == 255)
		return 3;
	else if (pixel[0] == 250)
		return 4;
	else
		return -1;
}