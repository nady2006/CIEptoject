#pragma once
#include "GameObject.h"
class enemy :public GameObject
{
    int speed;
    int enemy_num;
    int type;
public:
    enemy(Game* r_pGame, point ref, double s, color fc, color bc);
    void set_speed(int x);
    int get_speed()const;
    int get_enemy_num()const;
    void set_enemy_num();
    void set_enemy_x(int max, int min);
    int get_enemy_x() const;
    void set_enemy_y(int max, int min);
    int get_enemy_y() const;
    void set_enemy_type();
    void set_position(int x, int y);
     int get_enemy_type();
};

