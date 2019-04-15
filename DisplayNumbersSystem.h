#pragma once
struct DisplayNumbersSystem {

        //Textures
        sf::Texture numberTextures[10];

	//Sprites
        sf::Sprite numberSprites[10];

	//Constructor
	DisplayNumbersSystem();

	//Function
	void Display(int posX, int posY, int number);
	
};