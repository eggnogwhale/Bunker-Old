#include <SFML/Graphics.hpp>
#include "Header.h"
#include "DisplayNumbersSystem.h"

////////////////////   INDEX   ////////////////////
//
//	Constructor
//		The constructor loads in the sprites for the
//		numbers.
//
//
//
///////////////////////////////////////////////////



DisplayNumbersSystem::DisplayNumbersSystem() {

	//Texture loading
	if (!numberTextures[1].loadFromFile("Sprites/Menu/One.png")) {}
	if (!numberTextures[2].loadFromFile("Sprites/Menu/Two.png")) {}
	if (!numberTextures[3].loadFromFile("Sprites/Menu/Three.png")) {}
	if (!numberTextures[4].loadFromFile("Sprites/Menu/Four.png")) {}
	if (!numberTextures[5].loadFromFile("Sprites/Menu/Five.png")) {}
	if (!numberTextures[6].loadFromFile("Sprites/Menu/Six.png")) {}
	if (!numberTextures[7].loadFromFile("Sprites/Menu/Seven.png")) {}
	if (!numberTextures[8].loadFromFile("Sprites/Menu/Eight.png")) {}
	if (!numberTextures[9].loadFromFile("Sprites/Menu/Nine.png")) {}
	if (!numberTextures[0].loadFromFile("Sprites/Menu/Zero.png")) {}
	
    //Sprite Setup
    for (int i=0;i<10;i++){
		numberSprites[i].setTexture(numberTextures[i]);
    }
}


void DisplayNumbersSystem::Display(int posX, int posY, int number) {
	
	int digit = 0, base = 10000, offset=0;
	
	digit = number % base;
	while (digit == number){//digit used as util variable and not actual digit
		base/=10;
		digit = number % base;
	}
	
	while (base > 0){
		digit = (number - (number % base)) / base;
		number -= digit * base;
		numberSprites[digit].setPosition(sf::Vector2f(posX + offset * 5, posY));
		WindowPass->draw(numberSprites[digit]);
		base /= 10;
		offset++;
	}
}