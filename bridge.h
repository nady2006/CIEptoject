#pragma once
#include "GameObject.h"
class bridge :public GameObject
{
    bridge(Game* r_pGame, point ref, double s, color fc, color bc);
    void  draw() const override;
    void move()override;
    void collisionAction(GameObject* other) override;
    void save(string f)override;
    void load(string f)override;
};

