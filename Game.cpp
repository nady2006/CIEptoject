#include "Game.h"
#include "GameConfig.h"
#include "plane.h"
#include <ctime>
#include <iostream>
using namespace std;

Game::Game() : moveStep(50), isRunning(true), toolbar(this, intialPoint, config.windWidth, config.toolBarHeight), F1(this, {350,50}, .2, BLACK, BLACK) {
	//1 - Create the main window
	pWind = CreateWind(config.windWidth, config.windHeight, config.wx, config.wy);
	// Initialize window dimensions
	windowWidth = pWind->GetWidth();
	windowHeight = pWind->GetHeight();

	// Initialize background
	ptrbackground = new Background(this,intialPoint,1.0,config.windWidth,config.playingAreaHeight);
	ptrhelo=new helocopter (this, { 3000, 100 }, 0.1, RED, BLACK);
	// Initialize toolbar
	// Initialize toolbar
	// toolbar = Toolbar(this,{0,0},config.windWidth,config.toolBarHeight);
	// st = status_bar();
	double planeScale = 0.07;
	int planeY = 465;
	int planeX = 600;

	point p = { planeX,planeY };
	point pb = { planeX, planeY + 50 };
//	ptrbullet = new Bullet(this, pb, planeScale, GREEN, GREEN);
	ptrPlane = new plane(this, p, planeScale, GREEN, GREEN,10);

	
}
/*
Game::Game()
{
	//1 - Create the main window
	pWind = CreateWind(config.windWidth, config.windHeight, config.wx, config.wy);

	//2 - create and draw the toolbar
	createToolbar();

	//3 - create and draw the backgroundPlayingArea
	plane player1;


	//4- Create the Plane
	//TODO: Add code to create and draw the Plane

	//5- Create the Bullet
	//TODO: Add code to create and draw the Bullet

	//6- Create the enemies
	//TODO: Add code to create and draw enemies in random places

	//7- Create and clear the status bar
	clearStatusBar();
}*/

Game::~Game()
{
	for (auto e : enemies)
		delete e;
	enemies.clear();
	delete ptrPlane;
}

clicktype Game::getMouseClick(int& x, int& y) const
{

	return pWind->WaitMouseClick(x, y);	//Wait for mouse click

}

string Game::getSrting() const
{
	string Label;
	char Key;
	keytype ktype;
	pWind->FlushKeyQueue();
	while (1)
	{
		ktype = pWind->WaitKeyPress(Key);
		if (ktype == ESCAPE)	//ESCAPE key is pressed
			return "";	//returns nothing as user has cancelled label
		if (Key == 13)	//ENTER key is pressed
			return Label;
		if (Key == 8)	//BackSpace is pressed
			if (Label.size() > 0)
				Label.resize(Label.size() - 1);
			else
				Key = '\0';
		else
			Label += Key;
		printMessage(Label);
	}
}

window* Game::CreateWind(int w, int h, int x, int y) const
{
	window* pW = new window(w, h, x, y);
	pW->SetBrush(config.bkGrndColor);
	pW->SetPen(config.bkGrndColor, 1);
	pW->DrawRectangle(0, 0, w, h);
	return pW;
}

void Game::createToolbar() 
{

	gameToolbar = new Toolbar(this, {0,0}, 0, config.toolBarHeight);
	gameToolbar->draw();
}

void Game::clearStatusBar() const
{
	//Clear Status bar by drawing a filled rectangle
	pWind->SetPen(config.statusBarColor, 1);
	pWind->SetBrush(config.statusBarColor);
	pWind->DrawRectangle(0, config.windHeight - config.statusBarHeight, config.windWidth, config.windHeight);
}

void Game::move() {
	keytype ktInput;
	char cKeyData;
	window* t = this->getWind();
	ktInput = t->GetKeyPress(cKeyData);
	if (ktInput == ASCII) {
		switch (cKeyData) {
		case ' ':
		{
			Bullet* B1 = new Bullet(this, ptrPlane->getRefPoint(), 1, YELLOW, YELLOW);
			bullets.push_back(B1);
			break;
		}
		case 'a':
		case 'A':  // A key - move left
			// Prevent moving too far left (into the left green rectangle)
			ptrPlane->move('a');
			break;
		case 'd':
		case 'D':  // D key - move right
			// Prevent moving too far right (into the right green rectangle)
			ptrPlane->move('d');
			break;
		case 'w':
		case 'W':
			ptrPlane->move('w');
			break;
		case 's':
		case 'S':
			ptrPlane->move('s');
			break;
		case 'p':
		case 'P':
			isPaused = true;
			break;
		}
	}
}


void Game::Drawbullets() const {
	for (int i = 0;i < bullets.size();i++) {
		bullets[i]->draw();
		bullets[i]->move();
	}
}

void Game::cleanupbullets()
{
	for (int i = 0; i < bullets.size(); i++) {
		point p = bullets[i]->getRefPoint();
		if (p.y <= config.toolBarHeight) {
			bullets.erase(
				bullets.begin() + i
			);
		}
	}
}

void Game::deleteEnemy(enemy* E)
{
	for (int i = 0; i < enemies.size(); i++) {
		if (enemies[i] == E) {
			enemies.erase(
				enemies.begin() + i
			);
		}
	}
}

