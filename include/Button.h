#pragma once
#include "FontHolder.h"


class Button
{
public:
	//constructor
	Button(const sf::Vector2f& loc, const sf::Vector2f& size, const std::string& name);

	//public functions
	bool buttonPressed(const sf::Vector2f& pressedLoc);//maybe change name
	void drawButton(sf::RenderWindow& window);
	void setFrame(sf::RenderWindow& window, const float& frameThickness, const sf::Color& color);

private:
	//members
	sf::Vector2f m_buttonSize;
	sf::Vector2f m_buttonLocation;
	sf::RectangleShape m_recButton;
	std::string m_buttonName;
	sf::Text m_buttonText;

	//private members
	void textCare();
};