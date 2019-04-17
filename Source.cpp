#include <SFML/Graphics.hpp>
#include <time.h>
#include "Header.h"
#include "PlayerCharacter.h"
#include "InputSystem.h"
#include "CameraSystem.h"
#include "WorldTileGenerator.h"
#include "WorldDisplaySystem.h"
#include "InventorySystem.h"
#include "DisplayNumbersSystem.h"

//External Things
PlayerCharacter *PlayerPass;
CameraSystem * CameraPass;
sf::RenderWindow *WindowPass;
WorldTileGenerator * WorldTilePass;
InventorySystem * InventoryPass;
DisplayNumbersSystem * DisplayNumberPass;


int main() {
	
	//Setting up randomly generated seed
	srand(time(NULL));

	//////////  Window Setup  //////////
	sf::RenderWindow window(sf::VideoMode(1920,1080), "Bunker", sf::Style::Fullscreen);
	window.setMouseCursorVisible(false);
	window.setFramerateLimit(500);
	sf::Event event;
	WindowPass = &window;

	//////////  Class Declaration  //////////
	//Player Instantiation and pointer passing
	PlayerCharacter Player;
	PlayerPass = &Player;
	//Control Setup
	InputSystem Input;
	//Camera that focuses on the players
	CameraSystem Camera;
	CameraPass = &Camera;
	//World Tile Generator instantiation, passing and generating a tile
	WorldTileGenerator TileGenerator;
	WorldTilePass = &TileGenerator;
	TileGenerator.GenerateTile();
	//World Displaying System
	WorldDisplaySystem WorldDisplay;
	//Inventory Setup
	InventorySystem Inventory;
	InventoryPass = &Inventory;
	//Number Display Setup
	DisplayNumbersSystem DisplayNumbers;
	DisplayNumberPass = &DisplayNumbers;

	///////////////////////////////////////////
	///////////////  Game Loop  ///////////////
	while (window.isOpen()) {

		//Events
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}
		}

		////////////////////////////////////////////
		///////////////  Game Stuff  ///////////////
		window.clear(sf::Color::Black);

		//This shit seems to work right now
		Camera.UpdateCamera();
		WorldDisplay.DrawEverything();
		Player.Draw();
		Inventory.HotbarFunctions();
		Input.MouseFunctions();
		Input.RunKeyboardInput();


		/// This is a debug thing for closing the game by pressing backspace
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace)) {
			window.close();
		}


		window.display();
		//////////  Ending The Frame //////////
		///////////////////////////////////////
	}

	return 0;
}