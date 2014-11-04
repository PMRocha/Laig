#include "Graph.h"


Graph::Graph(void)
{
}

void Graph::addNode(Node* node)
{
	this->nodes.push_back(node);
	/*
	if(node->getId()==rootid)
	{
	Node temp = *nodes[0];
	nodes[0]=node;
	nodes[nodes.size()-1]=&temp;
	}
	*/

}
Graph::~Graph(void)
{
}

void Graph::setRootId(string rootid)
{
	this->rootid=rootid;
}

void Graph::setNodeAppearance(int nodeIndex,string id,Appearance* appearance)
{
	
	nodes[nodeIndex]->setNodeAppearance(make_pair(id,appearance));
}

vector<Node*> Graph::getNodes()
{
	return nodes;
}

void Graph::calcPrimitives()
{
	unsigned int fatherInd;
	vector<string> sonIds;

	//searches for the father and gets sons
	for (fatherInd=0;fatherInd<nodes.size();fatherInd++)
	{
		if(rootid==nodes[fatherInd]->getId())
		{
			glLoadIdentity(); 
			glGetFloatv(GL_MODELVIEW_MATRIX, &nodes[fatherInd]->transMatrix[0]);
			break;
		}
	
	}

	sonIds=nodes[fatherInd]->getChildNodeIds();
	auxCalcPrimitives(sonIds);

}

void Graph::auxCalcPrimitives(vector<string> sonIds)
{
	//searches son position on vector
	unsigned int sonInd;
	vector<string> childrenIds;
	vector<Transformation* > trans;
	float matrixTrans [16];


	for (unsigned int j=0;j<sonIds.size();j++)
	{
		for (sonInd=0;sonInd<nodes.size();sonInd++)
		{
			if(sonIds[j]==nodes[sonInd]->getId())
			{
				
				//end of set appearance


				childrenIds=nodes[sonInd]->getChildNodeIds();


				
				//gets its transformations
				trans=nodes[sonInd]->getTransformations();

				//calcs matrix transformation of the son
	           
				glPushMatrix();
				for(unsigned int i=0;i<trans.size();i++)
					trans[i]->apply();
				glGetFloatv(GL_MODELVIEW_MATRIX, &matrixTrans[0]);
				glPopMatrix();


				nodes[sonInd]->setTransMatrix(matrixTrans);
				

				//if child is found
				if(childrenIds.size()>0)
				{
					auxCalcPrimitives(childrenIds);
				}

			}
		}
	}
}

string Graph::getRootId()
{
	return rootid;
}

void Graph::setChildDisplay(){
	for(int i=0; i<nodes.size(); i++)
	{
		if(nodes[i]->getId()==rootid)
			depthBoolSet(nodes[i],nodes[i]->getDisplayList());
	}
}

void Graph::depthBoolSet(Node* node, bool fatherBool){

	vector<string> children = node->getChildNodeIds(); 
	
	for(int i=0; i<children.size();i++){
		for(int j=0; j<nodes.size();j++){
			if(nodes[j]->getId()==children[i]){
				if(fatherBool)
					nodes[j]->setDisplayList(true);
				
				depthBoolSet(nodes[j],nodes[j]->getDisplayList());
			}
		}
	}
}

void Graph::setDisplayList(){
	GLuint ID=glGenLists(nodes.size());
	for(int i=0; i<nodes.size();i++){
		nodes[i]->createDisplayList(ID);
		ID++;
	}
}