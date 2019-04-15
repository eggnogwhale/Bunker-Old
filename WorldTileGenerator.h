#pragma once
struct WorldTileGenerator {
	
	//DEBUG TILES
	sf::Texture DebugTex;
	sf::Sprite DebugSprite;
	

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
	int WorldTileMap[101][101];
	int WorldWallMap[101][101];

	//Constructor
	WorldTileGenerator();

	//Generate Tile
	void GenerateTile();
};