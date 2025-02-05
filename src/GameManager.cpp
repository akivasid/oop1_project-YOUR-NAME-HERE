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
		if (m_gameInfo.getLife() <= 0 && m_gameWindow.isOpen())
			break;
	}
}

//============================================ private functions ==================================


void GameManager::handleEvents()
{
	sf::Clock clock;
	while (m_gameWindow.isOpen()) //event loop
	{
		sf::Event event = m_gameWindow.pollEvent();
		
		if(event.type == sf::Event::Closed)
		{
			m_gameWindow.close();
			break;
		}

		if (event.type == sf::Event::KeyPressed)
			if(event.key.code == sf::Keyboard::B)
				createBomb();
			
		handleBombs();
		if (m_gameInfo.getLife() <= 0)
			return;
		
		handleMovement(clock);
		if (m_gameInfo.getPlayerStatus() || m_gameInfo.getLife() <= 0)
			return;
		
		
		clearDeadObjects();
		updateWindow();
	}
}


void GameManager::handleBombs()
{
	for (int i = 0; i < m_bombs.size(); i++)
	{
		m_bombs[i]->bombStateUpdate();
		if (m_bombs[i]->bombExploded())
			handleBombCollisions(i);
	}
}


void GameManager::handleBombCollisions(int i)
{
	int prevLife = m_gameInfo.getLife();
	for (int j = 0; j < m_dynamic.size(); j++)
	{
		m_bombs[i]->handleCollision(*m_dynamic[j], m_gameInfo);
		if (m_gameInfo.getLife() == (prevLife - 1))
		{
			m_bombs.clear();
			manageFirstLocations();
			return;
		}
	}

	for (int j = 0; j < m_static.size(); j++)
		m_bombs[i]->handleCollision(*m_static[j], m_gameInfo);
}


void GameManager::handleMovement(sf::Clock& clock)
{
	for(int i=0; i<m_dynamic.size(); i++)
	{
		if (m_dynamic[i]->gotToTopLeft())
		{
			sf::Vector2f prevTopLeft(m_dynamic[i]->getTopLeft());
			m_dynamic[i]->updateMovement(m_gameWindow, m_gameInfo);
			if (m_dynamic[i]->getDirection() != MovementConsts::NO_DIRECTION)
				manageDynamicCollisions(prevTopLeft, i);
		}

		m_dynamic[i]->move(clock.getElapsedTime().asSeconds());
	}

	clock.restart();
}


void GameManager::createBomb()
{
	m_bombs.push_back(std::make_unique<Bomb>(m_gameInfo.getPlayerLocation(), m_gameWindow.getTileSize()));
}


void GameManager::manageDynamicCollisions(const sf::Vector2f& prevTopLeft, const int i)
{
	int prevLife = m_gameInfo.getLife();

	for (int j = 0; j < m_static.size(); j++)//static 
	{
		m_dynamic[i]->handleCollision(*m_static[j], m_gameInfo);
		if (m_dynamic[i]->getDirection() == MovementConsts::NO_DIRECTION)
			m_dynamic[i]->setTopLeft(prevTopLeft);	
		if(m_gameInfo.getPlayerStatus())
			return;
	}

	for (int j = 0; j < m_dynamic.size(); j++)//dynamic
	{
		m_dynamic[i]->handleCollision(*m_dynamic[j], m_gameInfo);

		if (m_gameInfo.getLife() == (prevLife - 1))
		{
			m_bombs.clear();
			manageFirstLocations();
			return;
		}
	}
}


void GameManager::clearDeadObjects()
{
	std::erase_if(m_bombs, [](const auto& object) {return !object->getDeadOrAlive(); });
	std::erase_if(m_dynamic, [](const auto& object) {return !object->getDeadOrAlive(); });
	std::erase_if(m_static, [](const auto& object) {return !object->getDeadOrAlive(); });
}


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

	
	for (int i = 0; i < m_static.size(); i++)
		m_static[i]->draw(m_gameWindow);
	for (int i = 0; i < m_bombs.size(); i++)
		m_bombs[i]->drawBomb(m_gameWindow);
	for(int i=0; i<m_dynamic.size(); i++)
		m_dynamic[i]->draw(m_gameWindow);
	
	
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
				createGifts(row, col);
				m_static.push_back(std::make_unique<Rock>(m_gameWindow.getLocationByIndex(row, col), m_gameWindow.getTileSize()));
				break;

			case ParticipantsCharId::WALL:
				m_static.push_back(std::make_unique<Wall>(m_gameWindow.getLocationByIndex(row, col), m_gameWindow.getTileSize()));
				break;

			case ' ':
				createGifts(row, col);
				break;

			default:
				break;
			}
		}
		row++;
	}
	levelFile.close();
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
	m_bombs.clear();
}

void GameManager::createGifts(const int row, const int col)
{
	int random = std::rand() % 50;

	switch (random)
	{
	case 1:
		m_static.push_back(std::make_unique<GiftAddTime>(m_gameWindow.getLocationByIndex(row, col), m_gameWindow.getTileSize()));
		break;

	case 2:
		m_static.push_back(std::make_unique<GiftKillGuard>(m_gameWindow.getLocationByIndex(row, col), m_gameWindow.getTileSize()));
		break;

	case 3:
		m_static.push_back(std::make_unique<GiftFreezeGuards>(m_gameWindow.getLocationByIndex(row, col), m_gameWindow.getTileSize()));
		break;

	case 4:
		m_static.push_back(std::make_unique<GiftAddLife>(m_gameWindow.getLocationByIndex(row, col), m_gameWindow.getTileSize()));
		break;

	}

}