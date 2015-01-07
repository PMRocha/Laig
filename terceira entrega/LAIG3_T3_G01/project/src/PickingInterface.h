#ifndef PickingInterface_H
#define PickingInterface_H

#include "conn.h"
#include "CGFinterface.h"
#include "XMLScene.h"
#include <string>
#include <string.h>
#include <stdlib.h>

class PickingInterface: public CGFinterface {
	private:
		Conn connection;
		XMLScene * xene;
		std::string mode;
	public:
		PickingInterface(XMLScene *xene);
		~PickingInterface();
		virtual void processMouse(int button, int state, int x, int y);	
		void performPicking(int x, int y);
		void processHits(GLint hits, GLuint buffer[]); 
};


#endif
