#include <SFML/Graphics.hpp>
#include "Header.h"
#include "InputSystem.h"
#include "CameraSystem.h"

////////////////////  INDEX  ////////////////////
//
//	Constructor
//		Doesn't really do anything
//
//	KeyboardInputSystem
//		Gets input from the keyboard and does
//		the action that is assigned to that key
//
//
/////////////////////////////////////////////////

InputSystem::InputSystem() {
	//Sprite & Texture Loading
	mouseSprite.setSize(sf::Vector2f(10,10));
	mouseSprite.setOrigin(sf::Vector2f(5, 5));
	mouseSprite.setFillColor(sf::Color::Cyan);
}


void InputSystem::DrawMouse() {
	//Sets the mouse in the proper position
	mouseSprite.setPosition(sf::Vector2f(posX, posY));
	//Draws the mouse to the window
	WindowPass->draw(mouseSprite);
}


void InputSystem::MouseInteraction() {

	//Setting up the x position
	posX = sf::Mouse::getPosition(*WindowPass).x + *CameraPass->posX - 640;
	posY = sf::Mouse::getPosition(*WindowPass).y + *CameraPass->posY - 360;

}


void InputSystem::CheckWallInteraction() {

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

}

void InputSystem::MouseFunctions() {
	MouseInteraction();
	CheckWallInteraction();
	CheckPlacingTile();
	DrawMouse();
}


void InputSystem::RunKeyboardInput() {

	//Moving Down
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) || sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
		PlayerPass->MoveDown();
	}

	//Moving Up
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
		PlayerPass->MoveUp();
	}

	//Moving Left
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
		PlayerPass->MoveLeft();
	}

	//Moving Right
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
		PlayerPass->MoveRight();
	}
    
	//Saving
	if ((sf::Keyboard::isKeyPressed(sf::Keyboard::S)) && 
		(sf::Keyboard::isKeyPressed(sf::Keyboard::LControl)) &&
		(sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)))
		SaveSystemPass->SaveMap();
	//Loading
	if ((sf::Keyboard::isKeyPressed(sf::Keyboard::O)) &&
		(sf::Keyboard::isKeyPressed(sf::Keyboard::LControl)) &&
		(sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)))
		SaveSystemPass->LoadMap();

	//Camera Shit
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1)) {
		CameraPass->SetCamera(&PlayerPass->posX,&PlayerPass->posY);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2)) {
		CameraPass->SetCamera(&CameraPass->sX,&CameraPass->sY);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num3)) {
		CameraPass->sX=PlayerPass->posX;
		CameraPass->sY=PlayerPass->posY;
		CameraPass->SetCamera(&CameraPass->sX,&CameraPass->sY);
	}
}


void InputSystem::CheckPlacingTile() {

	//Getting approximate tile position of the mouse cursor
	tilePosX = (posX - (posX % 32)) / 32;
	tilePosY = (posY - (posY % 32)) / 32;

	//If Placing Tile
	if (sf::Mouse::isButtonPressed(sf::Mouse::Right)) {
		
		//Placing Debug Tex
		WorldTilePass->WorldTileMap[tilePosX][tilePosY] = 0;

		//Placing Red
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
			WorldTilePass->WorldTileMap[tilePosX][tilePosY] = 2;

		//Placing Purple
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::X))
			WorldTilePass->WorldTileMap[tilePosX][tilePosY] = 3;

		//Placing Blue
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::C))
			WorldTilePass->WorldTileMap[tilePosX][tilePosY] = 4;

		//Placing Jesse Construction Zone
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::J))
			WorldTilePass->WorldTileMap[tilePosX][tilePosY] = 5;

		//Placing Fuzzen Construction Zone
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::K))
			WorldTilePass->WorldTileMap[tilePosX][tilePosY] = 6;

		//Placing Path
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::V))
			WorldTilePass->WorldTileMap[tilePosX][tilePosY] = 7;
	}

	//Clear Tile
	if (sf::Mouse::isButtonPressed(sf::Mouse::Middle))
		WorldTilePass->WorldTileMap[tilePosX][tilePosY] = 1;

	return;
}