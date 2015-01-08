#include "PickingInterface.h"
#include "XMLScene.h"
#include "CGFapplication.h"

// buffer to be used to store the hits during picking
#define BUFSIZE 256
GLuint selectBuf[BUFSIZE];
int test[2], picked[2];

PickingInterface::PickingInterface(XMLScene * xene) {
	mode = "origin";
	this->xene = xene;

	//initiate connection
	if(!connection.socketConnect()) {
		std::cout << "Failed to establish connection... =(" << std::endl;
		getchar();
		exit(0);
	}

	//get board's initial state
	for(int i = 0; i < 9; i++) {
		for(int j = 0; j < 9; j++) {
			char element[256];
			connection.receiveData(element);
			xene->board[i][j] = element[1];
		}
	}

	//TEST: print board
	std::cout << "INITAL BOARD CONDITION:" << std::endl;
	for(int i = 0; i < 9; i++) {
		for(int j = 0; j < 9; j++) {
			std::cout << xene->board[i][j];
		}
		std::cout << std::endl;
	}

	//initialize pieces
	for(int i = 0; i < 9; i++) {
		for(int j = 0; j < 9; j++) {
			if(xene->board[i][j] == 'B' || xene->board[i][j] == 'W') {
				ScenePiece sp(0.0f, 0.0f, 0.0f);
				xene->pieces.push_back(sp);
				xene->pieces.back().setName(j, i);
				if(xene->board[i][j] == 'B')
					xene->pieces.back().setColor('b',xene->sceneTextures["black"]);
				else
					xene->pieces.back().setColor('w',xene->sceneTextures["white"]);
			}
		}
	}
}

PickingInterface::~PickingInterface() {
	//terminate connection
	connection.quit();
}

void PickingInterface::processMouse(int button, int state, int x, int y) 
{
	CGFinterface::processMouse(button,state, x, y);

	// do picking on mouse press (GLUT_DOWN)
	// this could be more elaborate, e.g. only performing picking when there is a click (DOWN followed by UP) on the same place
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
		performPicking(x,y);
	if (button == GLUT_LEFT_BUTTON && state == GLUT_UP){
		performPicking(x,y);
		if(test[0] == picked[0] && test[1] == picked[1]){
			printf("Picked ID's: ");
			cout << test[0] << " " << picked[0] << " " << test[1] << " " << picked[1] << " ";
			printf("\n");
			xene->picked = true;
			xene->ring.move(picked[0],picked[1]);

			//send picking data
			if(test[0] == NULL) {
				char data[5];
				char pickedVal[33];
				strcpy(data, itoa(picked[0], pickedVal, 10));
				strcat(data, "\n");
				connection.sendData(data, strlen(data));

			}

			test[0] = NULL;
			test[1] = NULL;
			picked[0] = NULL;
			picked[1] = NULL;
		}
		else {
			test[0] = NULL;
			test[1] = NULL;
			picked[0] = NULL;
			picked[1] = NULL;

		}
	}
}

void PickingInterface::performPicking(int x, int y) 
{
	// Sets the buffer to be used for selection and activate selection mode
	glSelectBuffer (BUFSIZE, selectBuf);
	glRenderMode(GL_SELECT);

	// Initialize the picking name stack
	glInitNames();

	// The process of picking manipulates the projection matrix
	// so we will be activating, saving and manipulating it
	glMatrixMode(GL_PROJECTION);

	//store current projmatrix to restore easily in the end with a pop
	glPushMatrix ();

	//get the actual projection matrix values on an array of our own to multiply with pick matrix later
	GLfloat projmat[16];
	glGetFloatv(GL_PROJECTION_MATRIX,projmat);

	// reset projection matrix
	glLoadIdentity();

	// get current viewport and use it as reference for 
	// setting a small picking window of 5x5 pixels around mouse coordinates for picking
	GLint viewport[4];
	glGetIntegerv(GL_VIEWPORT, viewport);

	// this is multiplied in the projection matrix
	gluPickMatrix ((GLdouble) x, (GLdouble) (CGFapplication::height - y), 5.0, 5.0, viewport);

	// multiply the projection matrix stored in our array to ensure same conditions as in normal render
	glMultMatrixf(projmat);

	// force scene drawing under this mode
	// only the names of objects that fall in the 5x5 window will actually be stored in the buffer
	scene->display();

	// restore original projection matrix
	glMatrixMode (GL_PROJECTION);
	glPopMatrix ();

	glFlush();

	// revert to render mode, get the picking results and process them
	GLint hits;
	hits = glRenderMode(GL_RENDER);
	processHits(hits, selectBuf);
}

void PickingInterface::processHits (GLint hits, GLuint buffer[]) 
{
	GLuint *ptr = buffer;
	GLuint mindepth = 0xFFFFFFFF;
	GLuint *selected=NULL;
	GLuint nselected;

	// iterate over the list of hits, and choosing the one closer to the viewer (lower depth)
	for (int i=0;i<hits;i++) {
		int num = *ptr; ptr++;
		GLuint z1 = *ptr; ptr++;
		ptr++;
		if (z1 < mindepth && num>0) {
			mindepth = z1;
			selected = ptr;
			nselected=num;
		}
		for (int j=0; j < num; j++) 
			ptr++;
	}
	
	// if there were hits, the one selected is in "selected", and it consist of nselected "names" (integer ID's)
	if (selected!=NULL)
	{
		// this should be replaced by code handling the picked object's ID's (stored in "selected"), 
		// possibly invoking a method on the scene class and passing "selected" and "nselected"
		
		for (int i=0; i<nselected; i++)
			if(test[i]==NULL){
				test[i] = selected[i];
			}
			else{
				picked[i] = selected[i];
			}
		
	}
}
