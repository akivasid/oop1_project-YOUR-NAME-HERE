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
	//m_dynamic.push_back(std::make_unique <Guard>(m_gameWindow.getTopLeft(sf::Vector2f(100, 500)), m_gameWindow.getTileSize()));
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
		sf::Vector2f direction = m_dynamic[i]->getWantedDirection();
		if (direction != MovementConsts::NO_DIRECTION)
			takeToTopLeft(m_dynamic[i]->getDirection(), i);//the easyer way is to see if there is no press move to top left
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

void GameManager::takeToTopLeft(const sf::Vector2f& direction, int index)
{
	sf::Vector2f curLoc(m_dynamic[index]->getLocation());
	sf::Vector2f wantedTopLeft(m_gameWindow.getNextTopLeft(curLoc, direction));
	sf::Clock clock;

	
	m_dynamic[index]->move(m_dynamic[index]->getNewLocation(direction, clock.getElapsedTime().asSeconds()));//placing in right place
	clock.restart();
	curLoc = m_dynamic[index]->getLocation();//getting current location in order to add it to direction
	updateWindow();

	if ((curLoc.x - wantedTopLeft.x < 3 && curLoc.x - wantedTopLeft.x > -3) &&
		(curLoc.y - wantedTopLeft.y < 3 && curLoc.y - wantedTopLeft.y > -3))
	{
		m_dynamic[index]->move(wantedTopLeft);
		m_dynamic[index]->resetDirection();
	}
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