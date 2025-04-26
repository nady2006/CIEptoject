#pragma once
#include "CMUgraphicsLib\CMUgraphics.h"

// Configuration structure for game settings
struct GameConfig {
    // Window dimensions
    int windWidth = 900;
    int windHeight = 700;
    int wx = 5;
    int wy = 5;

    // Toolbar dimensions
    int toolBarHeight = 50;

    // Status bar dimensions
    int statusBarHeight = 50;

    // Colors
    color bkGrndColor = WHITE;
    color statusBarColor = LIGHTGRAY;
    color penColor = BLACK;
};

// Global configuration instance
extern GameConfig config;
