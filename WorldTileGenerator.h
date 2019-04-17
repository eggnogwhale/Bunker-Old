#pragma once
struct WorldTileGenerator {
	
	//DEBUG TILES
	sf::Texture DebugTex;
	sf::Sprite DebugSprite;

	//World Size, Saves The Array Length and Width - 1
	//THESE ARE EXTREMELY IMPORTANT FOR DISPLAYING TILES & WALLS
	const int WORLD_SIZE_X = 150;
	const int WORLD_SIZE_Y = 150;

	//Array
	int WorldTileMap[151][151];
	int WorldWallMap[151][151];

	//////////  TILES  //////////
	//Textures
	sf::Texture GrassTex;
	//Sprites
	sf::Sprite GrassSprite;

	//////////  WALLS  //////////
	//Textures
	sf::Texture TreeOneTex;
	sf::Texture TreeTwoTex;
	//Sprites
	sf::Sprite TreeOneSprite;
	sf::Sprite TreeTwoSprite;

	//Variables
	int randomNumber;

	//Constructor
	WorldTileGenerator();

	//Generate Tile
	void GenerateTile();
};