#pragma once
struct WorldDisplaySystem {

	//Variables
	float playerTilePosX;
	float playerTilePosY;
	int drawX;
	int drawY;
	int displayError;

	

	//Constructor
	WorldDisplaySystem();

	//Master World Drawing
	void DrawWorld();

	//Drawing World Parts
	void DrawTiles();
	void DrawWalls();
};