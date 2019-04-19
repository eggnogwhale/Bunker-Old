#pragma once
#include "Entity.h"
#include <SFML/Graphics.hpp>

class Bleeb : public Entity{
public:
	int m_id = 2;
	Bleeb();
	~Bleeb();
	void draw()override;
	void run()override;
	void follow(CameraSystem& camSys);
private:
	sf::Sprite *bleebSprite;
	int m_x,m_y,m_s;
};