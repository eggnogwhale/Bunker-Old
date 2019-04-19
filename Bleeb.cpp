#include "Header.h"
#include "Bleeb.h"

Bleeb::Bleeb() {
	m_x = rand() % (WorldTilePass->WORLD_SIZE_X * 32);
	m_y = rand() % (WorldTilePass->WORLD_SIZE_Y * 32);
	m_s = rand() % 4 + 2;
	bleebSprite = &ResourcePass->bleebSprite;
}
Bleeb::~Bleeb() {}

void Bleeb::draw(){
	bleebSprite->setPosition(sf::Vector2f(m_x, m_y));
	WindowPass->draw(*bleebSprite);
}
void Bleeb::run(){
	m_x += m_s * (m_x>PlayerPass->posX?-1:1)+ rand()%12-6;
	m_y += m_s * (m_y>PlayerPass->posY?-1:1)+ rand()%12-6;
}
void Bleeb::follow(CameraSystem& camSys){
	camSys.SetCamera(&m_x,&m_y);
	//TODO make less weird
}