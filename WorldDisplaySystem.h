#pragma once
struct WorldDisplaySystem {

	//Variables
	float cameraTilePosX;
	float cameraTilePosY;
	int drawX;
	int drawY;
	int displayError;
	
	//////////  TILES  //////////
	//DEBUG TILE
	sf::Sprite *DebugSprite;
	//Tiles
	sf::Sprite *GrassSprite;
	sf::Sprite *redSprite;
	sf::Sprite *blueSprite;
	sf::Sprite *purpleSprite;
	sf::Sprite *jesseConstructionSprite;
	sf::Sprite *fuzzenConstructionSprite;
	sf::Sprite *pathSprite;

	//////////  WALLS  //////////
	sf::Sprite *TreeOneSprite;
	sf::Sprite *TreeTwoSprite;

	//Constructor
	WorldDisplaySystem();

	//Master World Drawing
	void DrawWorld();

	//Drawing World Parts
	void DrawTiles();
	void DrawWalls();
};