void Game::deletebullets(Bullet* B)
{
	for (int i = 0; i < bullets.size(); i++) {
		if (bullets[i] == B) {
			bullets.erase(bullets.begin() + i);
		}
	}
}


void Game::printMessage(string msg) const
{
	clearStatusBar();	//First clear the status bar

	pWind->SetPen(config.penColor, 50);
	pWind->SetFont(24, BOLD, BY_NAME, "Arial");
	pWind->DrawString(10, config.windHeight - (int)(0.85 * config.statusBarHeight), msg);

}

window* Game::getWind() const
{
	return pWind;
}

void Game::run() {
	pWind->FlushKeyQueue();
	pWind->SetBuffering(true);

	char cKeyData;
	keytype kType;
	//This function reads the position where the user clicks to determine the desired operation
	int x, y;
	bool isExit = false;

	//Change the title
	pWind->ChangeTitle("- - - - - - - - - - River Raid (CIE101-project) - - - - - - - - - -");


	// Game loop
	while (isRunning) {
		
		//printMessage("Ready...");
		//getMouseClick(x, y);	//Get the coordinates of the user click
		////if (gameMode == MODE_DSIGN)		//Game is in the Desgin mode
		////{
		//	//[1] If user clicks on the Toolbar
		//if (y >= 0 && y < config.toolBarHeight)
		//{
		//	isRunning = gameToolbar->handleClick(x, y);
		//}
		//}.
		
		// Draw game elements background first to not hide plane
		// increase frame counter
		frameCounter++;
		cleanupbullets();
		// Every 100 frames: generate more enemies and increase speed
    if (frameCounter % 100 == 0) {
        generateEnemies();
        gameSpeed += 5;  // Increase difficulty gradually
    }
		
	
	ptrbackground->draw_motion();
	move();
		//ptrbullet->move();
	ptrPlane->draw();
		Drawbullets();
		toolbar.draw();
		F1.draw();
		F1.move();
		// Update screen

		time_t now = time(NULL);
		time_t s = ptrPlane->gettime();
		st.decrement_status(1, abs(int(now - s) / 3));

		ptrhelo->draw();
		st.DrawMenuDemo(*pWind);
		frameCounter++;
		if (frameCounter >= generateInterval)
		{
			frameCounter = 0;
		    generateEnemies();
		}

		for (int i = 0; i < enemies.size(); i++) {
			enemies[i]->move();   
			enemies[i]->draw();
		}
		for (auto e : enemies) {
			if (ptrPlane->CollisionDetection(e)) {
				printMessage("GAME OVER");
				isRunning = false;
				break;
			}
		}

		for (auto e : enemies) {
			if (ptrPlane->CollisionDetection(e)) {
				printMessage("GAME OVER");
				isRunning = false;
				break;
			}

			for (int i = 0; i < bullets.size(); i++) {
				if (bullets[i]->CollisionDetection(e)) {
					bullets[i]->collisionAction(e);
					e->collisionAction(bullets[i]);
					
					deletebullets(bullets[i]);
					deleteEnemy(e);
				}
			}
		}


		if (isPaused) {
			toolbar.check();
		}

		pWind->UpdateBuffer();

	}

	pWind->SetBuffering(false);
}
/*
void Game::go() const
{
	//This function reads the position where the user clicks to determine the desired operation
	int x, y;
	bool isExit = false;

	//Change the title
	pWind->ChangeTitle("- - - - - - - - - - River Raid (CIE101-project) - - - - - - - - - -");

	do
	{
		printMessage("Ready...");
		getMouseClick(x, y);	//Get the coordinates of the user click
		//if (gameMode == MODE_DSIGN)		//Game is in the Desgin mode
		//{
			//[1] If user clicks on the Toolbar
		if (y >= 0 && y < config.toolBarHeight)
		{
			isExit = gameToolbar->handleClick(x, y);
		}
		//}

	} while (!isExit);
}*/
void Game::generateEnemies()
{
	enemy* generator = new helocopter(this, point{ 0, 0 }, 0.1, RED, BLACK);
	generator->set_speed(20);
	generator->set_enemy_num();
	int numEnemies = generator->get_enemy_num();
	delete generator;

	// Do NOT clear enemies here if you want to accumulate them
	// Only remove if off-screen or hit, etc.

	int spacing = 100;   // More spacing
	int startX = 50; // Further off-screen  


	for (int i = 0; i < numEnemies; ++i)
	{
		// Temporary enemy to determine the type
		enemy* temp = new helocopter(this, point{ 0, 0 }, 0.1, RED, BLACK);
		temp->set_enemy_type();
		int type = temp->get_enemy_type();
		delete temp;

		enemy* newEnemy = nullptr;
		if (type == 0)
			newEnemy = new helocopter(this, point{ 0, 0 }, 0.1, RED, BLACK);
		else
			newEnemy = new ship(this, point{ 0, 0 }, 0.1, BLUE, BLACK);
		if (enemies.size() % 10 == 0) {
			newEnemy = new EnemyJet(this, point{ 1500, 200 }, 0.3, RED, BLACK);
		}
		newEnemy->set_speed(20);

		int x = startX + (i + 1) * spacing * ((rand() % 3) + 1);
		int y = 10 + (rand() % 200);
		cout << "herre " << enemies.size() << endl;
		newEnemy->set_position(x, y);

		enemies.push_back(newEnemy);
	}
}
