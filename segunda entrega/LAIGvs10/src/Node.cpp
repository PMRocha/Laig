#include "Node.h"


Node::Node(void)
{
}
Node::Node(string id, bool displaylist)
{
	DisplayList=displaylist;
	this->id=id;
	textS=1;
	textT=1;
}

Node::~Node(void)
{
}

void Node::addchildId(string id)
{
	this->childNodeIds.push_back(id);
}

vector<Transformation*> Node::getTransformations() const {
	return transformations;
}

void Node::setTransformations(vector<Transformation*> transformations) {
	this->transformations = transformations;
}



void Node::addTransformation(Transformation* transformation)
{
	this->transformations.push_back(transformation);
}

void Node::addObject(SceneObject* object)
{
	this->objects.push_back(object);
}

string Node::getId()
{
	return id;
}


vector<string> Node::getChildNodeIds() const
{
	return childNodeIds;
}

void Node::setTransMatrix(float a[16])
{
	for(unsigned int i=0;i<16;i++)
	{

			transMatrix[i]=a[i];
	}
}
vector<SceneObject*> Node::getObjects() const {
	return objects;
}


void Node::setObjects(vector<SceneObject*> objects) {
	this->objects = objects;
}

void Node::setNodeAppearance(pair<string, Appearance*> nodeAppearance)
{
	this->nodeAppearance=nodeAppearance;
}

pair<string,Appearance*> Node::getNodeAppearance() const
{
	return nodeAppearance;
}

void Node::setTextT(float t)
{
	textT=t;
	for (unsigned int i=0;i<objects.size();i++)
	{
		objects[i]->setTextT(t);
	}
}

void Node::setTextS(float s)
{
	textS=s;
	for (unsigned int i=0;i<objects.size();i++)
	{
		objects[i]->setTextS(s);
	}
}

float Node::getTextT()
{
	return textT;
}

float Node::getTextS()
{
	return textS;
}

bool Node::getDisplayList(){
	return DisplayList;
}

void Node::setDisplayList(bool displayList){
	DisplayList = displayList;
}

void Node::createDisplayList(GLuint ID){
	displayListId = ID;
	glNewList(ID, GL_COMPILE);
	for(int i=0; i<objects.size();i++)
	{
		objects[i]->draw();
	}
	glEndList();
}

GLuint Node::getDisplayListId(){
	return displayListId;
}