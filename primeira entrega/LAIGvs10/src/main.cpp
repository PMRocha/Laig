#include "CGFapplication.h"
#include <iostream>
#include <string>
#include "XMLScene.h"
#include "TPinterface.h"
using namespace std;

int main (int argc, char* argv[])
{
	CGFapplication app = CGFapplication();
	 XMLScene* xml;
	if(argc==2)
    xml = new XMLScene(argv[1]);
	else
	xml = new XMLScene("wall-e.xml");
	try {
		app.init(&argc, argv);
		 
		app.setScene(xml);
		app.setInterface(new TPinterface());
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