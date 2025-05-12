#include "bridge.h"
#include "Game.h"

bridge::bridge(Game* r_pGame, point ref, double s, color fc, color bc) :GameObject(r_pGame, ref, s, fc, bc)
{
	width = 600 * s;
	hight = 150 * s;
	stype = "bridge";
}

void bridge::draw()const
{
	window* t = pGame->getWind();
	const int ix = RefPoint.x;
	const int iy = RefPoint.y;
	t->SetBrush(SLATEGREY);
	t->SetPen(BLACK);
	t->DrawRectangle(ix, iy, ix +s* 600,iy +s* 150);
	t->SetPen(YELLOW, 3);
	t->DrawLine(ix, iy +s* 75, ix +s* 200, iy + s*75);
	t->DrawLine(ix + s*250, iy +s* 75, ix +s* 550,iy +s* 75);
}
void bridge::move()
{
}

void bridge::collisionAction(GameObject* other)
{
	if (other->get_type() == "Bullet") {
		pGame->getstatusBar()->increment_status(3, 500);
	}
	else if (other->get_type() == "plane") {
		pGame->getstatusBar()->decrement_status(0, 1);
	}
}

void bridge::save(string f)
{
	ofstream OutFile;
	OutFile.open(f);
	OutFile << "bridge " << RefPoint.x << " " << RefPoint.y << " " << s << endl;
	OutFile.close();
}

void bridge::load(string f)
{
	ifstream Infile;
	Infile.open(f);
	bool label;
	Infile >> label; // Read the first word ("bridge")

	if (label = "bridge")
	{
		Infile >> RefPoint.x >> RefPoint.y >> s;
	}
}
