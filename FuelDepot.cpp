#include "FuelDepot.h"
#include "Game.h"

#include <iostream>
using namespace std;

FuelDepot::FuelDepot(Game* r_pGame, point ref, double s=1, color fc=BLACK, color bc=BLACK) :GameObject(r_pGame, ref, s, fc, bc)
{
	//dumy numbers 
	width = 660 * s;
	hight = 240 * s;
}

void FuelDepot::draw()const
{
	window* t = pGame->getWind();
	const int ix = RefPoint.x;
	const int iy = RefPoint.y;

    t->SetBrush(RED);
    t->DrawRectangle(ix, iy + 15, ix + 40, iy + 30);
    t->SetBrush(BLUE);
    t->DrawRectangle(ix, iy, ix + 40, iy + 15);
    t->SetBrush(BLUE);
    t->DrawRectangle(ix, iy + 30, ix + 40, iy + 45);
    t->SetBrush(RED);
    t->DrawRectangle(ix, iy + 45, ix + 40, iy + 60);

    // Draw the word "FUEL" vertically
    t->SetFont(16, 1, ROMAN);
    t->SetPen(BLACK); // Set the pen color to black for the teixt
    t->DrawString(ix + 20, iy + 1, "F");   // Draw 'F'
    t->DrawString(ix + 20, iy + 16, "U"); // Draw 'U'
    t->DrawString(ix + 20, iy + 31, "E"); // Draw 'E'
    t->DrawString(ix + 20, iy + 46, "L"); // Draw 'L'
}
void FuelDepot::move()
{
    RefPoint.y += 4;
}

void FuelDepot::collisionAction(GameObject* other)
{
}

void FuelDepot::save(string f)
{
    ofstream OutFile;
    OutFile.open(f);
    OutFile << "fueldepot " << RefPoint.x << " " << RefPoint.y << " " << s << endl;
    OutFile.close();
}

void FuelDepot::load(string f)
{
    ifstream Infile;
    Infile.open(f);
    bool label;
    Infile >> label; // Read the first word ("bridge")

    if (label = "fueldepot")
    {
        Infile >> RefPoint.x >> RefPoint.y >> s;
    }
}

