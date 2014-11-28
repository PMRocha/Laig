#include "ScenePatch.h"

ScenePatch::ScenePatch(int order,int partsU, int partsV,string compute)
{
	this->order=order;
	this->partsU=partsU;
	this->partsV=partsV;
	this->compute=compute;
	index=0;


	if (compute.compare("fill") == 0)
	{
		drawmode=GL_FILL;
	}
	else if (compute.compare("line") == 0)
	{
		drawmode=GL_LINE;
	}
	else if (compute.compare("point") == 0)
	{
		drawmode=GL_POINT;
	}

	//textures
	if(order==1)
	{
		texturePoints1[0][0]=0;
		texturePoints1[0][1]=0;
		
		texturePoints1[1][0]=1;
		texturePoints1[1][1]=0;
		
		texturePoints1[2][0]=0;
		texturePoints1[2][1]=1;
		
		texturePoints1[3][0]=1;
		texturePoints1[3][1]=1;
	}

	else if(order==2)
	{
		texturePoints2[0][0]=0;
		texturePoints2[0][1]=0;
		
		texturePoints2[1][0]=0,5;
		texturePoints2[1][1]=0;
		
		texturePoints2[2][0]=1;
		texturePoints2[2][1]=0;
		
		texturePoints2[3][0]=0;
		texturePoints2[3][1]=0,5;
		
		texturePoints2[4][0]=0,5;
		texturePoints2[4][1]=0,5;
		
		texturePoints2[5][0]=1;
		texturePoints2[5][1]=0,5;
		
		texturePoints2[6][0]=0;
		texturePoints2[6][1]=1;
		
		texturePoints2[7][0]=0,5;
		texturePoints2[7][1]=1;
		
		texturePoints2[8][0]=1;
		texturePoints2[8][1]=1;
	}

	else if(order==3)
	{
		texturePoints3[0][0]=0;
		texturePoints3[0][1]=0;
		
		texturePoints3[1][0]=1/3.0;
		texturePoints3[1][1]=0;
		
		texturePoints3[2][0]=2/3.0;
		texturePoints3[2][1]=0;
		
		texturePoints3[3][0]=1;
		texturePoints3[3][1]=0;
		
		texturePoints3[4][0]=0;
		texturePoints3[4][1]=1/3.0;
		
		texturePoints3[5][0]=1/3.0;
		texturePoints3[5][1]=1/3.0;
		
		texturePoints3[6][0]=2/3.0;
		texturePoints3[6][1]=1/3.0;
	
		texturePoints3[7][0]=1;
		texturePoints3[7][1]=1/3.0;
		
		texturePoints3[8][0]=0;
		texturePoints3[8][1]=2/3.0;
		
		texturePoints3[9][0]=1/3.0;
		texturePoints3[9][1]=2/3.0;
		
		texturePoints3[10][0]=2/3.0;
		texturePoints3[10][1]=2/3.0;
		
		texturePoints3[11][0]=1;
		texturePoints3[11][1]=2/3.0;
		
		texturePoints3[12][0]=0;
		texturePoints3[12][1]=1;
		
		texturePoints3[13][0]=1/3.0;
		texturePoints3[13][1]=1;
		
		texturePoints3[14][0]=2/3.0;
		texturePoints3[14][1]=1;
		
		texturePoints3[15][0]=1;
		texturePoints3[15][1]=1;
	}
}

ScenePatch::~ScenePatch(void)
{
}

void ScenePatch::draw()
{

	if(order==1)
	{
		glMap2f(GL_MAP2_VERTEX_3, 0.0, 1.0, 3, 2,  0.0, 1.0, 6, 2,  &controlPoints1[0][0]);
		glMap2f(GL_MAP2_TEXTURE_COORD_2,  0.0, 1.0, 2, 2,  0.0, 1.0, 4, 2,  &texturePoints1[0][0]);
		glEnable(GL_MAP2_VERTEX_3);
		glEnable(GL_AUTO_NORMAL);
		glEnable(GL_MAP2_TEXTURE_COORD_2);
		glMapGrid2f(partsU, 0.0,1.0, partsV, 0.0,1.0); 
		glEvalMesh2(drawmode, 0,partsU, 0,partsV);	
	}

	else if(order==2)
	{
		glMap2f(GL_MAP2_VERTEX_3, 0.0, 1.0, 3, 3,  0.0, 1.0, 9, 3,  &controlPoints2[0][0]);
		glMap2f(GL_MAP2_TEXTURE_COORD_2, 0.0, 1.0, 2, 3,  0.0, 1.0, 6, 3, &texturePoints2[0][0]);
		glEnable(GL_MAP2_VERTEX_3);
		glEnable(GL_AUTO_NORMAL);
		glEnable(GL_MAP2_TEXTURE_COORD_2);
		glMapGrid2f(partsU, 0.0,1.0, partsV, 0.0,1.0); 
		glEvalMesh2(drawmode, 0,partsU, 0,partsV);	
		
	}

	else if(order==3)
	{
		glMap2f(GL_MAP2_VERTEX_3, 0.0, 1.0, 3, 4,  0.0, 1.0, 12, 4,  &controlPoints3[0][0]);
		glMap2f(GL_MAP2_TEXTURE_COORD_2,  0.0, 1.0, 2, 4,  0.0, 1.0, 8, 4,  &texturePoints3[0][0]);
		glEnable(GL_MAP2_VERTEX_3);
		glEnable(GL_AUTO_NORMAL);
		glEnable(GL_MAP2_TEXTURE_COORD_2);
		glMapGrid2f(partsU, 0.0,1.0, partsV, 0.0,1.0); 
		glEvalMesh2(drawmode, 0,partsU, 0,partsV);	
	}

}

void ScenePatch::addCntrPoint(float x,float y, float z)
{
	float cntr[3];

	cntr[0]=x;
	cntr[1]=y;
	cntr[2]=z;

	if(order==1)
	{
		controlPoints1[index][0]=cntr[0];
		controlPoints1[index][1]=cntr[1];
		controlPoints1[index][2]=cntr[2];
	}

	if(order==2)
	{
		controlPoints2[index][0]=cntr[0];
		controlPoints2[index][1]=cntr[1];
		controlPoints2[index][2]=cntr[2];
	}

	if(order==3)
	{
		controlPoints3[index][0]=cntr[0];
		controlPoints3[index][1]=cntr[1];
		controlPoints3[index][2]=cntr[2];
	}

	index++;
}