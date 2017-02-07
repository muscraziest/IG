#ifndef _OR_H
#define _OR_H

#include <objeto3D.h>
#include "file_ply_stl.hpp"
 
class OR:public Objeto3D{

	public:
	OR(const string & nombre, int pasos, bool tapas);
	OR(vector<float>, int pasos, bool tapas);

};

#endif
