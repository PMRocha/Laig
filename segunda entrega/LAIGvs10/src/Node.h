#ifndef NODE_H
#define NODE_H
#include "Appearance.h"
#include "Transformation.h"
#include "SceneObject.h"
#include "Animation.h"
#include <iostream>
class Node
{
	string id;
	pair<string,Appearance*> nodeAppearance;
	vector<Transformation* > transformations;
	vector<SceneObject*> objects;
	vector<string> childNodeIds;
	float textT,textS;
	bool DisplayList;
	GLuint displayListId;
	Animation* animation;
public:
	Node(string id, bool displaylist=false);
	Node(void);
	~Node(void);
	string getId();
	void addTransformation(Transformation* transformation);
	void addObject(SceneObject* object);
	void addchildId(string id);
	vector<string> getChildNodeIds() const;
	pair<string, Appearance*> getNodeAppearance() const;
	void setNodeAppearance(pair<string, Appearance*> nodeAppearance);
	vector<Transformation*> getTransformations() const;
	void setTransformations(vector<Transformation*> transformations);
	void setTransMatrix(float a[16]);
	vector<SceneObject*> getObjects() const;
	void setObjects(vector<SceneObject*> objects);
	float transMatrix[16];
	void setTextT(float t);
	void setTextS(float s);
	float getTextT();
	float getTextS();
	bool getDisplayList();
	void setDisplayList(bool displayList);
	void createDisplayList(GLuint ID);
	GLuint getDisplayListId();
	void setAnimation(Animation* animation);
};

#endif