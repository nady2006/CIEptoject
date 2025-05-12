#include "Background.h"
#include "Game.h"
#include "CMUgraphicsLib\auxil.h"	// where Pause is found
#include "GameConfig.h"

Background::Background(Game* r_pGame, point ref, double opj_size, int w,int h):Drawable(r_pGame, ref,opj_size,w,h)
{
     y1 = 50;
     y2 = 150;
     y3 = 250;
     z = TRUE;
}

void Background::draw()const {
    // left green rectangle
    window* t = pGame->getWind();
    t->SetPen(BLACK);
    t->SetBrush(DARKGREEN);
    t->DrawRectangle(0, 0, config.greenRectangleWidth, hight);

    // right green rectangle
    t->DrawRectangle(width - config.greenRectangleWidth, 0, width, hight);

    // center blue rectangle 
    t->SetPen(BLACK);
    t->SetBrush(BLUE);
    t->DrawRectangle(config.greenRectangleWidth, 0, width - config.greenRectangleWidth, hight);

}

int Background::getGreenRectWidth() const {
    return config.greenRectangleWidth;
}
void Background::draw_motion() {
        draw();
        window* t = pGame->getWind();
        t->SetPen(BLACK);
        draw_tree(40, y1);
        draw_tree(t->GetWidth()-40, y1);
        draw_tree(50, y2);
        draw_tree(t->GetWidth() - 50, y2);
        draw_tree(60, y3);
        draw_tree(t->GetWidth() - 60, y3);
        y1 = y1 + 5;
        y2 = y2 + 5;
        y3 = y3 + 5;
        Pause(30);
        if (z)config.greenRectangleWidth++;
        if (!z)config.greenRectangleWidth--;
        if (config.greenRectangleWidth > 200) z = FALSE;
        if (config.greenRectangleWidth == 150)z = TRUE;
        if (y1 + 20 == t->GetHeight()){
            y1 = 50;
        }
        if (y2 + 20 == t->GetHeight()) {
            y2 = 50;
        }
        if (y3 + 20 == t->GetHeight()) {
            y3 = 50;
        }
     
}

void Background::draw_tree(int p_x, int p_y)
{
    window* t = pGame->getWind();
    t->SetBrush(GREEN);
    t->DrawTriangle(p_x,p_y,p_x+40,p_y+60,p_x-40,p_y+60);
    t->SetBrush(BROWN);
    t->DrawRectangle(p_x+10, p_y + 60, p_x -10, p_y + 100);
}
