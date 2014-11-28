#ifndef GRAPH_H
#define GRAPH_H
#include <string>
#include <vector>
#include "Node.h"
using namespace std;
class Graph
{
private:
	string rootid;
	vector<Node*> nodes;
	void depthBoolSet(Node* node, bool fatherBool);
public:
	void addNode(Node* node);
	void setRootId(string rootId);
	void setNodeAppearance(int nodeIndex,string id,Appearance* appearance);
	void calcPrimitives();
	void auxCalcPrimitives(vector<string> sonIds);
	vector<Node*> getNodes();
	string getRootId();
	Graph(void);
	~Graph(void);
	void setChildDisplay();
	void setDisplayList();
};

#endif