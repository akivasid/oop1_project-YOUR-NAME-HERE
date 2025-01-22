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
	
	sf::Vector2f direction = m_dynamic[0]->getDirection();

	sf::Vector2f newLoc(m_dynamic[0]->getNewLocation(direction, clock.getElapsedTime().asSeconds()));
	//sf::Vector2f oldLoc = m_dynamic[0]->getLocation();

	if (m_gameWindow.inArea(newLoc))
	{
		m_dynamic[0]->move(newLoc);
		
		//sf::Vector2f direction(newLoc - oldLoc);//getting direction: up/down/right/left/in_place
		//if (newLoc == m_dynamic[0]->getMovement())//checking if movement stopped
		//	takeToTopLeft(direction, 0 /*index*/);
	}
	
	clock.restart();


	sf::Vector2f newDirection(m_dynamic[0]->getDirection());
	if (newDirection == sf::Vector2f(0.f, 0.f) && direction != sf::Vector2f(0.f, 0.f))
	{
		takeToTopLeft(direction, 0);
	}

	
	

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

void GameManager::takeToTopLeft(const sf::Vector2f& direction, int index)
{
	sf::Vector2f curLoc(m_dynamic[index]->getLocation());
	sf::Vector2f wantedTopLeft(m_gameWindow.getNextTopLeft(curLoc, direction));
	sf::Clock clock;

	while(wantedTopLeft != curLoc)
	{
		sf::Vector2f newLoc(m_dynamic[0]->getNewLocation(direction, clock.getElapsedTime().asSeconds()));
		m_dynamic[index]->move(newLoc);//placing in right place
		clock.restart();
		curLoc = m_dynamic[index]->getLocation();//getting current location in order to add it to direction
		updateWindow();
	}

}

void GameManager::updateWindow()
{
	m_gameWindow.clear();
	m_gameInfo.updateOutput();
	m_gameWindow.draw(m_gameInfo.getInfoRec());
	m_gameWindow.draw(m_gameInfo.getInfoOutput());
	m_gameWindow.draw(m_dynamic[0]->getParticipantSprite());
	m_gameWindow.display();
}