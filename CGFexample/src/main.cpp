/* 
 * G0_Base: projeto inicial de CGra
 * 
 */

#include <iostream>
#include <exception>
#include <String>

#include "CGFapplication.h"
#include "DemoScene.h"
#include "XMLScene.h"

using std::cout;
using std::cin;
using std::exception;


int main(int argc, char* argv[]) {

	/*CGFapplication app = CGFapplication();

	try {
		app.init(&argc, argv);

		app.setScene(new DemoScene());
		app.setInterface(new CGFinterface());
		
		app.run();
	}
	catch(GLexception& ex) {
		cout << "Error: " << ex.what();
		return -1;
	}
	catch(exception& ex) {
		cout << "Unexpected error: " << ex.what();
		return -1;
	}*/

	XMLScene("test.anf");
	system("PAUSE");
	return 0;
}