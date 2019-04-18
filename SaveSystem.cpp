#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include "Header.h"
#include "SaveSystem.h"

////////////////////  INDEX  ////////////////////
//
//	Constructor
//		
//
//
//
//
/////////////////////////////////////////////////

SaveSystem::SaveSystem() {
	return;
}

void SaveSystem::SaveMap() {
	//Writer Setup
	std::ofstream writeToFile;
	writeToFile.open("MAP.txt", std::ios_base::out);
	//Saving Tiles
	for (int saveY = 0; saveY < WorldTilePass->WORLD_SIZE_Y; saveY++) {
		for (int saveX = 0; saveX < WorldTilePass->WORLD_SIZE_X; saveX++) {
			writeToFile << WorldTilePass->WorldTileMap[saveX][saveY];
		}
	}
	//Saving Walls
	for (int saveWallY = 0; saveWallY < WorldTilePass->WORLD_SIZE_Y; saveWallY++) {
		for (int saveWallX = 0; saveWallX < WorldTilePass->WORLD_SIZE_X; saveWallX++) {
			writeToFile << WorldTilePass->WorldWallMap[saveWallX][saveWallY];
		}
	}

	//Finalizing Save
	writeToFile.close();
	return;
}

void SaveSystem::LoadMap() {
	//Map Loader Setup
	std::ifstream readFromFile;
	readFromFile.open("MAP.txt", std::ios_base::in);
	//Loading Map.txt
	if (readFromFile.is_open()) {

		//Loading Tiles
		for (int loadY = 0; loadY < WorldTilePass->WORLD_SIZE_Y; loadY++) {
			for (int loadX = 0; loadX < WorldTilePass->WORLD_SIZE_X; loadX++) {
				WorldTilePass->WorldTileMap[loadX][loadY] = (int)readFromFile.get() - 48; //48 is needed to set ASCII chars at 0
			}
		}

		//Loading Walls
		for (int loadWallY = 0; loadWallY < WorldTilePass->WORLD_SIZE_Y; loadWallY++) {
			for (int loadWallX = 0; loadWallX < WorldTilePass->WORLD_SIZE_X; loadWallX++) {
				WorldTilePass->WorldWallMap[loadWallX][loadWallY] = (int)readFromFile.get() - 48; //-48 sets ASCII codes at 0
			}
		}
	}

	
	return;
}