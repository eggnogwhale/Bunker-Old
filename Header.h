#pragma once
#include <SFML/Graphics.hpp>
#include "PlayerCharacter.h"
#include "WorldTileGenerator.h"
#include "InventorySystem.h"
#include "CameraSystem.h"
#include "DisplayNumbersSystem.h"
#include "ResourceManager.h"
#include "SaveSystem.h"
#include "InputSystem.h"
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

//Saving System Pass
extern SaveSystem * SaveSystemPass;

//Resources
extern ResourceManager * ResourcePass;

//Input Pass
extern InputSystem * InputPass;