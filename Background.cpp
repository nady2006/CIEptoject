#include "Background.h"

Background::Background(int width) : greenRectWidth(width) {}

int Background::draw(window& kimo, int windowWidth, int windowHeight) {
    // left green rectangle
    kimo.SetPen(BLACK);
    kimo.SetBrush(DARKGREEN);
    kimo.DrawRectangle(0, 0, greenRectWidth, windowHeight);

    // right green rectangle
    kimo.DrawRectangle(windowWidth - greenRectWidth, 0, windowWidth, windowHeight);

    // center blue rectangle 
    kimo.SetPen(BLACK);
    kimo.SetBrush(BLUE);
    kimo.DrawRectangle(greenRectWidth, 0, windowWidth - greenRectWidth, windowHeight);

    return greenRectWidth; // Return width of the green rectangle
}

int Background::getGreenRectWidth() const {
    return greenRectWidth;
}
Background:: draw_motion(window& w) {
    int y1 = 50;
    int y2 = 150;
    int y3 = 250;
    do {
        draw_background(w, w.GetWidth(), w.GetHeight());
        // conseder the circles as trees or buildings 
        w.SetBrush(RED);
        w.SetPen(BLACK);
        w.DrawCircle(50, y1, 20);
        w.DrawCircle(w.GetWidth()-50, y1, 20);
        w.SetBrush(YELLOW);
        w.SetPen(BLACK);
        w.DrawCircle(50, y2, 20);
        w.DrawCircle(w.GetWidth() - 50, y2, 20); w.SetBrush(YELLOW);
        w.SetBrush(BLUE);
        w.SetPen(BLACK);
        w.DrawCircle(50, y3, 20);
        w.DrawCircle(w.GetWidth() - 50, y3, 20);
        y1++, y2++, y3++;
        Pause(30);
        if (y1 + 20 == w.GetHeight()){
            y1 = 50;
        }
        if (y2 + 20 == w.GetHeight()) {
            y2 = 150;
        }
        if (y3 + 20 == w.GetHeight()) {
            y3 = 250;
        }
    } while (true);
     
}
