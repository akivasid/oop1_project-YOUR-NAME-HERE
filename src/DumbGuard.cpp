#include "DumbGuard.h"

// ============================================== constructor ===================================================
DumbGuard::DumbGuard(const sf::Vector2f& location, const sf::Vector2f& wantedSize)
	:Guard(location, wantedSize)
{}

// ============================================== public functions ===================================================

void DumbGuard::updateMovement(GameWindow& gameWindow, GameInformation& gameInfo)
{
	
	changeDirection();
	sf::Vector2f newTopLeft = gameWindow.getNextTopLeft(m_topLeft, m_direction);
	if (gameWindow.inArea(newTopLeft))
		m_topLeft = newTopLeft;
	else
		m_direction = MovementConsts::NO_DIRECTION;
}


void DumbGuard::handleCollision(Participant& obj, GameInformation& gameInfo)
{
	if (gameInfo.getKillGuard())
	{
		setDead();
		m_direction = MovementConsts::NO_DIRECTION;
		gameInfo.setKillGuard(false);
		gameInfo.setScoreKillGuard();
		return;
	}

	if(gameInfo.getFreezeGuards())
	{
		m_direction = MovementConsts::NO_DIRECTION;
		return;
	}

	obj.handleCollision(*this, gameInfo);
}

void DumbGuard::handleCollision(SmartGuard& guard, GameInformation& gameInfo)
{}


void DumbGuard::handleCollision(Player& player, GameInformation& gameInfo)
{
	if (gameInfo.getPlayerLocation() == m_topLeft)
		gameInfo.lostLife();
}


void DumbGuard::handleCollision(DumbGuard& guard, GameInformation& gameInfo)
{}


void DumbGuard::handleCollision(Bomb& bomb, GameInformation& gameInfo)
{
	if (bomb.bombExploded() && bomb.inExplosionArea(m_topLeft))
	{
		setDead();
		gameInfo.setScoreKillGuard();
	}

}

//================================================ private function ==========================================
void DumbGuard::changeDirection()
{
	int directionRandom = std::rand() % 4;
	switch (directionRandom)
	{
	case  0:
		m_direction = MovementConsts::DIRECTION_RIGHT;
		return;
	case 1:
		m_direction = MovementConsts::DIRECTION_LEFT;
		return;
	case 2:
		m_direction = MovementConsts::DIRECTION_UP;
		return;
	case 3:
		m_direction = MovementConsts::DIRECTION_DOWN;
		return;
	}
	m_direction = MovementConsts::NO_DIRECTION;
}