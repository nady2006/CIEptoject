#pragma once
#include "CMUgraphicsLib\CMUgraphics.h"
#include "Background.h"
#include "Plane.h"
#include "Toolbar.h"
#include "GameConfig.h"
#include "status_bar.h"
#include "GameObject.h"
#include "helocopter.h"
#include <vector>
#include "enemy.h"
#include "ship.h"
#include "Bullet.h"
#include "FuelDepot.h"
#include"EnemyJet.h"


class Game
{
private:
	Toolbar* gameToolbar;
	point intialPoint = { 0,0 };      // refrence to the toolbar intial point
	window* pWind;     // Reference to the main window
	Background*  ptrbackground;  // Background object
	plane* ptrPlane;           // Pointer to the plane object
	helocopter* ptrhelo;

	Bullet* ptrbullet;
	
	
	Toolbar toolbar;        // Toolbar object
	int windowWidth;        // Window width
	int windowHeight;       // Window height
	int moveStep;           // Movement size
	bool isRunning;         // To control the game loop
	status_bar st;          // the status bar
	vector<enemy*> enemies; // current enemies 
	vector<enemy*> allEnemies;  // All enemies ever created
	int gameSpeed = 20;        // Initial speed
	int frameCounter = 0;      // To control when to increase speed or spawn      
	int generateInterval = 300;
	string savedFile = "saved.txt"; //file which we save progress in 

	vector <Bullet*> bullets;

	bool isPaused = false;
	FuelDepot F1;

public:
	Game();
	~Game();
	void run();
	window* getWind() const;		//returns a pointer to the graphics window
	window* Game::CreateWind(int w, int h, int x, int y) const;


	clicktype getMouseClick(int& x, int& y) const; //Get coordinate where user clicks and returns click type (left/right)
	string getSrting() const;	 //Returns a string entered by the user

	void createToolbar();
	void clearStatusBar() const;	//Clears the status bar
	void generateEnemies();

	void printMessage(string msg) const;	//Print a message on Status bar

	void move();

	void Drawbullets() const;
	void cleanupbullets();
	status_bar* getstatusBar() { return &st; }
	vector <enemy*> getEnemy()const { return enemies; }
	void deleteEnemy(enemy* E);
	void deletebullets(Bullet* B);

	void setPause(bool P) { isPaused = P; }
	string getfile() const { return savedFile; }
	plane* getplane()const {return  ptrPlane; }
};

