#pragma once
#include "CMUgraphicsLib\CMUgraphics.h"
#include "Background.h"
#include "Plane.h"
#include "Toolbar.h"

class Game {
private:
    window& gameWindow;     // Reference to the main window
    Background background;  // Background object
    Plane* plane;           // Pointer to the plane object
    Toolbar toolbar;        // Toolbar object
    int windowWidth;        // Window width
    int windowHeight;       // Window height
    int moveStep;           // Movement size
    bool isRunning;         // To control the game loop

public:
    Game(window& w);

    // Destructor - Clean up dynamically allocated resources
    ~Game();

    // Run the game loop
    void run();
};
