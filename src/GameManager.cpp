#include "GameManager.h"


//============================================ constructor ==================================
GameManager::GameManager()
	:m_gameInfo(), m_gameWindow()
{}

//============================================ public functions ==================================

void GameManager::runGame()
{
	std::fstream filePlaylist(GameWindowConsts::NAME_PLAYLIST_LEVELS);
	std::string nameLevel; 

	while (std::getline(filePlaylist, nameLevel)) 
	{
		setLevel(nameLevel);
		handleEvents();
		nameLevel.clear();
	}
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
			/*for (int j = 0; j < m_dynamic.size(); j++)
			{
				if (i != j)
					m_dynamic[i]->handleCollision(m_gameInfo, newTopLeft, newDirection, *m_dynamic[j]);
			}*/
			sf::Vector2f newDirection(MovementConsts::NO_DIRECTION);
			sf::Vector2f newTopLeft(m_gameWindow.getNextTopLeft(m_dynamic[i]->getTopLeft(), newDirection));
			m_dynamic[i]->updateMovement(m_gameWindow, m_gameInfo,  newDirection, newTopLeft);
			if(newDirection != MovementConsts::NO_DIRECTION)
			{
				for (int k = 0; k < m_static.size(); k++)
					m_dynamic[i]->handleCollision(m_gameWindow, m_gameInfo, *m_static[k], newDirection, newTopLeft);

				m_dynamic[i]->finalMovement(newTopLeft, newDirection);
			}

		}

		m_dynamic[i]->move(clock.getElapsedTime().asSeconds());
	}

	clock.restart();
}

//============================================ private functions ==================================

void GameManager::setLevel(const std::string& nameLevel)
{
	int row = 0, col = 0, guards = 0;
	readFile(row, col, nameLevel);
	m_gameWindow.initializer(row, col);
	updateObjects(nameLevel, guards);
	m_gameInfo.initializer(guards);
}
	

void GameManager::readFile(int& row, int& col, const std::string& nameLevel)
{
	std::fstream levelFile(nameLevel);
	std::string line;

	while (std::getline(levelFile, line)) 
	{
		row++;
		col = static_cast<int> (line.size());
	}

	levelFile.close();
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


void GameManager::updateObjects(const std::string& nameLevel, int& guards)
{
	std::fstream levelFile(nameLevel);
	levelFile.clear();
	levelFile.seekg(0);

	std::string line;
	int row = 0;
	char ch = ' ';

	while (std::getline(levelFile, line)) 
	{
		for (int col = 0; col < line.size(); col++)
		{
			ch = line[col];
			switch (ch)
			{
			case ParticipantsCharId::PLAYER:
				m_dynamic.push_back(std::make_unique<Player>(m_gameWindow.getLocationByIndex(row, col), m_gameWindow.getTileSize()));
				m_gameInfo.setPlayerLocation(m_dynamic[m_dynamic.size()-1]->getTopLeft());
				break;

			case ParticipantsCharId::GUARD:
				guards++;
				if ((guards + 2) % 3 == 0) 
					m_dynamic.push_back(std::make_unique<SmartGuard>(m_gameWindow.getLocationByIndex(row, col), m_gameWindow.getTileSize()));
				else 
					m_dynamic.push_back(std::make_unique<DumbGuard>(m_gameWindow.getLocationByIndex(row, col), m_gameWindow.getTileSize()));
				break;

				/*case ParticipantsCharId::DOOR
				m_static.push_back(std::make_unique<Door>(m_gameWindow.getIndexPixel(row, col), m_gameWindow.getSizeTile()));
				break;*/

			case ParticipantsCharId::ROCK:
				m_static.push_back(std::make_unique<Rock>(m_gameWindow.getLocationByIndex(row, col), m_gameWindow.getTileSize()));
				break;

			case ParticipantsCharId::WALL:
				m_static.push_back(std::make_unique<Wall>(m_gameWindow.getLocationByIndex(row, col), m_gameWindow.getTileSize()));
				break;

			default:
				break;
			}
		}
		row++;
	}
}

