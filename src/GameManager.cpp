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

	while (std::getline(filePlaylist, nameLevel)) //level loop
	{
		setLevel(nameLevel);
		nameLevel.clear();
		handleEvents();
		clearObjects();
	}
}

void GameManager::handleEvents()
{
	sf::Clock clock;
	while (m_gameWindow.isOpen() && m_gameInfo.getLife()) //event loop
	{
		sf::Event event = m_gameWindow.pollEvent();
		
		if(event.type == sf::Event::Closed)
		{
			m_gameWindow.close();
			break;
		}
		
		handleMovement(clock);
		if (m_gameInfo.getPlayerStatus())
			return;
		updateWindow();
	}
}


void GameManager::handleMovement(sf::Clock& clock)
{
	for(int i=0; i<m_dynamic.size(); i++)
	{
		if (m_dynamic[i]->gotToTopLeft())
		{
			sf::Vector2f newDirection(MovementConsts::NO_DIRECTION);
			sf::Vector2f newTopLeft(m_gameWindow.getNextTopLeft(m_dynamic[i]->getTopLeft(), newDirection));
			m_dynamic[i]->updateMovement(m_gameWindow, m_gameInfo,  newDirection, newTopLeft);
			if (newDirection != MovementConsts::NO_DIRECTION)
				manageCollisions(newDirection, newTopLeft, i);
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

	//sf::sleep(sf::seconds(3));
	updateWindow();
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
	m_gameInfo.drawInfo(m_gameWindow);
	for(int i=0; i<m_dynamic.size(); i++)
		m_dynamic[i]->draw(m_gameWindow);
	for (int i = 0; i < m_static.size(); i++)
		m_static[i]->draw(m_gameWindow);
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
				if ((guards + 4) % 5 == 0) 
					m_dynamic.push_back(std::make_unique<SmartGuard>(m_gameWindow.getLocationByIndex(row, col), m_gameWindow.getTileSize()));
				else 
					m_dynamic.push_back(std::make_unique<DumbGuard>(m_gameWindow.getLocationByIndex(row, col), m_gameWindow.getTileSize()));
				break;

			case ParticipantsCharId::DOOR:
				m_static.push_back(std::make_unique<Door>(m_gameWindow.getLocationByIndex(row, col), m_gameWindow.getTileSize()));
				break;

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
	levelFile.close();
}


void GameManager::manageCollisions(sf::Vector2f& newDirection, sf::Vector2f& newTopLeft, const int i)
{
	unsigned prevLife = m_gameInfo.getLife();
	for (int j = 0; j < m_dynamic.size(); j++)
	{
		if (i != j)
			m_dynamic[i]->handleCollision(m_gameInfo, *m_dynamic[j], newDirection, newTopLeft);
		if (m_gameInfo.getLife() != prevLife)
		{
			manageFirstLocations();
			return;
		}
	}

	for (int k = 0; k < m_static.size(); k++)
		m_dynamic[i]->handleCollision(m_gameInfo, *m_static[k], newDirection, newTopLeft);

	m_dynamic[i]->finalMovement(newTopLeft, newDirection);
}

void GameManager::manageFirstLocations()
{
	for (int i = 0; i < m_dynamic.size(); i++)
		m_dynamic[i]->resetLocation();//does not update the player location in gameInformation
}

void GameManager::clearObjects()
{
	m_dynamic.clear();
	m_static.clear();
}