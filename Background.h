#pragma once
#include "CMUgraphicsLib\CMUgraphics.h"
#include "Drawable.h"
class Background :public Drawable
{
private:
    int y1;
    int y2;
    int y3;
    bool z;

public:
    Background(Game* r_pGame, point ref, double opj_size, int w, int h);

    // Draw the background and return the green rectangle width
    void draw()const override;

    // Getter for green rectangle width
    int getGreenRectWidth() const;
    void draw_motion(); //animation 
    void draw_tree(int p_x,int p_y);
};
