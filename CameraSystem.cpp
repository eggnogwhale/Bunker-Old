#include "CameraSystem.h"
#include "Header.h"

////////////////////  INDEX  ////////////////////
//
//	Constructor
//		Creates The New View, and assigns its first
//		location
//
//	UpdateCamera
//		Centers the camera onto the player
//
//
//
//
//
/////////////////////////////////////////////////

CameraSystem::CameraSystem() {
	SetCamera(&PlayerPass->posX,&PlayerPass->posY);
	view.setSize(sf::Vector2f(1280, 720));
	view.setCenter(sf::Vector2f(*posX, *posY));
	return;
}
void CameraSystem::SetCamera(int* x, int* y){
    posX = x;
    posY = y;
}

void CameraSystem::UpdateCamera() {
	view.setCenter(sf::Vector2f(*posX, *posY));
	view.setSize(sf::Vector2f(1280, 720));
	WindowPass->setView(view);
        
	return;
}