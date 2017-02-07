#ifndef _PIERNA_H
#define _PIERNA_H

#include <objeto3D.h>
#include <file_ply_stl.hpp>
#include <ply.h>

using namespace std;

class Pierna:public Objeto3D{

private:
    
    Ply *leg1;
    Ply *leg2;
    Ply	*shoe;

public:

	Pierna();

	void dibujar20(int, float, float);
};
#endif
