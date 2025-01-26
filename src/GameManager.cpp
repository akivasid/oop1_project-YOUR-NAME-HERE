#include "GameManager.h"


//============================================ constructor ==================================
GameManager::GameManager()
	:m_gameInfo(), m_gameWindow()
{}

//============================================ public functions ==================================

void GameManager::runGame()
{
	setLevel();
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
			if (newDirection == MovementConsts::NO_DIRECTION)
				continue;
			sf::Vector2f newTopLeft = m_gameWindow.getNextTopLeft(m_dynamic[i]->getTopLeft(), newDirection);
			
			/*for (int j = 0; j < m_dynamic.size(); j++)
			{
				if (i != j)
					m_dynamic[i]->handleCollision(m_gameInfo, newTopLeft, newDirection, *m_dynamic[j]);
			}*/

			for(int k=0; k<m_static.size(); k++)
				m_dynamic[i]->handleCollision(m_gameInfo, newTopLeft, newDirection, *m_static[k]);

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
	
	//m_dynamic.push_back(std::make_unique <Player>(m_gameWindow.getTopLeft(sf::Vector2f(150, 50)), m_gameWindow.getTileSize()));
	m_dynamic.push_back(std::make_unique <Guard>(m_gameWindow.getTopLeft(sf::Vector2f(982.f, 350.f)), m_gameWindow.getTileSize()));
	m_dynamic.push_back(std::make_unique <Guard>(m_gameWindow.getTopLeft(sf::Vector2f(950.f, 550.f)), m_gameWindow.getTileSize()));
	m_dynamic.push_back(std::make_unique <Player>(m_gameWindow.getTopLeft(sf::Vector2f(150.f, 50.f)), m_gameWindow.getTileSize()));
	m_dynamic.push_back(std::make_unique <Guard>(m_gameWindow.getTopLeft(sf::Vector2f(999.f,999.f)), m_gameWindow.getTileSize()));
	m_dynamic.push_back(std::make_unique <Guard>(m_gameWindow.getTopLeft(sf::Vector2f(100.f,900.f)), m_gameWindow.getTileSize()));
	m_static.push_back(std::make_unique <Wall>(m_gameWindow.getTopLeft(sf::Vector2f(0.f, 0.f)), m_gameWindow.getTileSize()));
	m_static.push_back(std::make_unique <Wall>(m_gameWindow.getTopLeft(sf::Vector2f(342.f, 654.f)), m_gameWindow.getTileSize()));
	m_static.push_back(std::make_unique <Rock>(m_gameWindow.getTopLeft(sf::Vector2f(0, 300.f)), m_gameWindow.getTileSize()));
	m_static.push_back(std::make_unique <Rock>(m_gameWindow.getTopLeft(sf::Vector2f(900.f, 0)), m_gameWindow.getTileSize()));

}

void GameManager::readFile(int& row, int& col, int& guards)
{
	//read file/playlist
	row = 14;
	col = 14;
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
	for (int i = 0; i < m_static.size(); i++)
		m_gameWindow.draw(m_static[i]->getParticipantSprite());
	m_gameWindow.display();
}