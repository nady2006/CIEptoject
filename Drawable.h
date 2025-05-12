#pragma once
#include "CMUgraphicsLib\CMUgraphics.h"
#include "GameConfig.h"

class Game;     //forward declaration

struct point
{
	int x, y;
};


class Drawable
{
protected:
	point RefPoint;		//Each game object must have a reference point
	double s;
	int width, hight;
	Game* pGame;        //pointer to game object

public:
	Drawable(Game* r_pGame, point r_point, double opject_size,int w,int h);
	virtual void draw() const =0;
	point getRefPoint() const;
};

