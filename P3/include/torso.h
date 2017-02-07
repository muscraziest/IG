#ifndef _TORSO_H
#define _TORSO_H

#include <objeto3D.h>
#include <file_ply_stl.hpp>
#include <ply.h>

using namespace std;

class Torso:public Objeto3D{

private:
    
    Ply *head;
    Ply *body;

public:

	Torso();

	void dibujar20(int,float,float);
};
#endif
