#pragma once
#include "CMUgraphicsLib\CMUgraphics.h"
class status_bar
{
protected:
    string* MenuItems;
    string s[4];
    int n[4];
    color colors[4];
    int size;
    int MenuItemWidth;
    int Height;
public:
    status_bar(int x = 4, int width = 50, int height = 50);
    void set_images(int i, string y);
    void set_status(int i, int x);
    void increment_status(int i, int x);
    void decrement_status(int i, int x);
    void DrawMenuDemo(window& w);
    ~status_bar();

};

