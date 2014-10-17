#include "TPinterface.h"
#include "XMLScene.h"
#include "Math.h"

TPinterface::TPinterface()
{
}


void TPinterface::processKeyboard(unsigned char key, int x, int y)
{
	// Uncomment below if you would like to process the default keys (e.g. 's' for snapshot, 'Esc' for exiting, ...)
	// CGFinterface::processKeyboard(key, x, y);
}

void TPinterface::initglut()
{
	GLUI_Panel *varPanel1 = addPanel("Lights", 1);
	varPanel1->set_alignment(0);
	unsigned int size=((XMLScene*) scene)->sceneLights.size();
	for(unsigned int i = 0;i <size;i++)
	{

		addCheckboxToPanel(varPanel1,((XMLScene*) scene)->sceneLights[i]->getId(),&((XMLScene*) scene)->activeLights[i],2);
		addColumnToPanel(varPanel1);
	}
	GLUI_Panel *varPanel3 = addPanel("Cameras", 1);
	int* camera = &((XMLScene*) scene)->camera;
	GLUI_Listbox *texturesListbox =addListboxToPanel(varPanel3,"Camera: ",camera,7);
	size=((XMLScene*) scene)->sceneCameras.size();
	for(unsigned int i = 0;i<size;i++)
	texturesListbox->add_item (i, ((XMLScene*) scene)->sceneCameras[i].first);
	
	GLUI_Panel *varPanel2 = addPanel("Draw Mode", 1);
	varPanel2->set_alignment(0);
	GLUI_RadioGroup* radioGroup = addRadioGroupToPanel(varPanel2,&((XMLScene*) scene)->drawmode,3);
	addRadioButtonToGroup(radioGroup,"Fill");
	addRadioButtonToGroup(radioGroup,"Line");
	addRadioButtonToGroup(radioGroup,"Point");
}

void TPinterface::processglut(GLUI_Control *ctrl)
{/*
	printf ("glut control id: %d\n  ",ctrl->user_id);
	switch (ctrl->user_id)
	{
		case 1:
		{
			break;
		};
		
		case 7:
		{
			if(((LightingScene*) scene)->clock->getStop())
				((LightingScene*) scene)->clock->setStop(false);
			else ((LightingScene*) scene)->clock->setStop(true);
			break;
		}
	};
	*/
}

