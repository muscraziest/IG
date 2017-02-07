#ifndef _OBJETO3D_H
#define _OBJETO3D_H

#include <vector>
using namespace std;

struct Tupla3r{

	float x,y,z;
};

struct Tupla3n{

	int v1,v2,v3;
};

class Objeto3D{

protected:
    
    int num_tri;
    int num_ver;
	vector<Tupla3r> vertices;
	vector<Tupla3n> caras;

public:

	void dibujar15(int );
	void dibujar20(int );
	void dibujarAjedrez();
};
#endif
