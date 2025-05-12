#pragma once
#include "Drawable.h"
#include <fstream>
class GameObject : public Drawable
{
protected:
	color fillColor;	//game object fill color
	color borderColor;	//game object border color
	string stype;

public:
	GameObject(Game* r_pGame, point ref, double opj_size, color fc, color bc);
	virtual void draw()const =0; //for a game object to draw itself on the screen
	void setRefPoint(point p);
	bool CollisionDetection(GameObject* a);
	//-- The following functions should be supported by the shape class
	//-- It should be overridden by each inherited shape
	//-- Decide the parameters that you should pass to each function	

	virtual void move() = 0;		//Move the game object
	virtual void save(string f) = 0;	//Save the shape parameters to the file
	virtual void load(string f) = 0;	//Load the shape parameters to the file
	virtual void collisionAction(GameObject *other) = 0;    //action that should be performed upon collision
	string get_type()const { return stype; }

};

