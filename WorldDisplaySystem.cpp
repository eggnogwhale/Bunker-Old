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
	playerTilePosX = 0;
	playerTilePosY = 0;
	drawX = 0;
	drawY = 0;
	displayError = 0;
	return;
}

//MASTER DRAWING FUNCTION THAT JUST RUNS ALL DRAW FUNCTIONS BELOW
void WorldDisplaySystem::DrawEverything() {
	//Drawing Everything from lowest layer to highest
	DrawTiles();
	DrawWalls();
	return;
}

void WorldDisplaySystem::DrawTiles() {

	//Getting The Player Position
	playerTilePosX = (*CameraPass->posX - (*CameraPass->posX % 32)) / 32;
	playerTilePosY = (*CameraPass->posY - (*CameraPass->posY % 32)) / 32;

	//Drawing Tiles on the Y axis
	for (drawY = (playerTilePosY - 13); drawY != playerTilePosY + 13; drawY++) {

		//Drawing Tiles on the X axis
		for (drawX = (playerTilePosX - 21); drawX != playerTilePosX + 21; drawX++) {

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
					WorldTilePass->DebugSprite.setPosition(sf::Vector2f(WorldTilePass->DebugSprite.getGlobalBounds().width * drawX, WorldTilePass->DebugSprite.getGlobalBounds().height * drawY));
					WorldTilePass->DebugSprite.rotate(0.1f); //THIS LINE IS WACK ASS WHEN CHANGED PAST 0
					WindowPass->draw(WorldTilePass->DebugSprite);
				}

				//Grass Tile
				if (WorldTilePass->WorldTileMap[drawX][drawY] == 1) {
					WorldTilePass->GrassSprite.setPosition(sf::Vector2f(WorldTilePass->GrassSprite.getGlobalBounds().width * drawX, WorldTilePass->GrassSprite.getGlobalBounds().height * drawY));
					WindowPass->draw(WorldTilePass->GrassSprite);
				}//*/
			}
		}
	}

	return;
}

void WorldDisplaySystem::DrawWalls() {
	//Drawing Tiles on the Y axis
	for (drawY = (playerTilePosY - 13); drawY != playerTilePosY + 13; drawY++) {

		//Drawing Tiles on the X axis
		for (drawX = (playerTilePosX - 21); drawX != playerTilePosX + 21; drawX++) {

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
					WorldTilePass->TreeOneSprite.setPosition(sf::Vector2f(32 * drawX, 32 * drawY));
					WindowPass->draw(WorldTilePass->TreeOneSprite);
				}

				//Tree One
				if (WorldTilePass->WorldWallMap[drawX][drawY] == 2) {
					WorldTilePass->TreeTwoSprite.setPosition(sf::Vector2f(32 * drawX, 32 * drawY));
					WindowPass->draw(WorldTilePass->TreeTwoSprite);
				}

			}
		}
	}
}
