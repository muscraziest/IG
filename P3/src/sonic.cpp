#include <sonic.h>
#include <cmath>
#include <GL/gl.h>
#include <GL/glut.h>

Sonic::Sonic(){

	brazo_der = new Brazo();
	brazo_izq = new Brazo();
    	torso = new Torso();
    	pierna_der = new Pierna(); 
    	pierna_izq = new Pierna();

	angulo_cabeza_lateral = 0;
	angulo_cabeza_vertical = 0;
    	angulo1_pierna_der = 0;
   	angulo1_pierna_izq = 0;
    	angulo2_pierna_der = 0;
    	angulo2_pierna_izq = 0;
    	angulo_brazo_der = 0;
    	angulo_brazo_izq = 0;
    	ring_der_x = 0;
    	ring_izq_x = 0;
}

void Sonic::dibujar20(int tipo){

	//Dibujamos torso
	glPushMatrix();
		torso->dibujar20(tipo,angulo_cabeza_lateral,angulo_cabeza_vertical);
	glPopMatrix();

	//Dibujamos brazo derecho
	glPushMatrix();
		glTranslatef(1.0,0.7,0.5);
		glRotatef(20,0,0,1);
		brazo_izq->dibujar20(tipo,angulo_brazo_der,ring_der_x);
	glPopMatrix();

	//Dibujamos brazo izquierdo
	glPushMatrix();
		glTranslatef(-1.0,0.7,0.5);
		glScalef(-1.0,1.0,1.0);
		glRotatef(20,0,0,1);
		glCullFace(GL_FRONT);
		brazo_izq->dibujar20(tipo,angulo_brazo_izq,ring_izq_x);
		glCullFace(GL_BACK);
	glPopMatrix();

	//Dibujamos pierna derecha
	glPushMatrix();
		glTranslatef(0.5,-0.6,0.5);
		glScalef(-1.0,1.0,1.0);
		glCullFace(GL_FRONT);
		pierna_izq->dibujar20(tipo,angulo1_pierna_der,angulo2_pierna_der);
		glCullFace(GL_BACK);	
	glPopMatrix();

	//Dibujamos pierna izq
	glPushMatrix();
		glTranslatef(-0.5,-0.6,0.5);
		pierna_izq->dibujar20(tipo,angulo1_pierna_izq,angulo2_pierna_izq);
	glPopMatrix();
}

void Sonic::levantar_brazo_der(){

	if(angulo_brazo_der >= -140) angulo_brazo_der--;
}

void Sonic::levantar_brazo_izq(){

	if(angulo_brazo_izq >= -140) angulo_brazo_izq--;
}

void Sonic::bajar_brazo_der(){

	if(angulo_brazo_der <= 80) angulo_brazo_der++;
}

void Sonic::bajar_brazo_izq(){

	if(angulo_brazo_izq <= 80)  angulo_brazo_izq++;
}

void Sonic::girar_cabeza_der(){

	if (angulo_cabeza_lateral <= 80) angulo_cabeza_lateral++;
}

void Sonic::girar_cabeza_izq(){

	if (angulo_cabeza_lateral >= -80) angulo_cabeza_lateral--;
}

void Sonic::girar_cabeza_abajo(){

	if(angulo_cabeza_vertical <= 20) angulo_cabeza_vertical++;
}

void Sonic::girar_cabeza_arriba(){

	if(angulo_cabeza_vertical >= -30) angulo_cabeza_vertical--;
}

void Sonic::levantar_pierna_der(){

	if(angulo1_pierna_der >= -90) angulo1_pierna_der--;	
}

void Sonic::levantar_pierna_izq(){

	if(angulo1_pierna_izq >= -90) angulo1_pierna_izq--;
}

void Sonic::levantar_rodilla_der(){
	
	if(angulo2_pierna_der >= 0) angulo2_pierna_der--;
}

void Sonic::levantar_rodilla_izq(){

	if(angulo2_pierna_izq >= 0)angulo2_pierna_izq--;
}

void Sonic::bajar_pierna_der(){

	if(angulo1_pierna_der <= 90) angulo1_pierna_der++;
}
 
void Sonic::bajar_pierna_izq(){
	
	if(angulo1_pierna_izq <= 90) angulo1_pierna_izq++;
}
 
void Sonic::bajar_rodilla_der(){

	if(angulo2_pierna_der <= 90) angulo2_pierna_der++;
}

void Sonic::bajar_rodilla_izq(){

	if(angulo2_pierna_izq <= 90) angulo2_pierna_izq++;
}

void Sonic::lanzar_anillo_der(){

	if(angulo_brazo_der >= -45) angulo_brazo_der-=2;
	else ring_der_x+=0.5;
}


void Sonic::lanzar_anillo_izq(){

	if(angulo_brazo_izq >= -45) angulo_brazo_izq-=2;
	else ring_izq_x+=0.5;

}

void Sonic::recuperar_anillo_der(){

	ring_der_x=0.0;
}

void Sonic::recuperar_anillo_izq(){

	ring_izq_x=0.0;
}

	
