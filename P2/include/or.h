#ifndef _OR_H
#define _OR_H

#include <objeto3D.h>
#include "file_ply_stl.h"
 
class OR:public Objeto3D{

	public:
	OR(char * file, int pasos, bool tapas);
	OR(vector<float> vector, int pasos, bool tapas);
};

#endif
