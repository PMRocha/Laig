#include "Animation.h"


Animation::Animation(void)
{
	acum=0;
}

Animation::Animation(float span,std::string type, vector<Point> controlPoints)
{
	this->span=span;
	this->type=type;
	this->controlpoints=controlPoints;
	acum=0;
	index=0;

	lastPoint.x=0;
	lastPoint.y=0;
	lastPoint.z=0;

	currentPoint.x=0;
	currentPoint.y=0;
	currentPoint.z=0;

	timeDivided=(span/((float)controlPoints.size()*2));

	deltaPoint.x=(controlpoints[index].x-lastPoint.x)/(timeDivided*1000.0);
	deltaPoint.y=(controlpoints[index].y-lastPoint.y)/(timeDivided*1000.0);
	deltaPoint.z=(controlpoints[index].z-lastPoint.z)/(timeDivided*1000.0);

	hip=sqrt (pow(deltaPoint.x,2)+pow(deltaPoint.z,2));

	if(deltaPoint.x!=0||deltaPoint.z!=0){
		if(deltaPoint.x>=0)
			angle=acos(deltaPoint.z/hip);
		else
			angle=-acos(deltaPoint.z/hip);

		angle=(180*angle)/(acos(-1.0));


		deltaAngle=angle/(timeDivided*1000.0);


		//discovers the smallest angle
		if((angle-lastAngle)>180)
			deltaAngle-=360/(timeDivided*1000.0);
		else if((angle-lastAngle)<-180)
			deltaAngle+=360/(timeDivided*1000.0);


	}
	else
	{
		deltaAngle=0;
	}

	animAngle=false;
	lastAngle=angle;
	lastTime=0;
}

Animation::Animation(float span,std::string type, float centerX, float centerY, float centerZ, float radius, float startang, float rotang )
{
	
}

Animation::~Animation(void)
{
}

void Animation::print()
{
	cout << "Control Points: "<< endl;
	for(unsigned int i = 0;i<controlpoints.size();i++)
	{
		cout << "X: "<< controlpoints[i].x << " Y: " << controlpoints[i].y << " Z: " <<controlpoints[i].z << endl;
	}
}

void Animation::movement()
{	
	glTranslatef(currentPoint.x,currentPoint.y,currentPoint.z);
	glRotatef(lastAngle,0,1,0);
}

void Animation::update(unsigned long time)
{
	float tmp=time;
	float time1=time-lastTime;

	if(lastTime==0)
	{
		lastTime=tmp;
	}


	else
	{
		lastTime=tmp;
		if(acum<timeDivided&&!animAngle)
		{
			currentPoint.x+=time1*deltaPoint.x;
			currentPoint.y+=time1*deltaPoint.y;
			currentPoint.z+=time1*deltaPoint.z;

			
			acum+=time1/1000.0;
		}

		else if(acum<timeDivided&&animAngle)
		{
			

			lastAngle+=time1*deltaAngle;


			acum+=time1/1000.0;

			if(acum>=timeDivided)
			{
				acum=0;
				animAngle=false;
				lastAngle=angle;
			}
		}

		else if (index<controlpoints.size()-1)
		{
			lastPoint.x=controlpoints[index].x;
			lastPoint.y=controlpoints[index].y;
			lastPoint.z=controlpoints[index].z;
			index++;
			deltaPoint.x=(controlpoints[index].x-lastPoint.x)/(timeDivided*1000.0);
			deltaPoint.y=(controlpoints[index].y-lastPoint.y)/(timeDivided*1000.0);
			deltaPoint.z=(controlpoints[index].z-lastPoint.z)/(timeDivided*1000.0);
			hip=sqrt(pow(deltaPoint.x,2)+pow(deltaPoint.z,2));
			lastAngle=angle;



			if(deltaPoint.x!=0||deltaPoint.z!=0){
				if(deltaPoint.x>=0)
				{
					angle=acos(deltaPoint.z/hip);
				}
				else
				{
					angle=-acos(deltaPoint.z/hip);
				}
				angle=(180*angle)/(acos(-1.0));


				deltaAngle=((angle-lastAngle)/(timeDivided*1000.0));

				//discovers the smallest angle
				if((angle-lastAngle)>180)
					deltaAngle-=360/(timeDivided*1000.0);
				else if((angle-lastAngle)<-180)
					deltaAngle+=360/(timeDivided*1000.0);

			}

			else
			{
				deltaAngle=0;
			}
			animAngle=true;
			acum=0;
		}
	}



}