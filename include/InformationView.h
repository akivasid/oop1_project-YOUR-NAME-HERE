#pragma once
#include <SFML/Graphics.hpp>
#include "FontHolder.h"
#include "GameInfoConsts.h"
#include "GameWindow.h"

class InformationView
{
public:
	InformationView();

	void updateOutput(const unsigned level, const int life, const unsigned score, const float timeLeft);
	void draw(GameWindow& window);
	void drawLevel(GameWindow& window);
	void drawEndGame(GameWindow& window);
	void drawLostLife(GameWindow& window);
	void drawWonGame(GameWindow& window);



private:
	//members
	sf::Text m_levelText;
	sf::Text m_lifeText;
	sf::Text m_scoreText;
	sf::Text m_timeText;
	sf::RectangleShape m_rectangle;

	//private functions 
	void levelOutput(const unsigned level);
	void lifeOutput(const int life);
	void scoreOutput(const unsigned score);
	void timeOutput(const float timeLeft);
	void drawTransitions(GameWindow& window, sf::Text& text);

};