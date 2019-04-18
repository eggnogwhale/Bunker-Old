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
	sf::RectangleShape interactionBox;

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