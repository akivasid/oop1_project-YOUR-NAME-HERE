#include "GameWindow.h"


//================================== constructor =====================================

GameWindow::GameWindow()
	:BasicWindow(GameWindowConsts::WINDOW_SIZE, GameWindowConsts::GAME_WINDOW_NAME)
{
	
}


//================================== public functions =====================================


void GameWindow::initializer(int row, int col)
{
	m_rows = row;
	m_cols = col;
	m_tileSize = sf::Vector2f(GameWindowConsts::GAME_SIZE.x / m_cols, GameWindowConsts::GAME_SIZE.y / m_rows);
	resetIndex();
}


sf::Vector2f GameWindow::getTopLeft(const sf::Vector2f& newLocation) const
{
	if (newLocation.x > GameWindowConsts::GAME_SIZE.x || newLocation.x < 0
		|| newLocation.y > GameWindowConsts::GAME_SIZE.y || newLocation.y < 0)
		return sf::Vector2f(-1, -1);

	int row = static_cast <int> (newLocation.x / m_tileSize.x);
	int col = static_cast <int> (newLocation.y / m_tileSize.y);
	return m_boardIndex[row][col];
}


void GameWindow::resetIndex()
{
	m_boardIndex.resize(m_rows);
	for (int i = 0; i < m_rows; i++)
		for (int j = 0; j < m_cols; j++)
			m_boardIndex[i].push_back(sf::Vector2f(j * m_tileSize.x, i * m_tileSize.y));
}


void GameWindow::draw(const sf::RectangleShape& rectangle)
{
	m_window.draw(rectangle);
}


void GameWindow::draw(const sf::Text& text)
{
	m_window.draw(text);
}


void GameWindow::draw(const sf::Sprite& picture)
{
	m_window.draw(picture);
}