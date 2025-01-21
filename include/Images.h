#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "ImagesConst.h"
#include "ParticipantType.h"

class Images 
{

public:
	//public functions
	static void loadAllTextures();
	static sf::Sprite getSprite(const ParticipantType& type, const sf::Vector2f& wantedSize);
	
	
private:
	//members
	static std::vector <sf::Texture> m_pictures;
	
	//private funcdtions
	static void loadPlayer();
	static void loadGuard();
	static void loadWall();
	static void loadRock();
	static void loadDoor();
};