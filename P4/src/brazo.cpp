#include <brazo.h>
#include <cmath>
#include <GL/gl.h>
#include <GL/glut.h>

Brazo::Brazo(){

	hand = new Ply("./hand_c");
	arm = new Ply("./arm_c");
	ring = new Ply("./ring");
}

void Brazo::dibujar20(int tipo,float angulo,float x_ring){

	//Dibujamos el brazo
	glPushMatrix();
		glRotatef(angulo,1,0,0);
		glRotatef(180.0,0,1,0);
		if (tipo != 4) arm->dibujar20(tipo);
		else arm->dibujarAjedrez();
		//Dibujamos la mano
		glPushMatrix();
			glTranslatef(0.0,-2.5,-0.2);
			glRotatef(90.0,0,1,0);
			if (tipo != 4) hand->dibujar20(tipo);
			else hand->dibujarAjedrez();
			glPushMatrix();
				glTranslatef(x_ring,0.0,0.0);
				glTranslatef(0.0,-1.0,0.5);
				glScalef(0.75,0.75,0.75);
				glRotatef(-90.0,0,1,0);
				if (tipo != 4) ring->dibujar20(tipo);
				else ring->dibujarAjedrez();
			glPopMatrix();
		glPopMatrix();
	glPopMatrix();
}
