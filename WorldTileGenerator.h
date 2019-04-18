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
	sf::Texture redTex;
	sf::Texture blueTex;
	sf::Texture purpleTex;
	sf::Texture jesseConstructionTex;
	sf::Texture fuzzenConstructionTex;
	sf::Texture pathTex;
	//Sprites
	sf::Sprite GrassSprite;
	sf::Sprite redSprite;
	sf::Sprite blueSprite;
	sf::Sprite purpleSprite;
	sf::Sprite jesseConstructionSprite;
	sf::Sprite fuzzenConstructionSprite;
	sf::Sprite pathSprite;

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