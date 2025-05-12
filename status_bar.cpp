#include "status_bar.h"
#include <iostream>
using namespace std;

status_bar::status_bar(int x, int width, int height)
{
    size = x;
    MenuItems = new string[size];
    MenuItems[0] = "images\\life.jpg";
    MenuItems[1] = "images\\fuel.jpg";
    MenuItems[2] = "images\\speed.jpg";
    MenuItems[3] = "images\\xp.jpg";
    n[0] = 5;
    n[1] = 1000;
    n[2] = 5;
    n[3] = 0;
    colors[0] = RED;
    colors[1] = GREEN;
    colors[2] = YELLOW;
    colors[3] = BLUE;
    s[0] = "life";
    s[1] = "fuel";
    s[2] = "speed";
    s[3] = "xp";
    this->Height = height;
    MenuItemWidth = width;
}

void status_bar::set_images(int i, string y)
{
    MenuItems[i] = y;
}

void status_bar::set_status(int i, int x)
{
    n[i] = x;
}

void status_bar::increment_status(int i, int x)
{
    //n it the values for status bar 
    n[i] += x;
}

void status_bar::decrement_status(int i, int x)
{
    if (i == 1 && n[i]  <= 0) {
        exit(0);
    }
    n[i] -= x;
}

void status_bar::DrawMenuDemo(window& w)
{
    w.SetBrush(WHITE);
    w.DrawRectangle(0, w.GetHeight(), w.GetWidth(), w.GetHeight() - 100);
    // Draw bar icon one image at a time
  
    for (int i = 0; i < size; i++) {
        w.DrawImage(MenuItems[i], (i * MenuItemWidth) + (200 * i), w.GetHeight() - Height - 30, MenuItemWidth, Height);
        //Draw status text
        w.SetPen(colors[i]);
        w.SetFont(20, BOLD, MODERN);
        w.DrawString((i * MenuItemWidth) + (200 * i) + (MenuItemWidth), w.GetHeight() - Height, s[i]);
        //Draw status numbers
        int xi, yi;
        w.SetPen(BLACK);
        w.GetStringSize(xi, yi, s[i]);
        w.DrawInteger((i * MenuItemWidth) + (200 * i) + (MenuItemWidth + xi + 20), w.GetHeight() - Height, n[i]);

    }
     
    

}

status_bar::~status_bar()
{
    delete[] MenuItems;
    delete[] s;
    delete[] n;
    delete[] colors;

}


