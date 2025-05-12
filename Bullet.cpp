#include "Bullet.h"
#include "Game.h"
#include<iostream>

Bullet::Bullet(Game* r_pGame, point ref, double s = 1, color fc = BLACK, color bc = BLACK) : GameObject(r_pGame, ref, s, fc, bc)
{
    width = 5;
    hight = 10;
    stype = "Bullet";
}

void Bullet::draw() const
{
    window* t = pGame->getWind();
    t->SetBrush(fillColor);
    t->SetPen(fillColor);
    const int ix = RefPoint.x;
    const int iy = RefPoint.y;
    t->DrawRectangle(ix, iy, ix + 5, iy + 10);
}

void Bullet::move()
{
    RefPoint.y -= 10;
}

void Bullet::collisionAction(GameObject* other)
{
    if (other->get_type() == "ship") {
//        pGame->deletebullets(this);
    }    
}

void Bullet::save(string f)
{
  
}

void Bullet::load(string f)
{
  
}
