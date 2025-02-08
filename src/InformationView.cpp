#include "InformationView.h"


// ======================================= constructor ==========================

InformationView::InformationView()
	: m_rectangle(GameInfoConsts::INFO_SIZE), m_levelText(FontHolder::getText()), m_lifeText(FontHolder::getText()),
	m_timeText(FontHolder::getText()), m_scoreText(FontHolder::getText())
{
	m_rectangle.setPosition(GameInfoConsts::INFO_LOCATION);
	m_rectangle.setFillColor(GameInfoConsts::INFO_COLOR);
	m_lifeText.setPosition(GameInfoConsts::LIFE_TEXT_LOCATION);
	m_timeText.setPosition(GameInfoConsts::TIME_TEXT_LOCATION);
	m_scoreText.setPosition(GameInfoConsts::SCORE_TEXT_LOCATION);
	m_levelText.setPosition(GameInfoConsts::LEVEL_TEXT_LOCATION);
}

// ======================================= public functions=================================

void InformationView::updateOutput(const unsigned level, const int life, const unsigned score, const float timeLeft)
{
	levelOutput(level);
	lifeOutput(life);
	scoreOutput(score);
	timeOutput(timeLeft);
}


void InformationView::draw(GameWindow& window)
{
	window.draw(m_rectangle);
	window.draw(m_lifeText);
	window.draw(m_timeText);
	window.draw(m_levelText);
	window.draw(m_scoreText);
}


void InformationView::drawLevel(GameWindow& window)
{
	sf::Text level = m_levelText;
	drawTransitions(window, level);
}


void InformationView::drawEndGame(GameWindow& window)
{
	sf::Text text = FontHolder::getText();
	text.setString(GameInfoConsts::GAME_OVER_OUTPUT);
	drawTransitions(window, text);
}


void InformationView::drawWonGame(GameWindow& window)
{
	sf::Text text = FontHolder::getText();
	text.setString(GameInfoConsts::GAME_WON_OUTPUT);
	drawTransitions(window, text);
}


void InformationView::drawLostLife(GameWindow& window)
{
	sf::Text text = m_lifeText;
	drawTransitions(window, text);
}


// ======================================= private functions =====================================

void InformationView::drawTransitions(GameWindow& window, sf::Text& text)
{
	text.setCharacterSize(100);

	float sizeX = text.getGlobalBounds().width;
	float sizeY = text.getGlobalBounds().height;
	text.setOrigin(sf::Vector2f(sizeX / 2, sizeY / 2));
	sf::Vector2f center(GameWindowConsts::GAME_SIZE.x / 2, GameWindowConsts::GAME_SIZE.y / 2);
	text.setPosition(sf::Vector2f(center));

	window.clear();
	window.draw(text);
	window.display();
	sf::sleep(sf::seconds(1));
}


void InformationView::levelOutput(const unsigned level)
{
	std::string levelStr = GameInfoConsts::LEVEL_OUTPUT + std::to_string(level);
	m_levelText.setString(levelStr);

}


void InformationView::lifeOutput(const int life)
{
	std::string lifeStr = GameInfoConsts::LIFE_OUTPUT + std::to_string(life);
	m_lifeText.setString(lifeStr);
}


void InformationView::scoreOutput(const unsigned score)
{
	std::string scoreStr = GameInfoConsts::SCORE_OUTPUT + std::to_string(score);
	m_scoreText.setString(scoreStr);
}


void InformationView::timeOutput(const float timeLeft)
{
	std::string timeStr = GameInfoConsts::TIME_OUTPUT + std::to_string(static_cast <int>(timeLeft) / 60)
		+ ":" + (((static_cast <int>(timeLeft) % 60) < 10) ? "0" : "")
		+ std::to_string(static_cast <int>(timeLeft) % 60);

	m_timeText.setString(timeStr);
}