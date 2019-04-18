#include <iostream>
#include "Header.h"
#include "InventorySystem.h"

////////////////////  INDEX  ////////////////////
//
//	Constructor
//		Clears all of the inventory slots so that
//		array out of bounds exceptions don't happen.
//
//	DisplayHotbar
//		Displays the hotbar to the screen and shows
//		all of the players items in the hotbar. It
//		Also draws the numbers nessecary for the 
//		items, and it shows the Items ICON.
//	
//	AddItem
//		Is used to add new items to the hotbar when
//		players destroy blocks and stuff. This is
//		primarily used by other parts of the program
//		to add items to the players inventory. It
//		is mostly used by the InteractionSystem.cpp
//		file in the wall interaction section.
//
//	DrawInteractionBoxes
//		This function draws the boxes that are used
//		by the mouse to track interaction with them.
//		These are essentially the hitboxes for the
//		mouse to use to select a hotbar slot.
//
//	HotbarFunctions
//		Just runs all of the nessecary hotbar functions
//		for main. This includes drawing the hotbar/Inventory
//		and placing the mouse interaction boxes in the
//		right place
//
/////////////////////////////////////////////////

InventorySystem::InventorySystem() {

	//Texture Loading
	if (!hotbarTex.loadFromFile("Sprites/Menu/Hotbar.png")) {}
	if (!logTex.loadFromFile("Sprites/Menu/LogIcon.png")) {}

	//Sprite loading
	hotbarSprite.setTexture(hotbarTex);
	logSprite.setTexture(logTex);

	//Making all slots empty
	for (int clearSlot = 0; clearSlot != 20; clearSlot++) {
		inventory[clearSlot] = 0;
		inventoryAmount[clearSlot] = 0;
		inventoryDurability[clearSlot] = 0;
	}

}



void InventorySystem::DisplayHotbar() {
	//HOTBAR SPRITE STUFFS
	/*
		The first hotbar slot icon appears at pixel 31,5
		Each hotbar slot origin distance is 30 pixels on x axis
		each hotbar slot is only 24 pixels wide, and 24 tall
	*/


	//Drawing the hotbar and pockets
	hotbarSprite.setPosition(sf::Vector2f(*CameraPass->posX - (1280 / 2), *CameraPass->posY + (720/2) - hotbarSprite.getGlobalBounds().height));
	WindowPass->draw(hotbarSprite);

	//Displaying Hotbar Items
	for (int displayHotbar = 0; displayHotbar != 10; displayHotbar++) {

		//Wood Block
		if (inventory[displayHotbar] == 1) {
			logSprite.setPosition(sf::Vector2f(*CameraPass->posX - (1280/2) + (24 * displayHotbar) + 30,*CameraPass->posY + (720/2) - logSprite.getGlobalBounds().height - 2));
			WindowPass->draw(logSprite);
			DisplayNumberPass->Display(logSprite.getPosition().x, logSprite.getPosition().y, inventoryAmount[displayHotbar]);
		}

	}
}



void InventorySystem::AddItem(int itemID, int amount) {

	//Checking to see if the player has this item yet
	for (int checkHas = 0; checkHas != 20; checkHas++) {

		//If that spot exists
		if (inventory[checkHas] == itemID) {
			//std::cout << "Gave the player ID#" << itemID << " amount:" << amount << std::endl;
			inventoryAmount[checkHas] += amount;
			return;
		}
	}

	//Checking to see if the player has an empty spot
	for (int checkEmpty = 0; checkEmpty != 20; checkEmpty++) {

		//Checking if empty
		if (inventory[checkEmpty] == 0) {
			//std::cout << "Gave the player ID#" << itemID << " amount:" << amount << std::endl;
			inventory[checkEmpty] = itemID;
			inventoryAmount[checkEmpty] += amount;
			return;
		}
	}

	//If the player has no empty spots end the function
}



void InventorySystem::DrawInteractionBoxes() {

	return;
}



void InventorySystem::HotbarFunctions() {
	DisplayHotbar();
	DrawInteractionBoxes();
}