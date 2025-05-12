#pragma once
#include "GameObject.h"
#include "enemy.h"
class ship :public enemy
{
    bool movingup = false;
public:
    ship(Game* r_pGame, point ref, double s, color fc, color bc);
    void  draw() const override;
    void move()override;
    void collisionAction(GameObject* other) override;
    void save(string f)override;
    void load(string f)override;
};
