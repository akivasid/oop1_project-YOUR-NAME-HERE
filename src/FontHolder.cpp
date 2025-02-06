#include "iostream"
#include "FontHolder.h"

sf::Font FontHolder::m_font;

void FontHolder::loadFont()
{
	if (!m_font.loadFromFile("Athelas.ttc"))
		std::cerr << "faild to load file" << '\n';
}

sf::Text FontHolder::getText()
{
	sf::Text text;
	text.setFont(m_font);
	text.setCharacterSize(40);
	return text;
}