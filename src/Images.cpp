#include "Images.h"

sf::Texture Images::m_player;
sf::Texture Images::m_guard;
sf::Texture Images::m_wall;
sf::Texture Images::m_rock;
sf::Texture Images::m_door;

//=============================================== public functions ======================================

void Images::loadAllTextures()
{
	loadPlayer();
	loadGuard();
	loadWall();
	loadRock();
	loadDoor();
}


sf::Sprite Images::getSpritePlayer()
{
	sf::Sprite sprite;
	sprite.setTexture(m_player);
	return sprite;
}


sf::Sprite Images::getSpriteGuard()
{
	sf::Sprite sprite;
	sprite.setTexture(m_guard);
	return sprite;
}


sf::Sprite Images::getSpriteWall()
{
	sf::Sprite sprite;
	sprite.setTexture(m_wall);
	return sprite;
}


sf::Sprite Images::getSpriteRock()
{
	sf::Sprite sprite;
	sprite.setTexture(m_rock);
	return sprite;
}


sf::Sprite Images::getSpriteDoor()
{
	sf::Sprite sprite;
	sprite.setTexture(m_door);
	return sprite;
}


//=============================================== public functions ======================================

void Images::loadPlayer()
{
	if (!m_player.loadFromFile(ImagesConst::NAME_PLAYER))
		std::cerr << "The image named" << ImagesConst::NAME_PLAYER << "was not loaded\n";
}


void Images::loadGuard()
{
	if (!m_guard.loadFromFile(ImagesConst::NAME_GUARD))
		std::cerr << "The image named" << ImagesConst::NAME_GUARD << "was not loaded\n";

}


void Images::loadWall()
{
	if (!m_wall.loadFromFile(ImagesConst::NAME_WALL))
		std::cerr << "The image named" << ImagesConst::NAME_WALL << "was not loaded\n";

}


void Images::loadRock()
{
	if (!m_rock.loadFromFile(ImagesConst::NAME_ROCK))
		std::cerr << "The image named" << ImagesConst::NAME_ROCK << "was not loaded\n";
}


void Images::loadDoor()
{
	if (!m_door.loadFromFile(ImagesConst::NAME_DOOR))
		std::cerr << "The image named" << ImagesConst::NAME_DOOR << "was not loaded\n";
}