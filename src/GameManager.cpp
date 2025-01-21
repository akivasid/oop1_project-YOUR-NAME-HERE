#include "GameManager.h"


//============================================ constructor ==================================
GameManager::GameManager()
	:m_gameInfo(), m_gameWindow()
{}

//============================================ public functions ==================================

void GameManager::runGame()
{
	int row = 0;
	int col = 0;
	int guards = 0;
	readFile(row, col, guards);
	m_gameInfo.initializer(guards);
	m_gameWindow.initializer(row, col);
	std::cout << m_gameWindow.getTileSize().x << ", " << m_gameWindow.getTileSize().y;
	Player player(m_gameWindow.getTopLeft(sf::Vector2f(150, 50)), m_gameWindow.getTileSize());


	while (m_gameWindow.isOpen())
	{
		sf::Event event = m_gameWindow.pollEvent();
		

		switch (event.type)
		{
		case sf::Event::Closed:
			m_gameWindow.close();
			break;
		}

		player.move();
			
		
		m_gameWindow.clear();
		m_gameInfo.updateOutput();
		m_gameWindow.draw(m_gameInfo.getInfoRec());
		m_gameWindow.draw(m_gameInfo.getInfoOutput());
		m_gameWindow.draw(player.getParticipantSprite());
		m_gameWindow.display();
	}



}


//============================================ private functions ==================================

void GameManager::readFile(int& row, int& col, int& guards)
{
	//read file/playlist
	row = 10;
	col = 10;
}