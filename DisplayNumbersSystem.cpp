#include "Header.h"
#include "DisplayNumbersSystem.h"
#include "Bleeb.h"

#include <iostream>
#include <typeinfo>

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
	numberSprites = &ResourcePass->numberSprites;
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
		(*numberSprites)[digit].setPosition(sf::Vector2f(posX + offset * 5, posY));
		WindowPass->draw((*numberSprites)[digit]);
		base /= 10;
		offset++;
	}
}