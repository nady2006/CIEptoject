#pragma once
#include "GameObject.h"
#include "enemy.h"
class EnemyJet :public enemy
{
    bool movingRight = false;
public:
    EnemyJet(Game* r_pGame, point ref, double s, color fc, color bc);
    void  draw() const override;
    void move()override;
    void collisionAction(GameObject* other) override;
    void save(string f)override;
    void load(string f)override;
};

