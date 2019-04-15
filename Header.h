#pragma once
#include "PlayerCharacter.h"
#include "WorldTileGenerator.h"
#include "InventorySystem.h"
#include "CameraSystem.h"
#include "DisplayNumbersSystem.h"
#include <SFML/Graphics.hpp>

//Holds A pointer to the window
extern sf::RenderWindow * WindowPass;

//Holds A pointer to the player character object
extern PlayerCharacter * PlayerPass;

//Holds A pointer to the Current World Tile
extern WorldTileGenerator * WorldTilePass;

//Holds a pointer to the players inventory
extern InventorySystem * InventoryPass;

//Holds the object to display numbers
extern DisplayNumbersSystem * DisplayNumberPass;

// Pointer to the camera system reachable by any file including this one 
extern CameraSystem * CameraPass;