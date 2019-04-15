#pragma once
struct InventorySystem {

	//Constructor
	InventorySystem();

	//Functions
	void DisplayHotbar();
	void AddItem(int itemID, int amount);

	//Draw Hotbar Interaction Boxes
	void DrawInteractionBoxes();

public:

	//Master Function
	void HotbarFunctions();

	//Invisible Interaction Boxes
	sf::RectangleShape interactionBoxOne;
	sf::RectangleShape interactionBoxTwo;
	sf::RectangleShape interactionBoxThree;
	sf::RectangleShape interactionBoxFour;
	sf::RectangleShape interactionBoxFive;
	sf::RectangleShape interactionBoxSix;
	sf::RectangleShape interactionBoxSeven;
	sf::RectangleShape interactionBoxEight;
	sf::RectangleShape interactionBoxNine;
	sf::RectangleShape interactionBoxTen;
	sf::RectangleShape interactionBoxEleven;
	sf::RectangleShape interactionBoxTwelve;
	sf::RectangleShape interactionBoxThirteen;
	sf::RectangleShape interactionBoxFourteen;
	sf::RectangleShape interactionBoxFifteen;
	sf::RectangleShape interactionBoxSixteen;
	sf::RectangleShape interactionBoxSeventeen;
	sf::RectangleShape interactionBoxEightteen;
	sf::RectangleShape interactionBoxNineteen;
	sf::RectangleShape interactionBoxTwenty;

	//Textures
	sf::Texture hotbarTex;
	sf::Texture logTex;

	//Sprites
	sf::Sprite hotbarSprite;
	sf::Sprite logSprite;

	//Inventory Variables
	int inventory[20];
	int inventoryAmount[20];
	int inventoryDurability[20];

};