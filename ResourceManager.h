#pragma once
#include <SFML/Graphics.hpp>
#include <stdlib.h>

struct ResourceManager{
	/////////////////////////////////////////Textures/////////////////////////////////////////////////
	sf::Texture numberTextures[10];
	
	sf::Texture UpTex;
	sf::Texture DownTex;
	sf::Texture LeftTex;
	sf::Texture RightTex;
	
	sf::Texture bleebTexture;
	
	sf::Texture DebugTex;
	
	sf::Texture GrassTex;
	sf::Texture redTex;
	sf::Texture blueTex;
	sf::Texture purpleTex;
	sf::Texture jesseConstructionTex;
	sf::Texture fuzzenConstructionTex;
	sf::Texture pathTex;
	
	sf::Texture TreeOneTex;
	sf::Texture TreeTwoTex;
	
	sf::Texture saintTex;
	
	//////////////////////////////////////////Sprites////////////////////////////////////////////////
	sf::Sprite numberSprites[10];
	
	sf::Sprite UpSprite;
	sf::Sprite DownSprite;
	sf::Sprite LeftSprite;
	sf::Sprite RightSprite;
	
	sf::Sprite bleebSprite;

	sf::Sprite DebugSprite;
	
	sf::Sprite GrassSprite;
	sf::Sprite redSprite;
	sf::Sprite blueSprite;
	sf::Sprite purpleSprite;
	sf::Sprite jesseConstructionSprite;
	sf::Sprite fuzzenConstructionSprite;
	sf::Sprite pathSprite;

	sf::Sprite TreeOneSprite;
	sf::Sprite TreeTwoSprite;
	
	sf::Sprite saintSprite;
	
	ResourceManager();
	~ResourceManager();
};
void loadTexSprite(sf::Texture& tex, sf::Sprite& sprite,const std::string& path);