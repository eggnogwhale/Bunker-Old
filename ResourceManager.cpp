#include "ResourceManager.h"
//#pragma GCC optimize ("unroll-loops")//does this work on windows????

ResourceManager::ResourceManager(){
	loadTexSprite(DebugTex,DebugSprite,"Sprites/Tiles/Debug.png");
	loadTexSprite(GrassTex,GrassSprite,"Sprites/Tiles/Grass.png");
	loadTexSprite(redTex,redSprite,"Sprites/Tiles/Red.png");
	loadTexSprite(blueTex,blueSprite,"Sprites/Tiles/Blue.png");
	loadTexSprite(purpleTex,purpleSprite,"Sprites/Tiles/Purple.png");
	loadTexSprite(fuzzenConstructionTex,fuzzenConstructionSprite,"Sprites/Tiles/FuzzenConst.png");
	loadTexSprite(jesseConstructionTex,jesseConstructionSprite,"Sprites/Tiles/JesseConst.png");
	loadTexSprite(pathTex,pathSprite,"Sprites/Tiles/Path.png");
	
	loadTexSprite(TreeOneTex,TreeOneSprite,"Sprites/Walls/Tree1.png");
	loadTexSprite(TreeTwoTex,TreeTwoSprite,"Sprites/Walls/Tree2.png");
	
	TreeOneSprite.setOrigin(sf::Vector2f(0, 32));
	TreeTwoSprite.setOrigin(sf::Vector2f(0, 32));
	
	loadTexSprite(bleebTexture,bleebSprite,"Sprites/Actors/bleeb.png");
	
	loadTexSprite(UpTex,UpSprite,"Sprites/Actors/Player/Up.png");
	loadTexSprite(DownTex,DownSprite,"Sprites/Actors/Player/Down.png");
	loadTexSprite(LeftTex,LeftSprite,"Sprites/Actors/Player/Left.png");
	loadTexSprite(RightTex,RightSprite,"Sprites/Actors/Player/Right.png");
	
	loadTexSprite(saintTex,saintSprite,"Sprites/Actors/pixel jesus.png");
	saintSprite.setOrigin(sf::Vector2f(13, 15));
	//Texture loading
	
	numberTextures[1].loadFromFile("Sprites/Menu/One.png");
	numberTextures[2].loadFromFile("Sprites/Menu/Two.png");
	numberTextures[3].loadFromFile("Sprites/Menu/Three.png");
	numberTextures[4].loadFromFile("Sprites/Menu/Four.png");
	numberTextures[5].loadFromFile("Sprites/Menu/Five.png");
	numberTextures[6].loadFromFile("Sprites/Menu/Six.png");
	numberTextures[7].loadFromFile("Sprites/Menu/Seven.png");
	numberTextures[8].loadFromFile("Sprites/Menu/Eight.png");
	numberTextures[9].loadFromFile("Sprites/Menu/Nine.png");
	numberTextures[0].loadFromFile("Sprites/Menu/Zero.png");

    //Sprite Setup
    for (int i=0;i<10;i++){
		numberSprites[i].setTexture(numberTextures[i]);
    }
}

ResourceManager::~ResourceManager(){
	// i think we're good here
}

inline void loadTexSprite(sf::Texture& tex, sf::Sprite& sprite,const std::string& path){
	tex.loadFromFile(path);
	sprite.setTexture(tex);
}