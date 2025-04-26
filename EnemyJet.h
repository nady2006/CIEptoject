#pragma once
#include "GameObject.h"
class EnemyJet :
    public GameObject
{
private:
    int ix;
    int iy;
    double s;
public:
    EnemyJet(int x, int y, int size, Game* r_pGame, point ref, int r_width, int r_height, color fc, color bc);
    void draw_jet(window& t);
};

