#pragma once
struct DisplayNumbersSystem {
	
	//Textures
	sf::Texture numberTextures[10];

	//Sprite
	sf::Sprite numberSprites[10];

	//Constructor
	DisplayNumbersSystem();

	//Function
	void Display(int posX, int posY, int number);
	
};