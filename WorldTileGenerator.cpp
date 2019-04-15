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

	//////////  TILES  //////////
	//Texture Loading
	if (!DebugTex.loadFromFile("Sprites/Tiles/Debug.png")) {}
	if(!GrassTex.loadFromFile("Sprites/Tiles/Grass.png")) {}
	//Sprite Setup
	DebugSprite.setTexture(DebugTex);
	GrassSprite.setTexture(GrassTex);

	//////////  WALLS  //////////
	//Texture Loading
	if (!TreeOneTex.loadFromFile("Sprites/Walls/Tree1.png")) {}
	if (!TreeTwoTex.loadFromFile("Sprites/Walls/Tree2.png")) {}
	//Sprite Setup
	TreeOneSprite.setTexture(TreeOneTex);
	TreeOneSprite.setOrigin(sf::Vector2f(0, 32));
	TreeTwoSprite.setTexture(TreeTwoTex);
	TreeTwoSprite.setOrigin(sf::Vector2f(0, 32));
	return;
}

void WorldTileGenerator::GenerateTile() {

	//Generate Tile Map
	for (int y = 0; y != 101; y++) {
		for (int x = 0; x != 101; x++) {
			WorldTileMap[x][y] = 1;
		}
	}

	//Generate Wall Map
	for (int randY = 0; randY != 100; randY++) {
		for (int randX = 0; randX != 100; randX++) {
			
			//Generating A Random Number
			randomNumber = rand() % 6 + 1;

			//Generating Tree 1
			if (randomNumber == 4) {
				WorldWallMap[randX][randY] = 1;
			}

			//Generating Tree 2
			if (randomNumber == 3) {
				WorldWallMap[randX][randY] = 2;
			}

		}
	}

	return;
}