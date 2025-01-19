#pragma once
#include <SFML/Graphics.hpp>
#include "ImagesConst.h"

class Images 
{

public:
	//public functions
	static void loadAllTextures();
	static sf::Sprite getSpritePlayer();
	static sf::Sprite getSpriteGuard();
	static sf::Sprite getSpriteWall();
	static sf::Sprite getSpriteRock();
	static sf::Sprite getSpriteDoor();

private:
	//members
	static sf::Texture m_player;
	static sf::Texture m_guard;
	static sf::Texture m_wall;
	static sf::Texture m_rock;
	static sf::Texture m_door;
	
	//private funcdtions
	static void loadPlayer();
	static void loadGuard();
	static void loadWall();
	static void loadRock();
	static void loadDoor();
};