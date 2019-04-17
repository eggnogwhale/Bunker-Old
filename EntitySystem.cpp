#include "Header.h"
#include "EntitySystem.h"

EntitySystem::EntitySystem(){
	
	for(int i=0;i<1000;i++){
		entities[i] = Entity(2);
		cap++;
	}
}

void EntitySystem::drawEntities(){
	for(int i=0;i<cap;i++){
		entities[i].draw();
	}
}

void EntitySystem::runEntities(){
	for(int i=0;i<cap;i++){
		entities[i].run();
	}
	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num0)){
		if (cap>=1000)return;
		entities[cap] = Entity(2);
		cap++;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num9)){
		if (cap<=0)return;
		cap--;
		entities[cap].~Entity();// is this a legit thing?
	}
}