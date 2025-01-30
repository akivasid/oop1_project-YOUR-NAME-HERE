#include "Images.h"

std::vector <sf::Texture> Images::m_pictures;

//=============================================== public functions ======================================

void Images::loadAllTextures()
{
	loadPlayer();
	loadGuard();
	loadDoor();
	loadRock();
	loadWall();
	loadBomb();
	loadExplosion();
}


sf::Sprite Images::getSprite(const ParticipantType& type, const sf::Vector2f& wantedSize)//check for memory exception
{
	int index = static_cast<int>(type);
	
	sf::Sprite sprite;
	sprite.setTexture(m_pictures[index]);
	float scaleX =  wantedSize.x / m_pictures[index].getSize().x;
	float scaleY =  wantedSize.y / m_pictures[index].getSize().y;
	sprite.setScale(sf::Vector2f(scaleX, scaleY));

	return sprite;
}


//=============================================== private functions ======================================


void Images::loadPlayer()
{
	if (!m_pictures.emplace_back().loadFromFile(ImagesConst::NAME_PLAYER))
		std::cerr << "The image named" << ImagesConst::NAME_PLAYER << "was not loaded\n";
}


void Images::loadGuard()
{
	if (!m_pictures.emplace_back().loadFromFile(ImagesConst::NAME_GUARD))
		std::cerr << "The image named" << ImagesConst::NAME_GUARD << "was not loaded\n";

}


void Images::loadWall()
{
	if (!m_pictures.emplace_back().loadFromFile(ImagesConst::NAME_WALL))
		std::cerr << "The image named" << ImagesConst::NAME_WALL << "was not loaded\n";

}


void Images::loadRock()
{
	if (!m_pictures.emplace_back().loadFromFile(ImagesConst::NAME_ROCK))
		std::cerr << "The image named" << ImagesConst::NAME_ROCK << "was not loaded\n";
}


void Images::loadDoor()
{
	if (!m_pictures.emplace_back().loadFromFile(ImagesConst::NAME_DOOR))
		std::cerr << "The image named" << ImagesConst::NAME_DOOR << "was not loaded\n";
}

void Images::loadBomb()
{
	if (!m_pictures.emplace_back().loadFromFile(ImagesConst::NAME_BOMB))
		std::cerr << "The image named" << ImagesConst::NAME_BOMB << "was not loaded\n";
}


void Images::loadExplosion()
{
	if (!m_pictures.emplace_back().loadFromFile(ImagesConst::NAME_EXPLOSION))
		std::cerr << "The image named" << ImagesConst::NAME_EXPLOSION << "was not loaded\n";
}