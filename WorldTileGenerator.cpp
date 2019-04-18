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
	if (!redTex.loadFromFile("Sprites/Tiles/Red.png")) {}
	if (!blueTex.loadFromFile("Sprites/Tiles/Blue.png")) {}
	if (!purpleTex.loadFromFile("Sprites/Tiles/Purple.png")) {}
	if (!fuzzenConstructionTex.loadFromFile("Sprites/Tiles/FuzzenConst.png")) {}
	if (!jesseConstructionTex.loadFromFile("Sprites/Tiles/JesseConst.png")) {}
	if (!pathTex.loadFromFile("Sprites/Tiles/Path.png")) {}

	//Sprite Setup
	DebugSprite.setTexture(DebugTex);
	GrassSprite.setTexture(GrassTex);
	redSprite.setTexture(redTex);
	blueSprite.setTexture(blueTex);
	purpleSprite.setTexture(purpleTex);
	fuzzenConstructionSprite.setTexture(fuzzenConstructionTex);
	jesseConstructionSprite.setTexture(jesseConstructionTex);
	pathSprite.setTexture(pathTex);

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

	return;
}