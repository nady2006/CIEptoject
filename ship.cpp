#include "ship.h"
#include "Game.h"

ship::ship(Game* r_pGame, point ref, double s, color fc, color bc) :enemy(r_pGame, ref, s, fc, bc)
{
	width = 290 * s;
	hight = 105 * s;
	stype = "ship";
}

void ship::draw()const
{
	window* t = pGame->getWind();
	const int ix = RefPoint.x;
	const int iy = RefPoint.y;


	t->SetPen(BLACK, 8);
	t->DrawLine(ix + s * 1280, iy + s * 370, ix + s * 1370, iy + s * 360, FRAME);
	t->DrawLine(ix + s * 1530, iy + s * 450, ix + s * 1620, iy + s * 435, FRAME);
	t->SetPen(BLACK, 1);
	t->SetBrush(SLATEGREY);
	t->DrawTriangle(ix + s * 515, iy + s * 160, ix + s * 545, iy + s * 260, ix + s * 485, iy + s * 260, FILLED);
	t->DrawTriangle(ix + s * 850, iy + s * 200, ix + s * 880, iy + s * 300, ix + s * 825, iy + s * 300, FILLED);
	t->DrawTriangle(ix + s * 690, iy + s * 45, ix + s * 705, iy + s * 220, ix + s * 675, iy + s * 220, FILLED);
	t->DrawRectangle(ix + s * 1425, iy + s * 470, ix + s * 1525, iy + s * 485);
	t->DrawRectangle(ix + s * 1180, iy + s * 390, ix + s * 1270, iy + s * 405);

	t->SetBrush(GREY);
	t->DrawRectangle(ix + s * 470, iy + s * 260, ix + s * 560, iy + s * 345);
	t->DrawRectangle(ix + s * 650, iy + s * 210, ix + s * 735, iy + s * 345);
	t->DrawRectangle(ix + s * 810, iy + s * 300, ix + s * 895, iy + s * 345);
	t->DrawRectangle(ix + s * 605, iy + s * 65, ix + s * 780, iy + s * 120);
	t->DrawRectangle(ix + s * 1420, iy + s * 440, ix + s * 1530, iy + s * 470);
	t->DrawRectangle(ix + s * 1175, iy + s * 360, ix + s * 1285, iy + s * 390);

	t->SetBrush(GREY);
	int XPoints6[] = { ix + s * 1145, ix + s * 1325, ix + s * 1355, ix + s * 1355, ix + s * 1115, ix + s * 1115 };
	int YPoints6[] = { iy + s * 405, iy + s * 405, iy + s * 435, iy + s * 490, iy + s * 490, iy + s * 435 };
	t->DrawPolygon(XPoints6, YPoints6, 6, FILLED);

	t->SetBrush(SLATEGREY);
	int XPoints5[] = { ix + s * 465, ix + s * 900, ix + s * 925, ix + s * 925, ix + s * 445, ix + s * 445 };
	int YPoints5[] = { iy + s * 345, iy + s * 345, iy + s * 360, iy + s * 410, iy + s * 410, iy + s * 360 };
	t->DrawPolygon(XPoints5, YPoints5, 6, FILLED);
	t->SetBrush(BLACK);
	t->DrawRectangle(ix + s * 1000, iy + s * 180, ix + s * 1025, iy + s * 450);
	t->DrawRectangle(ix + s * 385, iy + s * 410, ix + s * 970, iy + s * 455);

	t->SetBrush(GREY);
	int XPoints4[] = { ix + s * 345, ix + s * 1085, ix + s * 1100, ix + s * 285 };
	int YPoints4[] = { iy + s * 440, iy + s * 440, iy + s * 490, iy + s * 495 };
	t->DrawPolygon(XPoints4, YPoints4, 4, FILLED);

	t->SetBrush(BLACK);
	int XPoints1[] = { ix + s * 20, ix + s * 1890, ix + s * 1860, ix + s * 40 };
	int YPoints1[] = { iy + s * 490, iy + s * 465, iy + s * 510, iy + s * 530 };
	t->DrawPolygon(XPoints1, YPoints1, 4, FILLED);

	t->SetBrush(GREY);
	int XPoints2[] = { ix + s * 40, ix + s * 1860, ix + s * 1825, ix + s * 105 };
	int YPoints2[] = { iy + s * 530, iy + s * 510, iy + s * 595, iy + s * 590 };
	t->DrawPolygon(XPoints2, YPoints2, 4, FILLED);

	t->SetBrush(RED);
	int XPoints3[] = { ix + s * 105, ix + s * 1825, ix + s * 1825, ix + s * 210 };
	int YPoints3[] = { iy + s * 590, iy + s * 595, iy + s * 640, iy + s * 640 };
	t->DrawPolygon(XPoints3, YPoints3, 4, FILLED);

	t->SetBrush(BLACK);
	t->DrawCircle(ix + s * 1730, iy + s * 550, s * 30, FILLED);
}
void ship::move()
{
	int speedValue = 20;

	if (movingup) {
		RefPoint.y += speedValue;
		if (RefPoint.y >= 400) {
			movingup = false;  
		}
	}
	else {
		RefPoint.y -= speedValue;
		if (RefPoint.y <= 0) {
			movingup = true;  
		}
	}
}

void ship::collisionAction(GameObject *other)
{
	if (other->get_type() == "Bullet") {
		pGame->getstatusBar()->increment_status(3, 30);
	}
	else if (other->get_type() == "plane") {
		pGame->getstatusBar()->decrement_status(0, 1);
	}
}


void ship::save(string f)
{
	ofstream OutFile;
	OutFile.open(f);
	OutFile << "ship " << RefPoint.x << " " << RefPoint.y << " " << s << endl;
	OutFile.close();
}

void ship::load(string f)
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


