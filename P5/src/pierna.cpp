#include <pierna.h>
#include <cmath>
#include <GL/gl.h>
#include <GL/glut.h>

Pierna::Pierna(){

	leg1 = new Ply("./leg1_c");
	leg2 = new Ply("./leg1_c");
	shoe = new Ply("./shoe_c");
}

void Pierna::dibujar20(int tipo,float angulo1, float angulo2){

	//Dibujamos leg1
	glPushMatrix();
		glRotatef(angulo1,1,0,0);
		glRotatef(-5,0,0,1);
		if (tipo != 4) leg1->dibujar20(tipo);
		else leg1->dibujarAjedrez();
		//Dibujamos leg2
		glPushMatrix();
			glTranslatef(0.0,-1.2,0.0);
			glRotatef(angulo2,1,0,0);
			glRotatef(-2,0,0,1);
			if (tipo != 4) leg2->dibujar20(tipo);
			else leg2->dibujarAjedrez();
			//Dibujamos shoe
			glPushMatrix();
				glTranslatef(0.0,-2.0,0.2);
				glScalef(0.80,0.80,0.80);
				glRotatef(10,0,0,1);
				glRotatef(-7,1,0,0);
				if (tipo != 4) shoe->dibujar20(tipo);
				else shoe->dibujarAjedrez();
			glPopMatrix();	
		glPopMatrix();		
	glPopMatrix();
}
