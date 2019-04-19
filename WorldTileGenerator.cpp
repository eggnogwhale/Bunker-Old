#include <SFML/Graphics.hpp>
#include "Header.h"
#include "WorldTileGenerator.h"
#include <time.h>

////////////////////  INDEX  ////////////////////
//
//	Constructor
//		Loads the textures and sprites for all
//		tiles.
//
//	GenerateTile
//		Generates required land info and sends it
//		to the map array to be used by the display
//		This system handles everything.
//
//
/////////////////////////////////////////////////

WorldTileGenerator::WorldTileGenerator() {
}

void WorldTileGenerator::GenerateTile() {

	//Generate Tile Map
	for (int y = 0; y != WORLD_SIZE_Y; y++) {
		for (int x = 0; x != WORLD_SIZE_X; x++) {
			WorldTileMap[x][y] = 1;
		}
	}

	//Generate Wall Map
	for (int randY = 0; randY != WORLD_SIZE_Y; randY++) {
		for (int randX = 0; randX != WORLD_SIZE_X; randX++) {
			
			//Generating A Random Number
			randomNumber = rand() % 6 + 1;

			//Generating Tree 1
			if (randomNumber == 4) {
				WorldWallMap[randX][randY] = 1;
			}
			else if (randomNumber == 3) { //Generating Tree 2
				WorldWallMap[randX][randY] = 2;
			}
			else {
				WorldWallMap[randX][randY] = 0;
			}
		}
	}
}