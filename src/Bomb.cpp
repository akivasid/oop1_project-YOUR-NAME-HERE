#include "Bomb.h"


Bomb::Bomb(const sf::Vector2f& location, const sf::Vector2f& wantedSize)
	:Participant(location, wantedSize, ParticipantType::Bomb), m_clock(), m_countDown(BombConst::COUNT_DOWN),
	m_explosionTime(BombConst::EXPLOSION_TIME),	m_bombExploded(false), m_bombExpired(false),
	m_upValidation(true), m_downValidation(true), m_rightValidation(true), m_leftValidation(true)
{
	setExplosionLocation(location, wantedSize);
	setExplosionPictures(wantedSize);
}


void Bomb::bombStateUpdate()
{
	if (m_clock.getElapsedTime() >= m_countDown)
	{
		if (m_clock.getElapsedTime() >= m_countDown + m_explosionTime)
		{
			m_bombExploded = false;
			m_bombExpired = true;
			m_objectState = false;
		}

		else
		{
			m_bombExploded = true;
			m_bombExpired = false;
		}
	}
}

bool Bomb::bombExploded() const//maybe not needed
{
	return m_bombExploded;
}

bool Bomb::bombExpired() const//maybe not needed
{
	return m_bombExpired;
}


void Bomb::handleCollision(Participant& obj, GameInformation& gameInfo)
{
	obj.handleCollision(*this, gameInfo);
}

void Bomb::handleCollision(Player& player, GameInformation& gameInfo)
{
	if (bombExploded() && inExplosionArea(gameInfo.getPlayerLocation()))
		gameInfo.setLife();
}

void Bomb::handleCollision(SmartGuard& guard, GameInformation& gameInfo)
{
	/*if (bombExploded() && inExplosionArea(guard.getTopLeft()))
		guard.setDead();*/
}

void Bomb::handleCollision(DumbGuard& guard, GameInformation& gameInfo)
{
	/*if (bombExploded() && inExplosionArea(guard.getTopLeft()))
		guard.setDead();*/
}

void Bomb::handleCollision(Bomb& bomb, GameInformation& gameInfo) 
{}


bool Bomb::inExplosionArea(const sf::Vector2f& location)
{
	if (location == m_upLocation || location == m_downLocation ||
		location == m_rightLocation || location == m_leftLocation || location == m_topLeft)
		return true;
	return false;
}


void Bomb::setExplosionLocation(const sf::Vector2f& location, const sf::Vector2f& wantedSize)
{
	m_downLocation = sf::Vector2f(location.x, location.y + wantedSize.y);
	m_leftLocation = sf::Vector2f(location.x - wantedSize.x, location.y);
	m_rightLocation = sf::Vector2f(location.x + wantedSize.x, location.y);
	m_upLocation = sf::Vector2f(location.x, location.y - wantedSize.y);
}

void Bomb::setExplosionPictures(const sf::Vector2f& wantedSize)
{
	m_downPicture = Images::getSprite(ParticipantType::Explasion, wantedSize);
	m_downPicture.setPosition(m_downLocation);
	m_upPicture = Images::getSprite(ParticipantType::Explasion, wantedSize);
	m_upPicture.setPosition(m_upLocation);
	m_rightPicture = Images::getSprite(ParticipantType::Explasion, wantedSize);
	m_rightPicture.setPosition(m_rightLocation);
	m_leftPicture = Images::getSprite(ParticipantType::Explasion, wantedSize);
	m_leftPicture.setPosition(m_leftLocation);
}