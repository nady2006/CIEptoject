#include "Plane.h"
#include "Game.h"
#include <string>
#include "GameConfig.h"
#include <iostream>
using namespace std;
plane::plane(Game* r_pGame, point ref, double s, color fc, color bc,int sp) :GameObject(r_pGame, ref, s, fc, bc)
{ 
    width = 1194 * s;
    hight = 1560 * s;
    speed = sp;
    stype = "plane";
    stime = time(NULL);
}
void plane::draw() const
{
    window* t = pGame->getWind();
    const int ix = RefPoint.x;
    const int iy = RefPoint.y;
    // Main bodiy (green)
    t->SetPen(BLACK);
    t->SetBrush(GREEN);
    int ixPoints1[] = { ix, ix + s * 215, ix + s * 260, ix + s * 595, ix + s * 595, ix + s * 560, ix + s * 560, ix + s * 225, ix + s * 175, ix,
    ix - s * 175, ix - s * 225, ix - s * 560, ix - s * 560, ix - s * 595, ix - s * 595, ix - s * 260, ix - s * 215
};
    int iyPoints1[] = { iy - s * 705, iy - s * 500, iy - s * 320, iy, iy + s * 100, iy + s * 140, iy + s * 20, iy - s * 285, iy - s * 465, iy - s * 640,
                        iy - s * 465, iy - s * 285, iy + s * 20, iy + s * 140, iy + s * 100, iy, iy - s * 320, iy - s * 500 };
    t->DrawPolygon(ixPoints1, iyPoints1, 18, FILLED);

    t->SetBrush(GREENYELLOW);
    int ixPoints2[] = { ix, ix + s * 175, ix + s * 225, ix + s * 560, ix + s * 560, ix + s * 535, ix + s * 370, ix + s * 240, ix + s * 445, ix + s * 405,
                        ix + s * 205, ix, ix - s * 240, ix - s * 445, ix - s * 405, ix - s * 250, ix - s * 370, ix - s * 535, ix - s * 560, ix - s * 560,
                        ix - s * 225, ix - s * 175 };
    int iyPoints2[] = { iy - s * 640, iy - s * 465, iy - s * 285, iy + s * 20, iy + s * 140, iy + s * 160, iy + s * 205, iy + s * 130, iy + s * 320, iy + s * 415,
                        iy + s * 445, iy - s * 340, iy + s * 445, iy + s * 415, iy + s * 320, iy + s * 130, iy + s * 205, iy + s * 160, iy + s * 140, iy + s * 20,
                        iy - s * 285, iy - s * 465 };
    t->DrawPolygon(ixPoints2, iyPoints2, 22, FILLED);

    t->SetBrush(GREEN);
    int ixPoints3[] = { ix, ix + s * 35, ix + s * 255, ix + s * 215, ix + s * 60, ix, ix - s * 60, ix - s * 215, ix - s * 255, ix - s * 35 };
    int iyPoints3[] = { iy - s * 825, iy - s * 160, iy + s * 25, iy + s * 270, iy + s * 270, iy + s * 500, iy + s * 270, iy + s * 270, iy + s * 25, iy - s * 160 };
    t->DrawPolygon(ixPoints3, iyPoints3, 10, FILLED);
    
    t->SetBrush(GREENYELLOW);
    int ixPoints4[] = { ix + s * 70, ix + s * 160, ix + s * 145, ix + s * 75, ix + s * 60, ix, ix - s * 60, ix - s * 75, ix - s * 145, ix - s * 160, ix - s * 70 };
    int iyPoints4[] = { iy - s * 825, iy + s * 275, iy + s * 360, iy + s * 355, iy + s * 275, iy - s * 825, iy + s * 275, iy + s * 355, iy + s * 360, iy + s * 275, iy - s * 825 };
    t->DrawPolygon(ixPoints4, iyPoints4, 11, FILLED);

    t->SetBrush(GREY);
    int ixPoints5[] = { ix + s * 145, ix + s * 140, ix + s * 85, ix + s * 75 };
    int iyPoints5[] = { iy + s * 360, iy + s * 405, iy + s * 405, iy + s * 355 };
    t->DrawPolygon(ixPoints5, iyPoints5, 4, FILLED);

    t->SetBrush(GREY);
    int ixPoints6[] = { ix - s * 75, ix - s * 85, ix - s * 140, ix - s * 145 };
    int iyPoints6[] = { iy + s * 355, iy + s * 405, iy + s * 405, iy + s * 360 };
    t->DrawPolygon(ixPoints6, iyPoints6, 4, FILLED);

    t->SetBrush(GREY);
    int ixPoints7[] = { ix, ix + s * 70, ix - s * 70 };
    int iyPoints7[] = { iy - s * 1060, iy - s * 825, iy - s * 825 };
    t->DrawPolygon(ixPoints7, iyPoints7, 3, FILLED);

    t->SetBrush(YELLOW);
    t->DrawCircle(ix + s * 405, iy + s * 60, s * 2 * 35, FILLED);
    t->DrawCircle(ix - s * 405, iy + s * 60, s * 2 * 35, FILLED);
    t->DrawCircle(ix + s * 290, iy + s * 330, s * 2 * 20, FILLED);
    t->DrawCircle(ix - s * 290, iy + s * 330, s * 2 * 20, FILLED);

}

void plane::move(char c)
{
        switch (c) {
        case 'a':
        case 'A':  // A key - move left
            // Prevent moving too far left (into the left green rectangle)
            if (RefPoint.x >= 200)
                RefPoint.x -= speed;
            break;
        case 'd':
        case 'D':  // D key - move right
            // Prevent moving too far right (into the right green rectangle)
            if (RefPoint.x + 595 * s * 2 < config.windWidth - 200)
                RefPoint.x += speed;
            break;
        case 'w':
        case 'W':
            speed +=10;
            break;
        case 's':
        case 'S':
            speed -=10;
            break;
    }
}

void plane::collisionAction(GameObject* other)
{
}

void plane::save(string f)
{
    ofstream OutFile;
    OutFile.open(f);
    OutFile << "plane " << RefPoint.x << " " << RefPoint.y << " " << s << endl;
    OutFile.close();
}

void plane::load(string f)
{
    ifstream Infile;
    Infile.open(f);
    bool label;
    Infile >> label; // Read the first word ("bridge")

    if (label = "plane")
    {
        Infile >> RefPoint.x >> RefPoint.y >> s;
    }
}


