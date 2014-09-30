#include "XMLScene.h"

XMLScene::XMLScene(char *filename)
{

	// Read XML from file

	doc=new TiXmlDocument( filename );
	bool loadOkay = doc->LoadFile();

	if ( !loadOkay )
	{
		printf( "Could not load file '%s'. Error='%s'. Exiting.\n", filename, doc->ErrorDesc() );
		exit( 1 );
	}

	TiXmlElement* anfElement= doc->FirstChildElement( "anf" );

	if (anfElement == NULL)
	{
		printf("Main dgx block element not found! Exiting!\n");
		exit(1);
	}

	globalsElement = anfElement->FirstChildElement( "globals" );
	camerasElement = anfElement->FirstChildElement( "cameras" );
	lightsElement =  anfElement->FirstChildElement( "lights" );
	texturesElement =  anfElement->FirstChildElement( "textures" );
	appearancesElement =  anfElement->FirstChildElement( "appearance" );

	graphElement =  anfElement->FirstChildElement( "graph" );


	// Init
	// An example of well-known, required nodes

	if (globalsElement == NULL)
		printf("Global block not found!\n");
	else
	{
		printf("Processing Global:\n");
		// frustum: example of a node with individual attributes
		TiXmlElement* drawingElement=globalsElement->FirstChildElement("drawing");
		if (drawingElement)
		{
			char *modeString=NULL,*shadingString=NULL,*backgrounfString=NULL;
			float rBackground,gBackground,bBackground,aBackground;

			modeString =(char *) drawingElement->Attribute("mode");
			shadingString =(char *) drawingElement->Attribute("shading");
			backgrounfString =(char *) drawingElement->Attribute("background");

			if (modeString && shadingString && backgrounfString && sscanf(backgrounfString,"%f %f %f %f",&rBackground, &gBackground, &bBackground, &aBackground)==4)
				printf("  drawing attributes: %s %s %f %f %f %f\n", modeString, shadingString, rBackground, gBackground, bBackground, aBackground);
			else
				printf("Error parsing Drawing\n");
		}
		else
			printf("drawing not found\n");


		// translate: example of a node with an attribute comprising several float values
		// It shows an example of extracting an attribute's value, and then further parsing that value 
		// to extract individual values
		TiXmlElement* cullingElement=globalsElement->FirstChildElement("culling");
		if (cullingElement)
		{
			char *faceString=NULL,*orderString=NULL;

			faceString =(char *) cullingElement->Attribute("face");
			orderString =(char *) cullingElement->Attribute("order");

			if(faceString && orderString)
			{
				printf("  culling values: %s , %s \n", faceString, orderString);
			}
			else
				printf("Error parsing culling");
		}
		else
			printf("culling not found\n");		


		TiXmlElement* lightingElement=globalsElement->FirstChildElement("lighting");
		if (lightingElement)
		{
			char *modeString=NULL,*shadingString=NULL,*backgrounfString=NULL;
			float rBackground,gBackground,bBackground,aBackground;

			modeString =(char *) drawingElement->Attribute("mode");
			shadingString =(char *) drawingElement->Attribute("shading");
			backgrounfString =(char *) drawingElement->Attribute("background");

			if (modeString && shadingString && backgrounfString && sscanf(backgrounfString,"%f %f %f %f",&rBackground, &gBackground, &bBackground, &aBackground)==4)
				printf("  drawing attributes: %s %s %f %f %f %f\n", modeString, shadingString, rBackground, gBackground, bBackground, aBackground);
			else
				printf("Error parsing Drawing\n");
		}
		else
			printf("drawing not found\n");
	}

	// Other blocks could be validated/processed here


	// graph section
	if (graphElement == NULL)
		printf("Graph block not found!\n");
	else
	{
		char *prefix="  -";
		TiXmlElement *node=graphElement->FirstChildElement();

		while (node)
		{
			printf("Node id '%s' - Descendants:\n",node->Attribute("id"));
			TiXmlElement *child=node->FirstChildElement();
			while (child)
			{
				if (strcmp(child->Value(),"Node")==0)
				{
					// access node data by searching for its id in the nodes section
					
					TiXmlElement *noderef=findChildByAttribute(graphElement,"id",child->Attribute("id"));

					if (noderef)
					{
						// print id
						printf("  - Node id: '%s'\n", child->Attribute("id"));

						// prints some of the data
						printf("    - Material id: '%s' \n", noderef->FirstChildElement("material")->Attribute("id"));
						printf("    - Texture id: '%s' \n", noderef->FirstChildElement("texture")->Attribute("id"));

						// repeat for other leaf details
					}
					else
						printf("  - Node id: '%s': NOT FOUND IN THE NODES SECTION\n", child->Attribute("id"));

				}
				if (strcmp(child->Value(),"Leaf")==0)
				{
					// access leaf data by searching for its id in the leaves section
					TiXmlElement *leaf=findChildByAttribute(texturesElement,"id",child->Attribute("id"));

					if (leaf)
					{
						// it is a leaf and it is present in the leaves section
						printf("  - Leaf id: '%s' ; type: '%s'\n", child->Attribute("id"), leaf->Attribute("type"));

						// repeat for other leaf details
					}
					else
						printf("  - Leaf id: '%s' - NOT FOUND IN THE LEAVES SECTION\n",child->Attribute("id"));
				}

				child=child->NextSiblingElement();
			}
			node=node->NextSiblingElement();
		}
	}

}

XMLScene::~XMLScene()
{
	delete(doc);
}

//-------------------------------------------------------

TiXmlElement *XMLScene::findChildByAttribute(TiXmlElement *parent,const char * attr, const char *val)
// Searches within descendants of a parent for a node that has an attribute _attr_ (e.g. an id) with the value _val_
// A more elaborate version of this would rely on XPath expressions
{
	TiXmlElement *child=parent->FirstChildElement();
	int found=0;

	while (child && !found)
		if (child->Attribute(attr) && strcmp(child->Attribute(attr),val)==0)
			found=1;
		else
			child=child->NextSiblingElement();

	return child;
}


