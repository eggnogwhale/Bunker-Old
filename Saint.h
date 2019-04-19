#pragma once
#include <SFML/Graphics.hpp>
#include "Entity.h"

class Saint: public Entity{
	public:
		int m_id=666;
		Saint(int sp);
		void run();
		void draw();
	private:
		sf::Sprite *saintSprite;
		int m_x=666,m_y=666, m_sp=0;
		int nextTreeX=0, nextTreeY=0;
		void findNext();
};