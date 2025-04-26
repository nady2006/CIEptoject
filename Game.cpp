#include "Game.h"

Game::Game(window& w) : gameWindow(w), moveStep(50), isRunning(true) {
    // Initialize window dimensions
    windowWidth = gameWindow.GetWidth();
    windowHeight = gameWindow.GetHeight();

    // Initialize background
    background = Background(150);

    // Initialize toolbar
    toolbar = Toolbar();

    // Calculate plane initial position
    double planeScale = 0.1;
    int planeY = (windowHeight - planeScale * 500 - 20) / planeScale;
    int planeX = (windowWidth) / (2 * planeScale);

    // Create plane
    plane = new Plane(planeX, planeY, planeScale);
}

Game::~Game() {
    delete plane;
}

void Game::run() {
    gameWindow.FlushKeyQueue();
    gameWindow.SetBuffering(true);

    char cKeyData;
    keytype kType;

    // Game loop
    while (isRunning) {
        // Handle input
        kType = gameWindow.GetKeyPress(cKeyData);

        if (kType == ASCII) {
            switch (cKeyData) {
            case 'a':
            case 'A':  // A key - move left
                plane->moveLeft(moveStep, background.getGreenRectWidth());
                break;
            case 'd':
            case 'D':  // D key - move right
                plane->moveRight(moveStep, windowWidth - background.getGreenRectWidth());
                break;
            case 27:   // ESC key - exit game
                isRunning = false;
                break;
            }
        }

        // Draw game elements background first to not hide plane
        background.draw(gameWindow, windowWidth, windowHeight);
        plane->draw(gameWindow);
        toolbar.draw(gameWindow, windowWidth);
        // Update screen
        gameWindow.UpdateBuffer();
    }

    gameWindow.SetBuffering(false);
}
