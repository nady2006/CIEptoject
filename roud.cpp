#include "roud.h"

roud::roud(int x, int y, int size, Game* r_pGame, point ref, int r_width, int r_height, color fc, color bc) :GameObject(r_pGame, ref, r_width, r_height, fc, bc)
{
    ix = x;
    iy = y;
    s = size;
}


void roud::draw_roud(window& t)
{
	t.SetBrush(GREY);
	t.SetPen(BLACK);
	t.DrawRectangle(s * (ix), s * (iy), s * (ix + 600), s * (iy + 150));
	t.SetPen(YELLOW, 3);
	t.DrawLine(s * (ix), s * (iy + 75), s * (ix + 200), s * (iy + 75));
	t.DrawLine(s * (ix + 250), s * (iy + 75), s * (ix + 550), s * (iy + 75));
}
