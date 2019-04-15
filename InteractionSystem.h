#pragma once
struct InteractionSystem {

	//Mouse Textures
	//sf::Texture mouseTex;
	//Mouse Sprites
	//sf::Sprite mouseSprite;
	//Debug mouse shape
	sf::RectangleShape mouseSprite;

	//Mouse variables
	int posX;
	int posY;
	int tilePosX;
	int tilePosY;

	//Constructor
	InteractionSystem();

	//Mouse Drawing
	void DrawMouse();

	//Getting Mouse Input
	void MouseInteraction();

	//Master Mouse Function
	void MouseFunctions();

	//Hotbar Interaction
	void CheckHotbarInteraction();

	//Enviorment interaction
	void CheckWallInteraction();

};