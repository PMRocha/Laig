#include "XMLScene.h"
#include "CGFapplication.h"
#include <iostream>
#include <string>
#include "TPinterface.h"
#include "PickingInterface.h"

using namespace std;

int main (int argc, char* argv[])
{
	CGFapplication app = CGFapplication();
	 XMLScene* xml;
	 PickingInterface * pi;
	if(argc==2)
		xml = new XMLScene(argv[1]);
	else
		xml = new XMLScene("wall-e.xml");
	try {
		app.init(&argc, argv);
		 
		app.setScene(xml);
		app.setInterface(new TPinterface());
		pi = new PickingInterface(xml);
		app.setInterface(pi);
		app.run();
	}
	catch(GLexception& ex) {
		cout << "Erro: " << ex.what();
		return -1;
	}
	catch(exception& ex) {
		cout << "Erro inesperado: " << ex.what();
		return -1;
	}

	return 0;
}