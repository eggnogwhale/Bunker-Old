#pragma once
#include <SFML/Graphics.hpp>

struct WorldTileGenerator {
	
	//World Size, Saves The Array Length and Width - 1
	//THESE ARE EXTREMELY IMPORTANT FOR DISPLAYING TILES & WALLS
	const int WORLD_SIZE_X = 150;
	const int WORLD_SIZE_Y = 150;

	//Array
	int WorldTileMap[151][151];
	int WorldWallMap[151][151];

	//Variables
	int randomNumber;

	//Constructor
	WorldTileGenerator();

	//Generate Tile
	void GenerateTile();
};