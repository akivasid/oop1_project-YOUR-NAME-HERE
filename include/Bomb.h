#pragma once
#include "Participant.h"
#include "BombConst.h"
#include "FontHolder.h"

class Player;



class Bomb : public Participant
{
public:
	//constructor
	Bomb(const sf::Vector2f& location, const sf::Vector2f& wantedSize);

	//dtor

	//public functions
	bool bombExploded() const;
	bool bombExpired() const;
	void bombStateUpdate();
	bool inExplosionArea(const sf::Vector2f& location);
	void drawBomb(GameWindow& gameWindow);
	void validationUpdate(const sf::Vector2f& location);
	
	void handleCollision(Participant& obj, GameInformation& gameInfo) override;
	void handleCollision(SmartGuard& guard, GameInformation& gameInfo) override;
	void handleCollision(DumbGuard& guard, GameInformation& gameInfo) override;
	void handleCollision(Player& player, GameInformation& gameInfo) override;
	void handleCollision(Bomb& bomb, GameInformation& gameInfo) override;


private:
	//members
	sf::Sprite m_upPicture;
	sf::Sprite m_downPicture;
	sf::Sprite m_rightPicture;
	sf::Sprite m_leftPicture;

	sf::Vector2f m_upLocation;
	sf::Vector2f m_downLocation;
	sf::Vector2f m_rightLocation;
	sf::Vector2f m_leftLocation;

	bool m_upValidation;
	bool m_downValidation;
	bool m_rightValidation;
	bool m_leftValidation;

	sf::Clock m_clock;
	sf::Time m_countDown;
	sf::Time m_explosionTime;
	sf::Text m_timerText;
	sf::Music m_countDownSound;
	sf::Music m_explosionSound;
	bool m_bombExploded;
	bool m_bombExpired;

	//public functions
	void setExplosionPictures(const sf::Vector2f& wantedSize);
	void setExplosionLocation(const sf::Vector2f& location, const sf::Vector2f& wantedSize);
	void updateTimerText();
	void loadBombSounds();
};