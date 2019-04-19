#pragma once
#include <SFML/Graphics.hpp>

struct PlayerCharacter {

	//Variables
	int posX = 0;
	int posY = 0;
	int currentDirection = 0;
	const int moveSpeed = 8;

	//Sprites
	sf::Sprite *UpSprite;
	sf::Sprite *DownSprite;
	sf::Sprite *LeftSprite;
	sf::Sprite *RightSprite;

	//Constructor
	PlayerCharacter();

	//Drawing
	void Draw();

	//Movement
	void MoveUp();
	void MoveDown();
	void MoveLeft();
	void MoveRight();
};