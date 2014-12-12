#include "XMLScene.h"


XMLScene::XMLScene(char *filename)
{

	// Read XML from file
	this->filename=filename;
	drawmode=0;

}

void XMLScene::init()
{
	glEnable(GL_LIGHTING);
	loadFile();
	glMatrixMode(GL_MODELVIEW);
	//calcs tranformations on primitives
	sceneGraph->calcPrimitives();
}

void XMLScene::drawObjects()
{
	vector<Node*> nodes = sceneGraph->getNodes();

	string id=sceneGraph->getRootId();
	vector<string> sonIds;

	glPushMatrix();
	//searches for the father and gets sons

	auxDrawObjectsRoot();
	glPopMatrix();
}

void XMLScene::auxDrawObjectsRoot()
{
	
	vector<string> childrenIds;
	vector<Node*> nodes = sceneGraph->getNodes();
	vector<SceneObject*> objects;


			objects=nodes[0]->getObjects();
			childrenIds=nodes[0]->getChildNodeIds();

			glPushMatrix();


			glMultMatrixf(& nodes[0]->transMatrix[0]);

			glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT );
			glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT );

			//set appearance
			
			if(nodes[0]->getNodeAppearance().second->getSWrap()!=nodes[0]->getTextS())
				nodes[0]->setTextS(nodes[0]->getNodeAppearance().second->getSWrap());

			if(nodes[0]->getNodeAppearance().second->getTWrap()!=nodes[0]->getTextT())
				nodes[0]->setTextT(nodes[0]->getNodeAppearance().second->getTWrap());

			nodes[0]->getNodeAppearance().second->apply();

			if(nodes[0]->getDisplayList())
				{
					glCallList(nodes[0]->getDisplayListId());
				}
			else{
				for (unsigned int j=0;j<objects.size();j++)
				{
				
					objects[j]->draw();
				}
			}

			//if child is found
			if(childrenIds.size()>0)
			{
				auxDrawObjects(childrenIds,nodes[0]->getNodeAppearance());
			}
			glPopMatrix();
		
}

void XMLScene::auxDrawObjects(vector<string> sonIds,pair<string,Appearance*> fatherAppearance)
{
	//searches son position on vector
	unsigned int sonInd;
	vector<string> childrenIds;
	vector<Node*> nodes = sceneGraph->getNodes();
	vector<SceneObject*> objects;


	for (unsigned int j=0;j<sonIds.size();j++)
	{
		for (sonInd=0;sonInd<nodes.size();sonInd++)
		{



			if(sonIds[j]==nodes[sonInd]->getId())
			{
				objects=nodes[sonInd]->getObjects();
				childrenIds=nodes[sonInd]->getChildNodeIds();

				glPushMatrix();


				glMultMatrixf(& nodes[sonInd]->transMatrix[0]);

				glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT );
				glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT );

				//set appearance
				if(nodes[sonInd]->getNodeAppearance().first=="inherit")
				{
					if(fatherAppearance.second->getSWrap()!=nodes[sonInd]->getTextS())
						nodes[sonInd]->setTextS(fatherAppearance.second->getSWrap());

					if(fatherAppearance.second->getTWrap()!=nodes[sonInd]->getTextT())
						nodes[sonInd]->setTextT(fatherAppearance.second->getTWrap());

					fatherAppearance.second->apply();
				}

				else
				{
					if(nodes[sonInd]->getNodeAppearance().second->getSWrap()!=nodes[sonInd]->getTextS())
						nodes[sonInd]->setTextS(nodes[sonInd]->getNodeAppearance().second->getSWrap());

					if(nodes[sonInd]->getNodeAppearance().second->getTWrap()!=nodes[sonInd]->getTextT())
						nodes[sonInd]->setTextT(nodes[sonInd]->getNodeAppearance().second->getTWrap());

					nodes[sonInd]->getNodeAppearance().second->apply();
				}


				for (unsigned int j=0;j<objects.size();j++)
				{
					objects[j]->draw();
				}

				//if child is found
				if(childrenIds.size()>0)
				{
					if(nodes[sonInd]->getNodeAppearance().first=="inherit")
					{
						auxDrawObjects(childrenIds,fatherAppearance);
					}

					else
						auxDrawObjects(childrenIds,nodes[sonInd]->getNodeAppearance());
				}

				glPopMatrix();
			}
		}
	}
}

