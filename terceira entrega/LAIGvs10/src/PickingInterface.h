#ifndef PickingInterface_H
#define PickingInterface_H

#include "conn.h"
#include "CGFinterface.h"

class PickingInterface: public CGFinterface {
	private:
		Conn connection;
	public:
		PickingInterface();
		~PickingInterface();
		virtual void processMouse(int button, int state, int x, int y);	
		void performPicking(int x, int y);
		void processHits(GLint hits, GLuint buffer[]); 
};


#endif
