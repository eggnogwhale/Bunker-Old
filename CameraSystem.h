#pragma once
#include <SFML/Graphics.hpp>

struct CameraSystem {
        
	//View
	sf::View view;
	int* posX;
	int* posY;
	int sX=0;
	int sY=0;
	
	//Constructor
	CameraSystem();
        
	//Camera
	void SetCamera(int* x, int* y);
	void UpdateCamera();
};