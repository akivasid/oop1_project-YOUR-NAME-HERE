#include "Button.h"

//===================================== constructor ========================================
Button::Button(const sf::Vector2f& location, const sf::Vector2f& size, const std::string& name)
	:m_buttonSize(size), m_buttonLocation(location), m_buttonName(name),
		m_buttonText(FontHolder::getText()), m_recButton(m_buttonSize)
{
	m_recButton.setPosition(m_buttonLocation);
	m_buttonText.setString(m_buttonName);
	//m_buttonText.setCharacterSize(40);


	float sizeX = m_buttonText.getGlobalBounds().width;
	float sizeY = m_buttonText.getGlobalBounds().height;

	m_buttonText.setOrigin(sf::Vector2f(sizeX/2, sizeY/2));
	m_buttonText.setFillColor(sf::Color::Red);

	sf::Vector2f center(m_buttonLocation.x + m_buttonSize.x / 2, m_buttonLocation.y + m_buttonSize.y / 2);
	m_buttonText.setPosition(center);
}



//===================================== public functions ===================================
bool Button::buttonPressed(const sf::Vector2f& pressedLoc)
{
	return m_recButton.getGlobalBounds().contains(pressedLoc);
}


void Button::drawButton(sf::RenderWindow& window)
{
	window.draw(m_recButton);
	window.draw(m_buttonText);
}

