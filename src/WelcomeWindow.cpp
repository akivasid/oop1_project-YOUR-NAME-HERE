#include "WelcomeWindow.h"


//================================= constructor ===========================

WelcomeWindow::WelcomeWindow()
	:BasicWindow(WelcomeConsts::WELCOME_WINDOW_SIZE, WelcomeConsts::WINDOW_NAME, WelcomeConsts::MUSIC_FILE_NAME),
	m_play(WelcomeConsts::PLAY_LOCATION, WelcomeConsts::BUTTON_SIZE, WelcomeConsts::PLAY_NAME),
	m_help(WelcomeConsts::HELP_LOCATION, WelcomeConsts::BUTTON_SIZE, WelcomeConsts::HELP_NAME),
	m_exit(WelcomeConsts::EXIT_LOCATION, WelcomeConsts::BUTTON_SIZE, WelcomeConsts::EXIT_NAME), m_helpText(FontHolder::getText()),
	m_backToMenu(WelcomeConsts::BACK_LOCATION, WelcomeConsts::BACK_BUTTON_SIZE, WelcomeConsts::BACK_NAME), 
	m_background(Images::getSprite(WelcomeConsts::WELCOME_WINDOW_SIZE))
{
	getTextHelp();
}


//================================= public functions ===========================

void WelcomeWindow::draw()
{
	clear();
	m_window.draw(m_background);
	m_play.drawButton(m_window);
	m_help.drawButton(m_window);
	m_exit.drawButton(m_window);
	display();
}

bool WelcomeWindow::handleEvent()
{
	sf::Vector2f pressedLocation(-1.0f, -1.0f);
	sf::Vector2f lastMove(-1.0f, -1.0f);
	bool inHelp = false;

	while (m_window.isOpen())
	{
		sf::Event event;
		if (m_window.waitEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				m_window.close();
				break;
			
			case sf::Event::MouseButtonReleased:
				pressedLocation = sf::Vector2f(float(event.mouseButton.x), float(event.mouseButton.y));
				if (m_play.buttonPressed(pressedLocation))
					return true;

				else if (m_exit.buttonPressed(pressedLocation))
					return false;

				else if (m_help.buttonPressed(pressedLocation))
				{
					helpSituation();
					m_help.setFrame(m_window, 0.0f, sf::Color(230, 190, 138));
					inHelp = true;
				}

				else if (m_backToMenu.buttonPressed(pressedLocation))
				{
					draw();
					m_backToMenu.setFrame(m_window, 0.0f, sf::Color::Red);
					inHelp = false;
				}
				break;
			
			case sf::Event::MouseMoved:
				handleMovement(m_window.mapPixelToCoords({ event.mouseMove.x, event.mouseMove.y }), lastMove, inHelp);
				lastMove = m_window.mapPixelToCoords({ event.mouseMove.x, event.mouseMove.y });
				break;
			}
			
		}
	}

	return false;
}


//================================= private functions ===========================


void WelcomeWindow::getTextHelp()
{
	std::ifstream file(WelcomeConsts::HELP_FILE_NAME);
	if (!file)
	{
		std::cerr << "no file found\n";
		exit(0);
	}

	std::string line, newLine;
	while (getline(file, newLine))
		line += newLine + '\n';

	m_helpText.setString(line);
	m_helpText.setPosition(sf::Vector2f(215.0f, 30.0f));
	m_helpText.setCharacterSize(40);

}


void WelcomeWindow::helpSituation()
{
	m_window.clear();
	m_backToMenu.drawButton(m_window);
	m_window.draw(m_helpText);
	m_window.display();
}


void WelcomeWindow::handleMovement(const sf::Vector2f& locMove, sf::Vector2f& lastMove, bool inHelp)
{
	if (inHelp)
	{
		if (m_backToMenu.buttonPressed(locMove) && !m_backToMenu.buttonPressed(lastMove))
			m_backToMenu.setFrame(m_window, 2.0f, sf::Color::Red);
		else if(!m_backToMenu.buttonPressed(locMove) && m_backToMenu.buttonPressed(lastMove))
			m_backToMenu.setFrame(m_window, 0.0f, sf::Color::Red);
		helpSituation();
	}
	
	else
	{
		if (m_play.buttonPressed(locMove))
			frameArrangement(m_play);
		else
			deleteFrame(m_play);
		
		if (m_exit.buttonPressed(locMove))
			frameArrangement(m_exit);
		else 
			deleteFrame(m_exit);
		
		if (m_help.buttonPressed(locMove))
			frameArrangement(m_help);
		else 
			deleteFrame(m_help);
		draw();
	}
}


void WelcomeWindow::frameArrangement(Button& button) 
{
	button.setFrame(m_window, 2.0f, sf::Color(230, 190, 138));
}

void WelcomeWindow::deleteFrame(Button& button)
{
	button.setFrame(m_window, 0.0f, sf::Color(230, 190, 138));
}