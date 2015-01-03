#ifndef _SCENEBOARD_H_
#define _SCENEBOARD_H_
#include "SceneObject.h"
#include "ScenePlane.h"
#include "SceneBlock.h"
#include "ScenePiece.h"
using namespace std;

class SceneBoard:public SceneObject
{
private:
	SceneBlock block;
	vector<ScenePiece> pieces;
public:
	SceneBoard();
	~SceneBoard(void);
	void draw(void);
	void drawPieces(void);
};

#endif