void XMLScene::display()
{

	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	activeCamera->applyView();

	for(unsigned int i=0;i<sceneLights.size();i++)
	{
		if(activeLights[i]==1)
		{

			sceneLights[i]->enable();
			sceneLights[i]->draw();
		}
		else
			sceneLights[i]->disable();

		sceneLights[i]->update();
	}

	selectDrawMode();
	drawObjects();
	glutSwapBuffers();
}


void XMLScene::defineGlobalVariables()
{
	glClearColor(globalVariables->getBackground()[0],globalVariables->getBackground()[1],globalVariables->getBackground()[2],globalVariables->getBackground()[3]);
	glPolygonMode(GL_FRONT_AND_BACK,globalVariables->getDrawmode());
	glShadeModel(globalVariables->getShading());
	glFrontFace(globalVariables->getCullorder());
	glCullFace(globalVariables->getCullface());
	glLightModelf(GL_LIGHT_MODEL_TWO_SIDE, Light::isDoublesided());
	glLightModelf(GL_LIGHT_MODEL_LOCAL_VIEWER,Light::isLocal());
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, Light::getAmbients());
}

XMLScene::~XMLScene()
{
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

void XMLScene::processCameras(TiXmlElement* camerasElement)
{
	string rootId = camerasElement->Attribute("initial");
	char* id;
	TiXmlElement* orthoElement = camerasElement->FirstChildElement("ortho");
	TiXmlElement* perspectiveElement = camerasElement->FirstChildElement("perspective");
	CGFcamera* cam;
	float near, far, left, right, top, bottom;
	unsigned int i = 0;
	while(orthoElement != NULL)
	{
		read1Float("near",orthoElement, near);
		read1Float("far",orthoElement, far);
		read1Float("left",orthoElement, left);
		read1Float("right",orthoElement, right);
		read1Float("top",orthoElement, top);
		read1Float("bottom",orthoElement, bottom);
		id=(char*)orthoElement->Attribute("id");
		bool activated=id==rootId;
		cam = new OrthoCamera(near, far, left, right, top, bottom,activated);
		sceneCameras.push_back(make_pair(id,cam));
		orthoElement = orthoElement->NextSiblingElement("ortho");
		if(id==rootId)
			camera=i;
		else
			i++;
	}

	while(perspectiveElement != NULL)
	{
		float position[3],target[3],angle;
		read1Float("near",perspectiveElement, near);
		read1Float("far",perspectiveElement, far);
		read1Float("angle",perspectiveElement, angle);
		read3Float("pos", perspectiveElement, position[0], position[1], position[2]);
		read3Float("target", perspectiveElement, target[0], target[1], target[2]);
		id=(char*)perspectiveElement->Attribute("id");
		bool activated=id==rootId;
		cam = new PerspectiveCamera(id==rootId,near, far, angle, position[0], position[1],
			position[2], target[0], target[1], target[2]);
		sceneCameras.push_back(make_pair(id,cam));
		if(id==rootId)
			camera=i;
		else
			i++;
		perspectiveElement = perspectiveElement->NextSiblingElement("perspective");
	}
}

void XMLScene::processLights(TiXmlElement* lights)
{
	float position[4], ambient[4], diffuse[4], specular[4];
	float angle = 0, exponent = 0, target[3];
	bool enabled, marked;
	string type;
	char* id;
	Light* light;
	TiXmlElement* element = lights->FirstChildElement();
	TiXmlElement* component = element ->FirstChildElement();
	while(element!=NULL)
	{
		element->QueryBoolAttribute("enabled",&enabled);
		element->QueryBoolAttribute("marker",&marked);
		id = (char*)element->Attribute("id");
		read3Float("pos", element, position[0], position[1], position[2]);
		if(element->Attribute("target")!=NULL)
		{
			type="spot";
			read3Float("target", element, target[0], target[1],
				target[2]);
			read1Float("angle",element, angle);
			read1Float("exponent",element, exponent);

		}
		while(component != NULL)
		{
			if(component->Attribute("type")=="ambient"){
				read4Float("value", element, ambient[0], ambient[1], ambient[2],ambient[3]);
			}

			if(component->Attribute("type")=="diffuse"){
				read4Float("value", element, diffuse[0], diffuse[1], diffuse[2],diffuse[3]);
			}

			if(component->Attribute("type")=="specular"){
				read4Float("value", element, specular[0], specular[1], specular[2],specular[3]);
			}
			component=component->NextSiblingElement();
		}


		light = new Light(id,enabled,type,position,ambient,diffuse,specular,angle,exponent,target,marked);
		this->sceneLights.push_back(light);
		if(enabled)
			activeLights.push_back(1);
		else 
			activeLights.push_back(0);

		element=element->NextSiblingElement();
	}
}

void XMLScene::processTextures(TiXmlElement* texturesElement)
{
	TiXmlElement* texture = texturesElement->FirstChildElement("texture");
	CGFtexture* textureMapped;
	while(texture != NULL)
	{
		string id=texture->Attribute("id"),file=texture->Attribute("file");
		float sWrap;
		float tWrap;
		read1Float("texlength_s",texture,sWrap);
		read1Float("texlength_t",texture,tWrap);
		try
		{
			textureMapped= new CGFtexture(file);
		}
		catch(...)
		{
			cout <<"Ficheiro " << file << " nao encontrado!" << endl;
			id="";
		}
		if(id!=""){
			sceneTextures[id]=textureMapped;
		}
		Texture* temp = new Texture(id,file,sWrap,tWrap);
		Textures[id] = temp;
		texture = texture->NextSiblingElement();
	}
}

void XMLScene::processAppearances(TiXmlElement* appearancesElement)
{
	TiXmlElement* element= appearancesElement->FirstChildElement("appearance");
	float ambient[4],diffuse[4],specular[4],emissive[4],shininess,sWrap,tWrap;
	string textureRef,id;
	Appearance* appearance;
	while(element!=NULL)
	{
		id=element->Attribute("id"); 
		read1Float("shininess",element,shininess);
		if(element->Attribute("textureref")!=NULL)
			textureRef=element->Attribute("textureref");
		else textureRef="";

		TiXmlElement* component = element ->FirstChildElement();

		while(component != NULL){
			if(component->Attribute("type")=="ambient"){
				read4Float("value", element, ambient[0], ambient[1], ambient[2],
					ambient[3]);}

			if(component->Attribute("type")=="diffuse"){
				read4Float("value", element, diffuse[0], diffuse[1], diffuse[2],
					diffuse[3]);}

			if(component->Attribute("type")=="specular"){
				read4Float("value", element, specular[0], specular[1], specular[2],
					specular[3]);
			}
			component=component->NextSiblingElement();
		}

		if(textureRef!=""){

			Texture* temp = Textures[textureRef];
			appearance = new Appearance(ambient,diffuse,specular,emissive,shininess,temp->getSWrap(),temp->getTWrap(),textureRef);

			appearance->setTextureWrap(appearance->getSWrap(),appearance->getTWrap());
			appearance->setTexture(sceneTextures[textureRef]);

		}
		else
			appearance = new Appearance(ambient,diffuse,specular,emissive,shininess,1,1,textureRef);

		appearances[id]=appearance;

		element=element->NextSiblingElement("appearance");
	}
}

void XMLScene::processGraph(TiXmlElement* graphElement)
{
	string rootid=graphElement->Attribute("rootid");
	TiXmlElement* nodeElement = graphElement->FirstChildElement("node");
	sceneGraph = new Graph();
	sceneGraph->setRootId(rootid);
	while(nodeElement!=NULL)
	{
		bool displayList=false;
		string nodeId = nodeElement->Attribute("id");
		if(nodeElement->Attribute("displaylist") != NULL)
			nodeElement->QueryBoolAttribute("displaylist",&displayList);
		Node* node = new Node(nodeId, displayList);

		string animationID;
		TiXmlElement* animations = nodeElement->FirstChildElement("animationref");
		if(animations!=NULL)
			animationID=animations->Attribute("id");

		TiXmlElement* transformations = nodeElement->FirstChildElement("transforms");
		TiXmlElement* transformation = transformations->FirstChildElement();

		while(transformation!=NULL)
		{
			if(transformation->Attribute("axis")!=NULL)
			{
				string axis=transformation->Attribute("axis");
				float angle;
				read1Float("angle",transformation,angle);
				Transformation* rot = new Rotation(axis,angle);
				node->addTransformation(rot);
			}
			else if (transformation->Attribute("to")!=NULL)
			{
				float translation[3];
				read3Float("to",transformation,translation[0],translation[1],translation[2]);
				Transformation* translationElement = new Translation(translation[0],translation[1],translation[2]);
				node->addTransformation(translationElement);
			}

			else if (transformation->Attribute("factor")!=NULL)
			{
				float factor[3];
				read3Float("factor",transformation,factor[0],factor[1],factor[2]);
				Transformation* scaling = new Scaling(factor[0],factor[1],factor[2]);
				node->addTransformation(scaling);
			}

			transformation = transformation->NextSiblingElement();
		}

		TiXmlElement* appearanceRef = nodeElement->FirstChildElement("appearanceref");
		if(appearanceRef->Attribute("id")!="inherit")
		{
			node->setNodeAppearance(make_pair(appearanceRef->Attribute("id"),appearances[appearanceRef->Attribute("id")]));
		}
		else
		{
			node->setNodeAppearance(make_pair("inherit",new Appearance()));
		}
		TiXmlElement* primitive = nodeElement->FirstChildElement("primitives");
		TiXmlElement* primitiveAnalyzer = primitive->FirstChildElement();
		while(primitiveAnalyzer!=NULL)
		{
			if(primitiveAnalyzer->Attribute("xy1")!=NULL)
			{
				float xy1[2],xy2[2];
				read2Float("xy1",primitiveAnalyzer,xy1[0],xy1[1]);
				read2Float("xy2",primitiveAnalyzer,xy2[0],xy2[1]);
				SceneObject* rectangle = new SceneBoard();
				node->addObject(rectangle);
			}

			else if(primitiveAnalyzer->Attribute("xyz1")!=NULL)
			{
				float xyz1[3],xyz2[3],xyz3[3];
				read3Float("xyz1",primitiveAnalyzer,xyz1[0],xyz1[1],xyz1[2]);
				read3Float("xyz2",primitiveAnalyzer,xyz2[0],xyz2[1],xyz2[2]);
				read3Float("xyz3",primitiveAnalyzer,xyz3[0],xyz3[1],xyz3[2]);
				
				SceneObject* triangle = new SceneTriangle(xyz1,xyz2,xyz3);
				node->addObject(triangle);
			}

			else if(primitiveAnalyzer->Attribute("base")!=NULL)
			{
				float base,top,height;
				int slices,stacks;
				read1Float("base",primitiveAnalyzer,base);
				read1Float("top",primitiveAnalyzer,top);
				read1Float("height",primitiveAnalyzer,height);
				read1Int("slices",primitiveAnalyzer,slices);
				read1Int("stacks",primitiveAnalyzer,stacks);
				SceneObject* cylinder = new SceneCylinder(base,top,height,slices,stacks);
				node->addObject(cylinder);
			}

			else if(primitiveAnalyzer->Attribute("radius")!=NULL)
			{
				float radius;
				int slices,stacks;
				read1Float("radius",primitiveAnalyzer,radius);
				read1Int("slices",primitiveAnalyzer,slices);
				read1Int("stacks",primitiveAnalyzer,stacks);
				SceneObject* sphere = new SceneSphere(radius,slices,stacks);
				node->addObject(sphere);
			}

			else if(primitiveAnalyzer->Attribute("inner")!=NULL)
			{
				float inner,outer;
				int slices,loops;
				read1Float("inner",primitiveAnalyzer,inner);
				read1Float("outer",primitiveAnalyzer,outer);
				read1Int("slices",primitiveAnalyzer,slices);
				read1Int("loops",primitiveAnalyzer,loops);
				
				SceneObject* thorus = new SceneTorus(inner,outer,slices,loops);
				node->addObject(thorus);
			}

			else if(primitiveAnalyzer->Attribute("parts")!=NULL)
			{
				int parts;
				read1Int("parts",primitiveAnalyzer,parts);

				SceneObject* plane = new ScenePlane(parts);
				node->addObject(plane);

			}
			else if(strcmp(primitiveAnalyzer->Value(),"patch")==0)
			{
				int order,partsU,partsV;
				float x,y,z;
				string compute;

				primitiveAnalyzer->QueryIntAttribute("order",&order);
				primitiveAnalyzer->QueryIntAttribute("partsU",&partsU);
				primitiveAnalyzer->QueryIntAttribute("partsV",&partsV);
				compute=primitiveAnalyzer->Attribute("compute");

				ScenePatch* patch = new ScenePatch(order,partsU,partsV,compute);

				TiXmlElement* ControlPoints = primitiveAnalyzer->FirstChildElement("controlpoint");

				while(ControlPoints!=NULL)
				{
					ControlPoints->QueryFloatAttribute("x",&x);
					ControlPoints->QueryFloatAttribute("y",&y);
					ControlPoints->QueryFloatAttribute("z",&z);

					patch->addCntrPoint(x,y,z);

					ControlPoints = ControlPoints->NextSiblingElement("controlpoint");
				}
				node->addObject(patch);

			}
			else if(primitiveAnalyzer->Attribute("texture") != NULL) {
				std::string texture;
				texture = primitiveAnalyzer->Attribute("texture");
				SceneObject* flag = new SceneFlag(texture);
				node->addObject(flag);
				std::cout << "Added flag with texture: " << texture << std::endl;
			}

			primitiveAnalyzer = primitiveAnalyzer->NextSiblingElement();
		}
		TiXmlElement* descendants = nodeElement->FirstChildElement("descendants");
		TiXmlElement* descendantsAnalyzer = descendants->FirstChildElement();
		while(descendantsAnalyzer!=NULL)
		{
			node->addchildId(descendantsAnalyzer->Attribute("id"));
			
			descendantsAnalyzer=descendantsAnalyzer->NextSiblingElement();
		}

		sceneGraph->addNode(node);
		nodeElement=nodeElement->NextSiblingElement("node");

	}
}

void XMLScene::read1Int(char* attribute, TiXmlElement* element, int& f1) {
	stringstream ss;
	ss<< element->Attribute(attribute);
	ss >> f1;
	ss.clear();
}

void XMLScene::read1Float(char* attribute, TiXmlElement* element, float& f1) {
	stringstream ss;
	ss<< element->Attribute(attribute);
	ss >> f1;
	ss.clear();
}

void XMLScene::read2Float(char* attribute, TiXmlElement* element, float& f1,
	float& f2) {
		stringstream ss;
		ss<< element->Attribute(attribute);
		ss >> f1 >> f2;
		ss.clear();
}

void XMLScene::read3Float(char* attribute, TiXmlElement* element, float& f1,
	float& f2, float& f3) {
		stringstream ss;
		ss << element->Attribute(attribute);
		ss >> f1 >> f2 >> f3;
}

void XMLScene::read4Float(char* attribute, TiXmlElement* element, float& f1,
	float& f2, float& f3, float& f4) {
		stringstream ss;
		ss << element->Attribute(attribute);
		ss >> f1 >> f2 >> f3 >> f4;
}


void XMLScene::processGlobals(TiXmlElement* globalsElement) {


	char *modeString=NULL,*shadingString=NULL,*backgrounfString=NULL;
	float rBackground,gBackground,bBackground,aBackground;
	char *faceString=NULL,*orderString=NULL;

	printf("Processing Global:\n");

	TiXmlElement* drawingElement=globalsElement->FirstChildElement("drawing");
	if (drawingElement)
	{

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



	TiXmlElement* cullingElement=globalsElement->FirstChildElement("culling");
	if (cullingElement)
	{


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

	processGlobalLight(lightingElement);

	globalVariables= new Globals(rBackground, gBackground, bBackground, aBackground,
		modeString, shadingString, faceString, orderString);
}

void XMLScene::loadFile()
{
	TiXmlDocument* doc=new TiXmlDocument( filename );
	bool loadOkay = doc->LoadFile();
	if ( !loadOkay )
	{
		printf( "Could not load file '%s'. Error='%s'. Exiting.\n", filename, doc->ErrorDesc() );
		exit( 1 );
	}

	TiXmlElement* anfElement= doc->FirstChildElement( "anf" );

	if (anfElement == NULL)
	{
		printf("Main anf block element not found! Exiting!\n");
		exit(1);
	}
	TiXmlElement* globalsElement = anfElement->FirstChildElement( "globals" );
	processGlobals(globalsElement);
	TiXmlElement* camerasElement = anfElement->FirstChildElement("cameras");
	processCameras(camerasElement);
	TiXmlElement* lightingElement = anfElement->FirstChildElement("lights");
	defineGlobalVariables();
	processLights(lightingElement);
	defineGlobalVariables();
	TiXmlElement* texturesElement = anfElement->FirstChildElement("textures");
	processTextures(texturesElement);

	TiXmlElement* appearanceElement = anfElement->FirstChildElement("appearances");
	processAppearances(appearanceElement);

	TiXmlElement* graphElement = anfElement->FirstChildElement("graph");
	processGraph(graphElement);
	//sets the children to the correct bool
	sceneGraph->setChildDisplay();

}

void XMLScene::processGlobalLight( TiXmlElement* lights )
{
	bool doublesided,localLights,enabledLights;
	float globalAmbient[4];
	lights->QueryBoolAttribute("doublesided",&doublesided);


	lights->QueryBoolAttribute("enabled",&enabledLights);
	lights->QueryBoolAttribute("local",&localLights);
	read4Float("ambient",lights,globalAmbient[0],globalAmbient[1],globalAmbient[2],globalAmbient[3]);
	Light::setGlobalParameters(doublesided,localLights,enabledLights,globalAmbient);
}

void XMLScene::selectDrawMode()
{
	switch (drawmode)
	{
	case 0:
		glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
		break;
	case 1:
		glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
		break;
	case 2:
		glPolygonMode(GL_FRONT_AND_BACK,GL_POINT);
		break;	
	default:
		break;
	}
}

void XMLScene::processAnimations(TiXmlElement* animationElement){
	TiXmlElement* element = animationElement->FirstChildElement("animation");
	while(element!=NULL)
	{
		string id = element->Attribute("id"),type=element->Attribute("type");
		float span;
		element->QueryFloatAttribute("span",&span);
		vector<Point> points;
		if(type == "linear"){
			Point p;
			TiXmlElement* child = element->FirstChildElement("controlpoint");
			while(child!=NULL)
			{
				child->QueryFloatAttribute("xx", &p.x);
				child->QueryFloatAttribute("yy",&p.y);
				child->QueryFloatAttribute("zz",&p.z);
				points.push_back(p);
				child=child->NextSiblingElement();
			}
			Animation* animation = new Animation(span,type,points);
			Animations[id]=animation;
			element=element->NextSiblingElement();
		}
		else{
			float center[3], radius, startang, rotang;
			read3Float("center", element, center[0], center[1], center[2]);
			element->QueryFloatAttribute("radius",&radius);
			element->QueryFloatAttribute("startang",&startang);
			element->QueryFloatAttribute("rotang",&rotang);
			Animation* animation = new Animation(span,type,center[0],center[1],center[2],radius,startang,rotang);
			Animations[id]=animation;
			element=element->NextSiblingElement();
		}
	}
}