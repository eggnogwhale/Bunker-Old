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
	//Variable Setup
	posX = 0;
	posY = 0;
	currentDirection = 0;

	//Texture Loading
	if (!UpTex.loadFromFile("Sprites/Actors/Player/Up.png")) {}
	if (!DownTex.loadFromFile("Sprites/Actors/Player/Down.png")) {}
	if (!LeftTex.loadFromFile("Sprites/Actors/Player/Left.png")) {}
	if (!RightTex.loadFromFile("Sprites/Actors/Player/Right.png")) {}
	
	//Sprite Setup
	UpSprite.setTexture(UpTex);
	DownSprite.setTexture(DownTex);
	LeftSprite.setTexture(LeftTex);
	RightSprite.setTexture(RightTex);

	return;
}

void PlayerCharacter::Draw() {

	//Facing Down
	if(currentDirection == 0) {
		DownSprite.setPosition(sf::Vector2f(posX, posY));
		WindowPass->draw(DownSprite);
	}

	//Facing Up
	if (currentDirection == 2) {
		UpSprite.setPosition(sf::Vector2f(posX, posY));
		WindowPass->draw(UpSprite);
	}

	//Facing Left
	if (currentDirection == 3) {
		LeftSprite.setPosition(sf::Vector2f(posX, posY));
		WindowPass->draw(LeftSprite);
	}

	//Facing Down
	if (currentDirection == 1) {
		RightSprite.setPosition(sf::Vector2f(posX, posY));
		WindowPass->draw(RightSprite);
	}

	return;
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
	if (posY > 100 * 32) {
		posY = 100 * 32;
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
	/*
        if (posX > 32 * 100) {
		posX = 32 * 100;
	}//*/

	//Moving into position
	posX += moveSpeed;
	currentDirection = 1;
	return;
}
