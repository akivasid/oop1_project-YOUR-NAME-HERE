#include "Bomb.h"


Bomb::Bomb(const sf::Vector2f& location, const sf::Vector2f& wantedSize)
	:Participant(location, wantedSize, ParticipantType::Bomb), m_clock(), m_countDown(BombConst::COUNT_DOWN),
	m_explosionTime(BombConst::EXPLOSION_TIME),	m_bombExploded(false), m_bombExpired(false),
	m_upValidation(true), m_downValidation(true), m_rightValidation(true), m_leftValidation(true), m_timerText(FontHolder::getText())
{
	setExplosionLocation(location, wantedSize);
	setExplosionPictures(wantedSize);
	m_timerText.setPosition(sf::Vector2f(m_topLeft.x , m_topLeft.y ));
	m_timerText.setCharacterSize(20);
	m_timerText.setFillColor(sf::Color::Red);
	loadBombSounds();	
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
			m_countDownSound.stop();
			m_explosionSound.stop();
			setDead();
		}

		else if(!m_bombExploded)
		{
			m_countDownSound.stop();
			m_explosionSound.play();
			m_bombExploded = true;
			m_bombExpired = false;
		}
	}
}

void Bomb::validationUpdate(const sf::Vector2f& location)
{
	if (location == m_downLocation)
		m_downValidation = false;
	else if (location == m_upLocation)
		m_upValidation = false;
	else if (location == m_rightLocation)
		m_rightValidation = false;
	else if (location == m_leftLocation)
		m_leftValidation = false;
}

bool Bomb::bombExploded() const
{
	return m_bombExploded;
}

bool Bomb::bombExpired() const
{
	return m_bombExpired;
}


void Bomb::handleCollision(Participant& obj, GameInformation& gameInfo)
{
	obj.handleCollision(*this, gameInfo);
}

void Bomb::handleCollision(Player& player, GameInformation& gameInfo)
{}


void Bomb::handleCollision(SmartGuard& guard, GameInformation& gameInfo)
{}

void Bomb::handleCollision(DumbGuard& guard, GameInformation& gameInfo)
{}

void Bomb::handleCollision(Bomb& bomb, GameInformation& gameInfo) 
{}


bool Bomb::inExplosionArea(const sf::Vector2f& location)
{
	if (location == m_upLocation || location == m_downLocation ||
		location == m_rightLocation || location == m_leftLocation || location == m_topLeft)
		return true;
	return false;
}

void Bomb::drawBomb(GameWindow& gameWindow)
{
	
	if (m_bombExploded)
	{
		m_picture = m_downPicture;
		m_picture.setPosition(m_topLeft);
		if (gameWindow.inArea(m_downLocation) && m_downValidation)
			gameWindow.draw(m_downPicture);
		if (gameWindow.inArea(m_leftLocation) && m_leftValidation)
			gameWindow.draw(m_leftPicture);
		if (gameWindow.inArea(m_rightLocation) && m_rightValidation)
			gameWindow.draw(m_rightPicture);
		if (gameWindow.inArea(m_upLocation) && m_upValidation)
			gameWindow.draw(m_upPicture);
	}

	draw(gameWindow);

	if(!m_bombExploded && !m_bombExpired)
	{
		updateTimerText();
		gameWindow.draw(m_timerText);
	}
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

void Bomb::updateTimerText()
{
	int secondsLeft = static_cast<int>(m_countDown.asSeconds() - m_clock.getElapsedTime().asSeconds());
	std::string str = std::to_string(secondsLeft);
	m_timerText.setString(str);
}

void Bomb::loadBombSounds()
{
	if (!m_countDownSound.openFromFile(BombConst::COUNT_DOWN_SOUND))
		std::cerr << "failed to open file " << BombConst::COUNT_DOWN_SOUND;
	if (!m_explosionSound.openFromFile(BombConst::EXPLOSION_SOUND))
		std::cerr << "failed to open file " << BombConst::EXPLOSION_SOUND;
	m_countDownSound.play();
}