#include <SFML/Graphics.hpp>
#include "Header.h"
#include "KeyboardInputSystem.h"
#include "CameraSystem.h"

////////////////////  INDEX  ////////////////////
//
//	Constructor
//		Doesn't really do anything
//
//	KeyboardInputSystem
//		Gets input from the keyboard and does
//		the action that is assigned to that key
//
//
/////////////////////////////////////////////////

KeyboardInputSystem::KeyboardInputSystem() {
	return;
}

void KeyboardInputSystem::GetInput() {

	//Moving Down
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) || sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
		PlayerPass->MoveDown();
	}

	//Moving Up
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
		PlayerPass->MoveUp();
	}

	//Moving Left
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
		PlayerPass->MoveLeft();
	}

	//Moving Right
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
		PlayerPass->MoveRight();
	}
        
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1)) {
            CameraPass->SetCamera(&PlayerPass->posX,&PlayerPass->posY);
	}
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2)) {
            CameraPass->SetCamera(&CameraPass->sX,&CameraPass->sY);
	}
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num3)) {
            CameraPass->sX=PlayerPass->posX;
            CameraPass->sY=PlayerPass->posY;
            
            CameraPass->SetCamera(&CameraPass->sX,&CameraPass->sY);
	}
        
        
	return;
}