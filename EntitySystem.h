#pragma once
#include "Entity.h"

struct EntitySystem {
	
	EntitySystem();
	~EntitySystem();
	int cap=0;
	Entity** entities = new Entity*[10000];//TODO: Make this a vector<>
	
	void addEntity(Entity* add);
	void drawEntities();
	void runEntities();
};