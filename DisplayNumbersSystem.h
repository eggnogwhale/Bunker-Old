#pragma once
#include <SFML/Graphics.hpp>
#include "ResourceManager.h"

struct DisplayNumbersSystem {
	
	sf::Sprite (*numberSprites)[10];
	
	//Constructor
	DisplayNumbersSystem();

	//Function
	void Display(int posX, int posY, int number);
	
};