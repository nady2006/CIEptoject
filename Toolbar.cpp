#include "Toolbar.h"
#include "GameConfig.h"
#include "game.h"
#include <iostream>
using namespace std;

ToolbarIcon::ToolbarIcon(Game* r_pGame, point r_point, int r_width, int r_height, string img_path) : Drawable(r_pGame, r_point, 0, r_width, r_height)
{
	image_path = img_path;
}

void ToolbarIcon::draw() const
{
	//draw image of this object
	window* pWind = pGame->getWind();
	pWind->DrawImage(image_path, RefPoint.x, RefPoint.y, width, hight);
}

RestartIcon::RestartIcon(Game* r_pGame, point r_point, int r_width, int r_height, string img_path) : ToolbarIcon(r_pGame, r_point, r_width, r_height, img_path)
{}

void RestartIcon::onClick()
{
	//TO DO: add code for restarting the game here
}

ExitIcon::ExitIcon(Game* r_pGame, point r_point, int r_width, int r_height, string img_path) : ToolbarIcon(r_pGame, r_point, r_width, r_height, img_path)
{}
void ExitIcon::onClick()
{
	//TO DO: add code for cleanup and game exit here
}
saveIcon::saveIcon(Game* r_pGame, point r_point, int r_width, int r_height, string img_path) : ToolbarIcon(r_pGame, r_point, r_width, r_height, img_path)
{}
void saveIcon::onClick()
{
	for (int i = 0; i < pGame->getEnemy().size(); i++) {
		pGame->getEnemy()[i]->save(pGame->getfile());
	}
	pGame->getplane()->save(pGame->getfile());

	//TO DO: add code for saving the game
}

loadIcon::loadIcon(Game* r_pGame, point r_point, int r_width, int r_height, string img_path) : ToolbarIcon(r_pGame, r_point, r_width, r_height, img_path)
{}
void loadIcon::onClick()
{
	for (int i = 0; i < pGame->getEnemy().size(); i++) {
		pGame->getEnemy()[i]->load(pGame->getfile());
	}
	pGame->getplane()->load(pGame->getfile());
	//TO DO: add code for loading the game
}




Toolbar::Toolbar(Game* r_pGame, point r_point, int r_width, int r_height) : Drawable(r_pGame, r_point, 0, r_width, r_height)
{
	//First prepare List of images for each icon
	//To control the order of these images in the menu, reoder them in enum ICONS above	
	iconsImages[ICON_RESTART] = "images\\RESTART.jpg";
	iconsImages[ICON_EXIT] = "images\\EXIT.jpg";
	iconsImages[ICON_SAVE] = "images\\save.jpg";
	iconsImages[ICON_LOAD] = "images\\load.jpg";


	iconsList = new ToolbarIcon * [ICON_COUNT];

	//For each icon in the tool bar create an object 
	iconsList[ICON_RESTART] = new RestartIcon(pGame, r_point, config.iconWidth, config.toolBarHeight, iconsImages[ICON_RESTART]);
	r_point.x += config.iconWidth;
	iconsList[ICON_EXIT] = new ExitIcon(pGame, r_point, config.iconWidth, config.toolBarHeight, iconsImages[ICON_EXIT]);
	r_point.x += config.iconWidth;
	iconsList[ICON_SAVE] = new ExitIcon(pGame, r_point, config.iconWidth, config.toolBarHeight, iconsImages[ICON_SAVE]);
	r_point.x += config.iconWidth;
	iconsList[ICON_LOAD] = new ExitIcon(pGame, r_point, config.iconWidth, config.toolBarHeight, iconsImages[ICON_LOAD]);

}

Toolbar::~Toolbar()
{
	for (int i = 0; i < ICON_COUNT; i++)
		delete iconsList[i];
	delete iconsList;
}

void Toolbar::draw() const
{
	for (int i = 0; i < ICON_COUNT; i++)
		iconsList[i]->draw();
	window* pWind = pGame->getWind();
	pWind->SetPen(BLACK, 3);
	pWind->DrawLine(0, config.toolBarHeight, pWind->GetWidth(), config.toolBarHeight);
}

bool Toolbar::handleClick(int x, int y)
{
	if (x > ICON_COUNT * config.iconWidth)	//click outside toolbar boundaries
		return false;


	//Check whick icon was clicked
	//==> This assumes that menu icons are lined up horizontally <==
	//Divide x co-ord of the point clicked by the icon width (int division)
	//if division result is 0 ==> first icon is clicked, if 1 ==> 2nd icon and so on

	int clickedIconIndex = (x / config.iconWidth);
	iconsList[clickedIconIndex]->onClick();	//execute onClick action of clicled icon

	if (clickedIconIndex == ICON_EXIT) return true;

	return false;

}

void Toolbar::check()
{
	while (true) {
		int x, y;
		pGame->getWind()->WaitMouseClick(x, y);
		if (y < config.toolBarHeight) {
			if (x < config.iconWidth) {}
			else if (x < config.iconWidth * 2) {
				// Exit
				iconsList[
					ICON_EXIT
				]->onClick();
			}
			else if (x < config.iconWidth * 3) {
				// SAVE
				iconsList[
					ICON_SAVE
				]->onClick();
			}
			else if (x < config.iconWidth * 4) {
				// LOAD
				iconsList[
					ICON_LOAD
				]->onClick();
			}
		}
		else {
			pGame->setPause(false);
			break;
		}
	}
}
