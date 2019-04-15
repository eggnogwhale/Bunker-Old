#include <SFML/Graphics.hpp>
#include "InteractionSystem.h"
#include "Header.h"

////////////////////  INDEX  ////////////////////
//
//	Constructor
//		Setup of the mouse variables, and sprites
//
//
//
//
/////////////////////////////////////////////////

InteractionSystem::InteractionSystem() {

	//Sprite & Texture Loading
	mouseSprite.setSize(sf::Vector2f(10,10));
	mouseSprite.setOrigin(sf::Vector2f(5, 5));
	mouseSprite.setFillColor(sf::Color::Cyan);

	return;
}



void InteractionSystem::DrawMouse() {
	//Sets the mouse in the proper position
	mouseSprite.setPosition(sf::Vector2f(posX, posY));
	//Draws the mouse to the window
	WindowPass->draw(mouseSprite);


	return;
}



void InteractionSystem::MouseInteraction() {

	//Setting up the x position
	posX = sf::Mouse::getPosition(*WindowPass).x + PlayerPass->posX - 640;
	posY = sf::Mouse::getPosition(*WindowPass).y + PlayerPass->posY - 360;

	return;
}



void InteractionSystem::CheckWallInteraction() {

	//Getting approximate tile position of the mouse cursor
	tilePosX = (posX - (posX % 32)) / 32;
	tilePosY = (posY - (posY % 32)) / 32;

	//Trying to click on a wall
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {

		//Overlapping with a tree one
		if (WorldTilePass->WorldWallMap[tilePosX][tilePosY] == 1) {
			WorldTilePass->WorldWallMap[tilePosX][tilePosY] = 0;
			InventoryPass->AddItem(1, 1);
		}

		//Overlapping with a tree two
		if (WorldTilePass->WorldWallMap[tilePosX][tilePosY] == 2) {
			WorldTilePass->WorldWallMap[tilePosX][tilePosY] = 0;
			InventoryPass->AddItem(1, 1);
		}
	}

	//PLACEING TREE DEBUG
	if (sf::Mouse::isButtonPressed(sf::Mouse::Right)) {
		WorldTilePass->WorldTileMap[tilePosX][tilePosY] = 0;
	}
	if (sf::Mouse::isButtonPressed(sf::Mouse::Middle)) {
		WorldTilePass->WorldTileMap[tilePosX][tilePosY] = 1;
	}

	return;
}



void InteractionSystem::MouseFunctions() {
	MouseInteraction();
	CheckWallInteraction();
	DrawMouse();

	return;
}


void InteractionSystem::CheckHotbarInteraction() {

	

	return;
}