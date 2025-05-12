#include "enemy.h"
#include <iostream>


enemy::enemy(Game* r_pGame, point ref, double s, color fc, color bc) :GameObject(r_pGame, ref, s, fc, bc)
{
	speed = 0;
	enemy_num = 1;
}

void enemy::set_speed(int x)
{
	speed = x;
}

int enemy::get_speed() const
{
	return speed;
}

int enemy::get_enemy_num() const
{
	return enemy_num;
}

void enemy::set_enemy_num()
{
	//generates random number based on the speed , as the speed grows the numbers get bigger
	//srand(time(0));//should be in main (dont forget !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!)
	int max = (speed / 5);
	int min = (speed / 10);
	int range = (max - min + 1);
	enemy_num = min + (rand() % range);

}

void enemy::set_enemy_x(int max, int min)
{
	//generates random x coordinate between x_min and x_max based on the background
	int range = (max - min + 1);
	RefPoint.x = min + (rand() % range);

}

int enemy::get_enemy_x() const
{
	return RefPoint.x;
}

void enemy::set_enemy_y(int max, int min)
{
	//generates random y coordinate between y_min and y_max based on the background
	
	int range = (max - min + 1);
	RefPoint.y = min + (rand() % range);

}

int enemy::get_enemy_y() const
{
	return RefPoint.y;

}

void enemy::set_enemy_type()
{
	//generate random type for example, 1 being ship 0 being helicopter .
	int x = 1 + (rand() % 14);
	if (x % 2 == 0) {
		type = 0;
	}
	else type = 1;

}
void enemy::set_position(int x, int y)
{
	RefPoint.x = x;
	RefPoint.y = y;
}

int enemy::get_enemy_type()
{
	return type;
}

