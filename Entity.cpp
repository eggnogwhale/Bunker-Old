#include "Entity.h"
#include "Header.h"

Entity::Entity() {
}
Entity::Entity(int id) {
	m_id = id;
	m_x = rand() %5000 + 150;
	m_y = rand() %5000 + 150;
	m_s = rand() % 5+1;
}
Entity::~Entity() {}

void Entity::draw(){
	ResourcePass->bleebSprite.setPosition(sf::Vector2f(m_x, m_y));
	WindowPass->draw(ResourcePass->bleebSprite);
}
void Entity::run(){
	m_x += m_s * (m_x>PlayerPass->posX?-1:1)+ rand()%2;
	m_y += m_s * (m_y>PlayerPass->posY?-1:1);
}