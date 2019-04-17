#pragma once
#include "Entity.h"
struct EntitySystem {
	
	EntitySystem();
	int cap=0;
	Entity entities[10000];//TODO: Make this a vector<>
	
	void drawEntities();
	void runEntities();
};