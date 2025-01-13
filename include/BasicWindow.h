#pragma once
#include <SFML/Graphics.hpp>




class BasicWindow
{
public:
	//constructor
	BasicWindow(const sf::Vector2f size, const std::string& windowName);

	//public functions
	bool isOpen() const;
	void close();
	

protected:
	//members
	sf::Vector2f m_windowSize;
	sf::RenderWindow m_window;
};