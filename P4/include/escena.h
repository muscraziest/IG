#include "cubo.h"
#include "tetraedro.h"
#include "ply.h"
#include "or.h"
#include "sonic.h"
#include "brazo.h"
#include "luz.h"
#include "luz_posicional.h"
#include "luz_direccional.h"

#ifndef _ESCENA_H
#define _ESCENA_H
class Escena {
private:
// tamaño de los ejes
static const int AXIS_SIZE=5000;

// variables que definen la posicion de la camara en coordenadas polares
GLfloat Observer_distance;
GLfloat Observer_angle_x;
GLfloat Observer_angle_y;

// variables que controlan la ventana y la transformacion de perspectiva
GLfloat Width,Height,Front_plane,Back_plane;

int tipo, practica;
Objeto3D *objeto;
Objeto3D *peon1;
Objeto3D *peon2;
Objeto3D *peon3;
Objeto3D *lata_pcue;
Objeto3D *lata_pinf;
Objeto3D *lata_psup;
Sonic * s;
LuzPosicional *luzp;
LuzDireccional *luzd;

private:
	void clear_window();
	void draw_axis(); //dibujar ejes
	void draw_objects();

//Transformación de cámara
	void change_projection();
	void change_observer();


public:
    Escena();
	void inicializar(int UI_window_width,int UI_window_height);
	void redimensionar(int newWidth,int newHeight) ;

	// Dibujar
	void dibujar() ;
	void encenderLuces();
	// Interacción con la escena
	int teclaPulsada(unsigned char Tecla1,int x,int y) ;
	void teclaEspecial(int Tecla1,int x,int y);

	void idle();
};
#endif
