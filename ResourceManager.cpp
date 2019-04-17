#include "Header.h"

ResourceManager::ResourceManager(){
	bleebTexture.loadFromFile("Sprites/Actors/bleeb.png");
	bleebSprite.setTexture(bleebTexture);
}