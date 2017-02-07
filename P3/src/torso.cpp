#include <torso.h>
#include <cmath>
#include <GL/gl.h>
#include <GL/glut.h>

Torso::Torso(){

	body = new Ply("./body_c");
	head = new Ply("./head_c");
}
 
void Torso::dibujar20(int tipo,float angulo1,float angulo2){

	//Dibujamos la cabeza
	glPushMatrix();
		glTranslatef(0.0,2.0,0.5);
		glRotatef(angulo2,1,0,0);
		glRotatef(angulo1,0,1,0);
		if (tipo != 4) head->dibujar20(tipo);
		else head->dibujarAjedrez();
	glPopMatrix();

	//Dibujamos el cuerpo
	glPushMatrix();
		if (tipo != 4) body->dibujar20(tipo);
		else body->dibujarAjedrez();
	glPopMatrix();
}
