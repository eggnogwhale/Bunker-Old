#pragma once
struct InputSystem {
    
	//Debug mouse shape
	sf::RectangleShape mouseSprite;

	//Mouse variables
	int posX;
	int posY;
	int tilePosX;
	int tilePosY;
    
	//Constructor
	InputSystem();
	
	
	//Mouse functions
	void DrawMouse();

	void MouseInteraction();

	void MouseFunctions();

	void CheckWallInteraction();

	void CheckPlacingTile();

	//Keyboard functions
	void RunKeyboardInput();
};