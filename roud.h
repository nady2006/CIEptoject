#pragma once
#include "GameObject.h"
class roud :
    public GameObject
{
private:
    int ix;
    int iy;
    double s;
public:
    roud(int x, int y, int size, Game* r_pGame, point ref, int r_width, int r_height, color fc, color bc);
    void draw_roud(window& t);

};

