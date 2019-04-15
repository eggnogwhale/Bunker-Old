#pragma once
struct PlayerCharacter {

	//Variables
	int posX;
	int posY;
	int currentDirection;
	const int moveSpeed = 8;

	//Sprites
	sf::Sprite UpSprite;
	sf::Sprite DownSprite;
	sf::Sprite LeftSprite;
	sf::Sprite RightSprite;
	//Textures
	sf::Texture UpTex;
	sf::Texture DownTex;
	sf::Texture LeftTex;
	sf::Texture RightTex;


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