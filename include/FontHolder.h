#pragma once
#include <SFML/Graphics.hpp>



class FontHolder
{
public:
	static void loadFont();
	static sf::Text getText();


private:
	static sf::Font m_font;
};