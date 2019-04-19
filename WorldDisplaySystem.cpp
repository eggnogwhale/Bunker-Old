#include <SFML/Graphics.hpp>
#include "Header.h"
#include "WorldDisplaySystem.h"
#include <iostream>
#include <stdlib.h>

////////////////////  INDEX  ////////////////////
//
//	Constructor
//		Does Very Little	
//
//	DrawTiles
//		Draws the respective tile to the world
//		by checking the WorldTileMap Array.
//		
//	DrawEverything	
//		Runs each layer of drawing in order
//		to achieve full drawing. i.e. runs DrawTiles
//		and DrawWalls, DrawActors, etc.
//
//
/////////////////////////////////////////////////

WorldDisplaySystem::WorldDisplaySystem() {
	cameraTilePosX = 0;
	cameraTilePosY = 0;
	drawX = 0;
	drawY = 0;
	displayError = 0;
	
	DebugSprite = &ResourcePass->DebugSprite;
	
	GrassSprite = &ResourcePass->GrassSprite;
	redSprite = &ResourcePass->redSprite;
	blueSprite = &ResourcePass->blueSprite;
	purpleSprite = &ResourcePass->purpleSprite;
	jesseConstructionSprite = &ResourcePass->jesseConstructionSprite;
	fuzzenConstructionSprite = &ResourcePass->fuzzenConstructionSprite;
	pathSprite = &ResourcePass->pathSprite;

	TreeOneSprite = &ResourcePass->TreeOneSprite;
	TreeTwoSprite = &ResourcePass->TreeTwoSprite;
	return;
}

//MASTER DRAWING FUNCTION THAT JUST RUNS ALL DRAW FUNCTIONS BELOW
void WorldDisplaySystem::DrawWorld() {
	//Drawing Everything from lowest layer to highest
	DrawTiles();
	DrawWalls();
	return;
}

void WorldDisplaySystem::DrawTiles() {

	//Getting The Player Position
	cameraTilePosX = (*CameraPass->posX - (*CameraPass->posX % 32)) / 32;
	cameraTilePosY = (*CameraPass->posY - (*CameraPass->posY % 32)) / 32;

	//Drawing Tiles on the Y axis
	for (drawY = (cameraTilePosY - 13); drawY != cameraTilePosY + 13; drawY++) {

		//Drawing Tiles on the X axis
		for (drawX = (cameraTilePosX - 21); drawX != cameraTilePosX + 21; drawX++) {

			//Resetting display error
			displayError = 0;

			//Drawing above the map
			if (drawY < 0) {
				displayError = 1;
				break;
			}

			//Drawing too far left
			if (drawX < 0) {
				displayError = 1;
			}

			//Drawing too far right DEFAULT SETTING = 100, otherwise weird shit happens
			if (drawX > WorldTilePass->WORLD_SIZE_X) {
				displayError = 1;
				break;
			}

			//Drawing below the map
			if (drawY > WorldTilePass->WORLD_SIZE_Y) {
				displayError = 1;
				return;
			}

			////////////////////////////////////////////////
			//////////  Doing the actual drawing  //////////
			if (displayError == 0) {

				//Debug Tile
				if (WorldTilePass->WorldTileMap[drawX][drawY] == 0) {
					DebugSprite->setPosition(sf::Vector2f(DebugSprite->getGlobalBounds().width * drawX, DebugSprite->getGlobalBounds().height * drawY));
					//WorldTilePass->DebugSprite.rotate(0.1f); //THIS LINE IS WACK ASS WHEN CHANGED PAST 0
					WindowPass->draw(*DebugSprite);
				}
				//Grass Tile
				if (WorldTilePass->WorldTileMap[drawX][drawY] == 1) {
					GrassSprite->setPosition(sf::Vector2f(GrassSprite->getGlobalBounds().width * drawX, GrassSprite->getGlobalBounds().height * drawY));
					WindowPass->draw(*GrassSprite);
				}
				//Red Tile
				if (WorldTilePass->WorldTileMap[drawX][drawY] == 2) {
					redSprite->setPosition(sf::Vector2f(GrassSprite->getGlobalBounds().width * drawX, GrassSprite->getGlobalBounds().height * drawY));
					WindowPass->draw(*redSprite);
				}
				//Purple Tile
				if (WorldTilePass->WorldTileMap[drawX][drawY] == 3) {
					purpleSprite->setPosition(sf::Vector2f(GrassSprite->getGlobalBounds().width * drawX, GrassSprite->getGlobalBounds().height * drawY));
					WindowPass->draw(*purpleSprite);
				}
				//Blue Tile
				if (WorldTilePass->WorldTileMap[drawX][drawY] == 4) {
					blueSprite->setPosition(sf::Vector2f(GrassSprite->getGlobalBounds().width * drawX, GrassSprite->getGlobalBounds().height * drawY));
					WindowPass->draw(*blueSprite);
				}
				//Jesse Construction Tile
				if (WorldTilePass->WorldTileMap[drawX][drawY] == 5) {
					jesseConstructionSprite->setPosition(sf::Vector2f(GrassSprite->getGlobalBounds().width * drawX, GrassSprite->getGlobalBounds().height * drawY));
					WindowPass->draw(*jesseConstructionSprite);
				}
				//Fuzzen Construction Tile
				if (WorldTilePass->WorldTileMap[drawX][drawY] == 6) {
					fuzzenConstructionSprite->setPosition(sf::Vector2f(GrassSprite->getGlobalBounds().width * drawX,GrassSprite->getGlobalBounds().height * drawY));
					WindowPass->draw(*fuzzenConstructionSprite);
				}
				//Path
				if (WorldTilePass->WorldTileMap[drawX][drawY] == 7) {
					pathSprite->setPosition(sf::Vector2f(GrassSprite->getGlobalBounds().width * drawX, GrassSprite->getGlobalBounds().height * drawY));
					WindowPass->draw(*pathSprite);
				}
			}
		}
	}

	return;
}

void WorldDisplaySystem::DrawWalls() {
	//Drawing Tiles on the Y axis
	for (drawY = (cameraTilePosY - 13); drawY != cameraTilePosY + 13; drawY++) {

		//Drawing Tiles on the X axis
		for (drawX = (cameraTilePosX - 21); drawX != cameraTilePosX + 21; drawX++) {

			//Resetting display error
			displayError = 0;

			//Drawing above the map
			if (drawY < 0) {
				displayError = 1;
				break;
			}

			//Drawing too far left
			if (drawX < 0) {
				displayError = 1;
			}

			//Drawing too far right DEFAULT SETTING = 100, otherwise weird shit happens
			if (drawX > WorldTilePass->WORLD_SIZE_X) {
				displayError = 1;
				break;
			}

			//Drawing below the map
			if (drawY > WorldTilePass->WORLD_SIZE_Y) {
				displayError = 1;
				return;
			}

			/////////////////////////////////////////////////
			///////////  Doing the actual drawing  //////////
			if (displayError == 0) {

				//Tree One
				if (WorldTilePass->WorldWallMap[drawX][drawY] == 1) {
					TreeOneSprite->setPosition(sf::Vector2f(32 * drawX, 32 * drawY));
					WindowPass->draw(*TreeOneSprite);
				}

				//Tree One
				if (WorldTilePass->WorldWallMap[drawX][drawY] == 2) {
					TreeTwoSprite->setPosition(sf::Vector2f(32 * drawX, 32 * drawY));
					WindowPass->draw(*TreeTwoSprite);
				}

			}
		}
	}
}
