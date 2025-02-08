#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>

class BasicWindow
{
public:
	//constructor
	BasicWindow(const sf::Vector2f size, const std::string& windowName, const std::string& musicFile);

	//public functions
	bool isOpen() const;
	void clear(); 
	void display();
	void close();
	void stopMusic();
	void playMusic();
	
protected:
	//members
	sf::Vector2f m_windowSize;
	sf::RenderWindow m_window;
	sf::Music m_backgroundMusic;
};