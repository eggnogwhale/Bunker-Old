#include "Header.h"
#include "EntitySystem.h"
#include "Bleeb.h"
#include "Saint.h"

EntitySystem::EntitySystem(){
	
	for(int i=0;i<1000;i++){
		addEntity(new Bleeb());
	}
	addEntity(new Saint(2));
	addEntity(new Saint(1));
	
}

void EntitySystem::addEntity(Entity* add){
	entities[cap] = add;
	cap++;
}

EntitySystem::~EntitySystem(){
	for(int i=0;i<cap;i++){
		delete entities[i];
	}
	delete[] entities;
}

void EntitySystem::drawEntities(){
	for(int i=0;i<cap;i++){
		entities[i]->draw();
	}
}

void EntitySystem::runEntities(){
	for(int i=0;i<cap;i++){
		entities[i]->run();
	}
	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num0)){
		if (cap>=10000)return;
		addEntity(new Bleeb());
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num9)){
		if (cap<=0)return;
		while(cap>0){
			cap--;
			delete entities[cap];
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num8)){
		entities[rand()%cap]->follow(*CameraPass);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num7)){
		addEntity(new Saint(rand()%3+1));
	}
}