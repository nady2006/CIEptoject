#include "helocopter.h"
#include "Game.h"
#include<iostream>

helocopter::helocopter(Game* r_pGame, point ref, double s, color fc, color bc) :enemy(r_pGame, ref, s, fc, bc)
{
	width = 1090 * s;
	hight = 455 * s;
	stype = "helocopter";
}

void helocopter::draw()const
{
	window* t = pGame->getWind();
	const int ix = RefPoint.x;
	const int iy = RefPoint.y;
	//cout << "h->"  << ix << "," << iy << endl;
	t->SetPen(BLACK, 1);
	t->SetBrush(MEDIUMSEAGREEN);
	int XPoints3[] = {
	ix + s * 110, ix + s * 185, ix + s * 435, ix + s * 460, ix + s * 495,
	ix + s * 500, ix + s * 715, ix + s * 755, ix + s * 790, ix + s * 845,
	ix + s * 865, ix + s * 865, ix + s * 910, ix + s * 910, ix + s * 790,
	ix + s * 520, ix + s * 410, ix + s * 365, ix + s * 85,  ix + s * 75
	};

	int YPoints3[] = {
		iy + s * 165, iy + s * 240, iy + s * 245, iy + s * 220, iy + s * 220,
		iy + s * 215, iy + s * 215, iy + s * 240, iy + s * 240, iy + s * 295,
		iy + s * 295, iy + s * 360, iy + s * 360, iy + s * 380, iy + s * 400,
		iy + s * 380, iy + s * 310, iy + s * 310, iy + s * 270, iy + s * 180
	};
	t->DrawPolygon(XPoints3, YPoints3, 20, FILLED);

	t->SetPen(DARKGREEN, 8);
	t->DrawLine(ix + s * 580, iy + s * 200, ix + s * 580, iy + s * 65, FRAME);
	t->DrawLine(ix + s * 555, iy + s * 135, ix + s * 605, iy + s * 135, FRAME);

	t->SetPen(DARKGREEN, 12);
	t->DrawLine(ix + s * 125, iy + s * 200, ix + s * 165, iy + s * 130, FRAME);
	t->DrawLine(ix + s * 120, iy + s * 220, ix + s * 185, iy + s * 260, FRAME);
	t->DrawLine(ix + s * 95, iy + s * 215, ix + s * 55, iy + s * 285, FRAME);
	t->DrawLine(ix + s * 100, iy + s * 195, ix + s * 30, iy + s * 150, FRAME);

	t->SetPen(BLACK, 1);
	t->SetBrush(BLACK);
	t->DrawCircle(ix + s * 570, iy + s * 420, s * 40, FILLED);
	t->DrawCircle(ix + s * 865, iy + s * 405, s * 30, FILLED);
	t->DrawCircle(ix + s * 110, iy + s * 207, s * 30, FILLED);

	t->SetBrush(GREEN);
	t->DrawCircle(ix + s * 110, iy + s * 207, s * 10, FILLED);

	t->SetBrush(DARKGREEN);
	int XPoints4[] = { ix + s * 500, ix + s * 650, ix + s * 625, ix + s * 510 };
	int YPoints4[] = { iy + s * 215, iy + s * 215, iy + s * 195, iy + s * 195 };
	t->DrawPolygon(XPoints4, YPoints4, 4, FILLED);

	t->SetBrush(DARKGREEN);
	int XPoints5[] = { ix + s * 865, ix + s * 910, ix + s * 910, ix + s * 865 };
	int YPoints5[] = { iy + s * 295, iy + s * 330, iy + s * 360, iy + s * 360 };
	t->DrawPolygon(XPoints5, YPoints5, 4, FILLED);

	t->SetBrush(BLACK);
	int XPoints6[] = { ix + s * 365, ix + s * 410, ix + s * 520, ix + s * 790, ix + s * 490 };
	int YPoints6[] = { iy + s * 310, iy + s * 310, iy + s * 380, iy + s * 400, iy + s * 400 };
	t->DrawPolygon(XPoints6, YPoints6, 5, FILLED);

	t->SetBrush(DARKGREEN);
	int XPoints1[] = { ix + s * 560, ix + s * 600, ix + s * 600, ix + s * 580, ix + s * 560 };
	int YPoints1[] = { iy + s * 75,  iy + s * 75,  iy + s * 90,  iy + s * 100, iy + s * 90 };
	t->DrawPolygon(XPoints1, YPoints1, 5, FILLED);

	t->SetBrush(GREEN);
	int XPoints2[] = {
		ix + s * 90,  ix + s * 580, ix + s * 1065, ix + s * 1050, ix + s * 655,
		ix + s * 645, ix + s * 580,  ix + s * 510,  ix + s * 505,  ix + s * 105
	};
	int YPoints2[] = {
		iy + s * 85,  iy + s * 110, iy + s * 170,  iy + s * 190,  iy + s * 140,
		iy + s * 130, iy + s * 115, iy + s * 115,  iy + s * 125,  iy + s * 110
	};
	t->DrawPolygon(XPoints2, YPoints2, 10, FILLED);

	t->SetBrush(PALEGREEN);
	int XPoints7[] = { ix + s * 650, ix + s * 715, ix + s * 755, ix + s * 755, ix + s * 650 };
	int YPoints7[] = { iy + s * 215, iy + s * 215, iy + s * 240, iy + s * 360, iy + s * 360 };
	t->DrawPolygon(XPoints7, YPoints7, 5, FILLED);

	t->SetBrush(SKYBLUE);
	int XPoints8[] = { ix + s * 770, ix + s * 795, ix + s * 835, ix + s * 765 };
	int YPoints8[] = { iy + s * 250, iy + s * 250, iy + s * 290, iy + s * 290 };
	t->DrawPolygon(XPoints8, YPoints8, 4, FILLED);

	t->DrawRectangle(ix + s * 560, iy + s * 250, ix + s * 640, iy + s * 290);
	t->DrawRectangle(ix + s * 665, iy + s * 250, ix + s * 745, iy + s * 290);
}


void helocopter::move()
{
	int speedValue = 20;

	if (movingRight) {
		RefPoint.x += speedValue;
		if (RefPoint.y < 450)
			RefPoint.y += speedValue / 3;
		if (RefPoint.x >= 1000) {
			movingRight = false;  // Change direction to left
		}
	}
	else {
		RefPoint.x -= speedValue;
		if (RefPoint.y > 0)
			RefPoint.y -= speedValue / 5;
		if (RefPoint.x <= 200) {
			movingRight = true;  // Change direction to right
		}
	}
}

void helocopter::collisionAction(GameObject* other)
{
	if (other->get_type() == "Bullet") {
		pGame->getstatusBar()->increment_status(3, 60);
	}
	else if (other->get_type() == "plane") {
		pGame->getstatusBar()->decrement_status(0, 1);
	}

}

void helocopter::save(string f)
{
	ofstream OutFile;
	OutFile.open(f);
	OutFile << "helocopter " << RefPoint.x << " " << RefPoint.y << " " << s << endl;
	OutFile.close();
}


void helocopter::load(string f)
{
	ifstream Infile;
	Infile.open(f);
	bool label;
	Infile >> label; // Read the first word ("bridge")

	if (label = "helocopter")
	{
		Infile >> RefPoint.x >> RefPoint.y >> s;
	}
}


