#include "GameWindow.h"


//================================== constructor =====================================

GameWindow::GameWindow()
	:BasicWindow(GameWindowConsts::WINDOW_SIZE, GameWindowConsts::GAME_WINDOW_NAME), m_boardIndex(),
	m_rows(0), m_cols(0), m_tileSize(0.f,0.f)
{
	m_window.setFramerateLimit(60);
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
	
	if (!inArea(newLocation))
		return sf::Vector2f(-1.f, -1.f);

	int row = static_cast <int> (newLocation.y / m_tileSize.y);
	int col = static_cast <int> (newLocation.x / m_tileSize.x);
	
	return m_boardIndex[row][col];
}

sf::Vector2f GameWindow::getNextTopLeft(const sf::Vector2f& location, const sf::Vector2f& direction) const
{
	if (direction == MovementConsts::NO_DIRECTION)
		return location;
	
	sf::Vector2f newLoc = location;
	if (direction == MovementConsts::DIRECTION_UP)
		newLoc = sf::Vector2f(location.x, location.y - m_tileSize.y);
	else if(direction == MovementConsts::DIRECTION_DOWN)
		newLoc = sf::Vector2f(location.x, location.y + m_tileSize.y);
	else if (direction == MovementConsts::DIRECTION_RIGHT)
		newLoc = sf::Vector2f(location.x + m_tileSize.x, location.y);
	else if (direction == MovementConsts::DIRECTION_LEFT)
		newLoc = sf::Vector2f(location.x - m_tileSize.x, location.y);

	if (inArea(newLoc))
		return newLoc;
	
	return location;
}


void GameWindow::resetIndex()
{
	m_boardIndex.clear();
	m_boardIndex.resize(m_rows);
	for (int i = 0; i < m_rows; i++)
		for (int j = 0; j < m_cols; j++)
			m_boardIndex[i].push_back(sf::Vector2f(j * m_tileSize.x, i * m_tileSize.y));
}

const sf::Vector2f GameWindow::getTileSize() const
{
	return m_tileSize;
}


const sf::Event GameWindow::pollEvent()
{
	sf::Event event; 
	while (m_window.pollEvent(event));
	return event;
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


bool GameWindow::inArea(const sf::Vector2f& newLocation) const
{
	if (newLocation.x >= 0 && newLocation.x <= GameWindowConsts::GAME_SIZE.x - m_tileSize.x &&//ma
		newLocation.y >= 0 && newLocation.y <= GameWindowConsts::GAME_SIZE.y - m_tileSize.y)
		return true;
	return false;
}