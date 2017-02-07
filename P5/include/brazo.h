#ifndef _BRAZO_H
#define _BRAZO_H

#include <objeto3D.h>
#include <file_ply_stl.hpp>
#include <ply.h>

using namespace std;

class Brazo{

private:
    
    Ply *hand;
    Ply *arm;
    Ply *ring;

public:

	Brazo();

	void dibujar20(int,float,float);
};
#endif
