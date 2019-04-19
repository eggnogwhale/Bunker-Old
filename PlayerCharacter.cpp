#include <SFML/Graphics.hpp>
#include "PlayerCharacter.h"
#include "Header.h"

////////////////////  INDEX  ////////////////////
//
//	Constructor
//		Loads in all of the nessecary sprites
//		and textures for the player.
//
//	Draw
//		Picks the proper sprite and displays it
//		to the screen. Moves the player into the
//		allocated spot.
//
//	Movement Functions
//		These are used by keyboard input to move
//		the player.
//
/////////////////////////////////////////////////

PlayerCharacter::PlayerCharacter() {
	
	//Get Sprites
	UpSprite = &ResourcePass->UpSprite;
	DownSprite = &ResourcePass->DownSprite;
	LeftSprite = &ResourcePass->LeftSprite;
	RightSprite = &ResourcePass->RightSprite;
	
}

void PlayerCharacter::Draw() {

	/*use cases or arrays for this?*/ 
	
	//Facing Down
	if(currentDirection == 0) {
		DownSprite->setPosition(sf::Vector2f(posX, posY));
		WindowPass->draw(*DownSprite);
	}

	//Facing Up
	else if (currentDirection == 2) {
		UpSprite->setPosition(sf::Vector2f(posX, posY));
		WindowPass->draw(*UpSprite);
	}

	//Facing Left
	else if (currentDirection == 3) {
		LeftSprite->setPosition(sf::Vector2f(posX, posY));
		WindowPass->draw(*LeftSprite);
	}

	//Facing Down
	else if (currentDirection == 1) {
		RightSprite->setPosition(sf::Vector2f(posX, posY));
		WindowPass->draw(*RightSprite);
	}
}

void PlayerCharacter::MoveUp() {
	//If above world, stop them from moving
	if (posY < 0) {
		posY = 0;
	}//*/

	//Moves into position
	posY -= moveSpeed;
	currentDirection = 2;

	return;
}

void PlayerCharacter::MoveDown() {
	//If moving below the world
	if (posY > WorldTilePass->WORLD_SIZE_Y * 32) {
		posY = WorldTilePass->WORLD_SIZE_Y * 32;
	}//*/

	//Moving into position
	posY += moveSpeed;
	currentDirection = 0;
	return;
}

void PlayerCharacter::MoveLeft() {
	//If Moving too far left
	if (posX < 0) {
		posX = 0;
	}//*/

	//Moving Into position
	posX -= moveSpeed;
	currentDirection = 3;
	return;
}

void PlayerCharacter::MoveRight() {
	//If moving too far right
    if (posX > WorldTilePass->WORLD_SIZE_X * 32) {
		posX = WorldTilePass->WORLD_SIZE_X * 32;
	}//*/

	//Moving into position
	posX += moveSpeed;
	currentDirection = 1;
	return;
}
