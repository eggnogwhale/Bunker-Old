#include "Saint.h"
#include "Header.h"

Saint::Saint(int sp){
	m_sp = sp;
	saintSprite = &ResourcePass->saintSprite;
	findNext();
}
void Saint::run(){
	m_x += m_sp * (m_x/32>nextTreeX?-1:1);
	m_y += m_sp * (m_y/32>nextTreeY?-1:1);
	
	int TilePosX = (m_x - (m_x % 32)) / 32;
	int TilePosY = (m_y - (m_y % 32)) / 32;
	int cTile = WorldTilePass->WorldWallMap[TilePosX][TilePosY];
	if (TilePosX == 1 || cTile == 2 ||
		(TilePosX == nextTreeX & TilePosY == nextTreeY))
	{
		WorldTilePass->WorldWallMap[TilePosX][TilePosY] = 0;
		findNext();
	}
}
void Saint::draw(){
	saintSprite->setPosition(sf::Vector2f(m_x, m_y));
	WindowPass->draw(*saintSprite);
}
void Saint::findNext(){
	int TilePosX = (m_x - (m_x % 32)) / 32;
	int TilePosY = (m_y - (m_y % 32)) / 32;
	int dist = 1;
	for(;;){
		// right side
		for (int y=0;y<dist*2;y++){
			if (WorldTilePass->WorldWallMap[TilePosX+dist][TilePosY+y] == 2 || 
				WorldTilePass->WorldWallMap[TilePosX+dist][TilePosY+y] == 1){
				nextTreeX = (TilePosX+dist);
				nextTreeY = (TilePosY+y);
				return;
			}
		}
		//bottom
		for (int x=0;x<1+dist*2;x++){
			if (WorldTilePass->WorldWallMap[TilePosX-dist+x][TilePosY+dist] == 2 || 
				WorldTilePass->WorldWallMap[TilePosX-dist+x][TilePosY+dist] == 1){
				nextTreeX = (TilePosX-dist+x);
				nextTreeY = (TilePosY+dist);
				return;
			}
		}
		//top
		for (int x=0;x<1+dist*2;x++){
			if (WorldTilePass->WorldWallMap[TilePosX-dist+x][TilePosY-dist] == 2 || 
				WorldTilePass->WorldWallMap[TilePosX-dist+x][TilePosY-dist] == 1){
				nextTreeX = (TilePosX-dist+x);
				nextTreeY = (TilePosY-dist);
				return;
			}
		}
		//left side
		for (int y=0;y<dist*2;y++){
			if (WorldTilePass->WorldWallMap[TilePosX-dist][TilePosY+y] == 2 || 
				WorldTilePass->WorldWallMap[TilePosX-dist][TilePosY+y] == 1){
				nextTreeX = (TilePosX-dist);
				nextTreeY = (TilePosY+y);
				return;
			}
		}
		dist++;
	}
}