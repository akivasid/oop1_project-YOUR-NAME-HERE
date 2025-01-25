#include "GameManager.h"


//============================================ constructor ==================================
GameManager::GameManager()
	:m_gameInfo(), m_gameWindow()
{}

//============================================ public functions ==================================

void GameManager::runGame()
{
	setLevel();

	m_dynamic.push_back(std::make_unique <Player>(m_gameWindow.getTopLeft(sf::Vector2f(150, 50)), m_gameWindow.getTileSize()));
	//m_dynamic.push_back(std::make_unique <Player>(m_gameWindow.getTopLeft(sf::Vector2f(150, 50)), m_gameWindow.getTileSize()));
	m_dynamic.push_back(std::make_unique <Guard>(m_gameWindow.getTopLeft(sf::Vector2f(100, 500)), m_gameWindow.getTileSize()));
	m_dynamic.push_back(std::make_unique <Guard>(m_gameWindow.getTopLeft(sf::Vector2f(450, 500)), m_gameWindow.getTileSize()));
	//player(m_gameWindow.getTopLeft(sf::Vector2f(150, 50)), m_gameWindow.getTileSize());//get out of here
	

	handleEvents();
}

void GameManager::handleEvents()
{
	sf::Clock clock;
	while (m_gameWindow.isOpen())
	{
		sf::Event event = m_gameWindow.pollEvent();
		
		if(event.type == sf::Event::Closed)
		{
			m_gameWindow.close();
			break;
		}
		
		handleMovement(clock);
		updateWindow();
	}
}


void GameManager::handleMovement(sf::Clock& clock)
{
	for(int i=0; i<m_dynamic.size(); i++)
	{
		if (m_dynamic[i]->gotToTopLeft())
		{
			sf::Vector2f newDirection = m_dynamic[i]->getWantedDirection();
			sf::Vector2f newTopLeft = m_gameWindow.getNextTopLeft(m_dynamic[i]->getTopLeft(), newDirection);//check function
			m_dynamic[i]->updateMovement(newTopLeft, newDirection);
		}

		m_dynamic[i]->move(clock.getElapsedTime().asSeconds());
	}
	clock.restart();
}
//============================================ private functions ==================================

void GameManager::setLevel()
{
	int row = 0, col = 0, guards = 0;
	readFile(row, col, guards);
	m_gameInfo.initializer(guards);
	m_gameWindow.initializer(row, col);
	//get the participants vector
}

void GameManager::readFile(int& row, int& col, int& guards)
{
	//read file/playlist
	row = 20;
	col = 20;
	guards = 0;
}

void GameManager::updateWindow()
{
	m_gameWindow.clear();
	m_gameInfo.updateOutput();
	m_gameWindow.draw(m_gameInfo.getInfoRec());
	m_gameWindow.draw(m_gameInfo.getInfoOutput());
	for(int i=0; i<m_dynamic.size(); i++)
		m_gameWindow.draw(m_dynamic[i]->getParticipantSprite());
	m_gameWindow.display();
}