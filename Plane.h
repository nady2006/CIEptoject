#pragma once
#include "CMUgraphicsLib\CMUgraphics.h"
#include <string>
#include "GameObject.h"
#include <ctime>


class plane :public GameObject
{
private:
    int speed;
    time_t stime;
public:
    plane(Game* r_pGame, point ref, double s, color fc, color bc, int sp);
    void  draw() const override;
    void move() override {};
    void move(char c);
    void collisionAction(GameObject* other) override;
    void save(string f)override;
    void load(string f)override;
    time_t gettime() const { return stime; }
};

