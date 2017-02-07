#ifndef _PLY_H
#define _PLY_H

#include <objeto3D.h>
#include "file_ply_stl.h"
 
class Ply:public Objeto3D{

	public:
	Ply(char * file);
};

#endif
