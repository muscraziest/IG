#include <objeto3D.h>
#include <brazo.h>
#include <pierna.h>
#include <torso.h>

#ifndef _SONIC_H
#define _SONIC_H

using namespace std;

class Sonic:public Objeto3D{

private:
    
    Brazo *brazo_der;
    Brazo *brazo_izq;
    Torso *torso;
    Pierna *pierna_der; 
    Pierna *pierna_izq;

    float angulo_cabeza_lateral;
    float angulo_cabeza_vertical;
    float angulo1_pierna_der;
    float angulo1_pierna_izq;
    float angulo2_pierna_der;
    float angulo2_pierna_izq;
    float angulo_brazo_der;
    float angulo_brazo_izq;
    float ring_der_x;
    float ring_der_y;
    float ring_der_z;
    float ring_izq_x;
    float ring_izq_y;
    float ring_izq_z;
    

public:

	Sonic();

	void dibujar20(int);

	void levantar_brazo_der();
	void levantar_brazo_izq();
	void bajar_brazo_der();
	void bajar_brazo_izq();
	void girar_cabeza_der();
	void girar_cabeza_izq();
	void girar_cabeza_abajo();
	void girar_cabeza_arriba();
	void levantar_pierna_der(); //pierna completa
	void levantar_pierna_izq(); //pierna completa
	void levantar_rodilla_der();
	void levantar_rodilla_izq();
	void bajar_pierna_der(); //pierna completa
	void bajar_pierna_izq(); //pierna completa
	void bajar_rodilla_der();
	void bajar_rodilla_izq();
	void lanzar_anillo_der();
        void lanzar_anillo_izq();
	void recuperar_anillo_der();
	void recuperar_anillo_izq();
	void recuperar_anillos();


};

#endif
