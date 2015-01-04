#ifndef _XMLSCENE_H_
#define _XMLSCENE_H_

#include "tinyxml.h"
#include <string>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <map>
#include <stdio.h>
#include "CGFscene.h"
#include "tinyxml.h"
#include "Light.h"
#include "Animation.h"
#include "Globals.h"
#include "OrthoCamera.h"
#include "PerspectiveCamera.h"
#include "Graph.h"
#include "Translation.h"
#include "Scaling.h"
#include "Rotation.h"
#include "SceneRectangle.h"
#include "SceneTriangle.h"
#include "SceneCylinder.h"
#include "SceneSphere.h"
#include "SceneTorus.h"
#include "SceneObject.h"
#include "ScenePlane.h"
#include "ScenePatch.h"
#include "SceneBlock.h"
#include "SceneBoard.h"
#include "ScenePiece.h"
#include "Appearance.h"
#include "Texture.h"
#include "SceneFlag.h"

class XMLScene : public CGFscene
{
public:
	ScenePiece piece;
	XMLScene(char *filename);
	~XMLScene();
	void init();

	void defineGlobalVariables();

	void display();
	void update(unsigned long millis);
	static TiXmlElement *findChildByAttribute(TiXmlElement *parent,const char * attr, const char *val);
	void processCameras(TiXmlElement* camerasElement);
	void processLights(TiXmlElement* lightsElement);

	void processGlobalLight( TiXmlElement* lights );

	void processTextures(TiXmlElement* texturesElement);
	void processAppearances(TiXmlElement* appearancesElement);
	static CGFappearance* findAppearance(string id);
	void processGraph(TiXmlElement* element);
	void read1Int(char* attribute,TiXmlElement* element,int &f1);
	void read1Float(char* attribute,TiXmlElement* element,float &f1);
	void read2Float(char* attribute,TiXmlElement* element,float &f1,float &f2);
	void read3Float(char* attribute,TiXmlElement* element,float &f1,float &f2,float &f3);
	void read4Float(char* attribute,TiXmlElement* element,float &f1,float &f2,float &f3,float &f4);
	void processGlobals(TiXmlElement* globalsElement);
	void processAnimations(TiXmlElement* animationElement);
	void loadFile();
	void drawObjects();
	void auxDrawObjects(vector<string> sonIds,pair<string,Appearance*> fatherAppearance);
	void selectDrawMode();
	void auxDrawObjectsRoot();
private:
	Globals* globalVariables;
	vector<Light*> sceneLights;
	vector<pair<char*,CGFcamera*> > sceneCameras;
	map<string,Texture*> Textures;
	map<string,Animation*> Animations;
	map<string,CGFtexture*> sceneTextures;
	map<string,Appearance*> appearances;
	Graph* sceneGraph;
	char* filename;
	vector<int> activeLights;
	friend class TPinterface;
	int drawmode;
	int camera;
	float* view_rotate;

	//time related vars
	unsigned long lastTime;
	unsigned long thisTime;
	unsigned long deltaTime;
	float dtseconds;
};
#endif