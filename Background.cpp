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
