#include "PicturesHolder.h"
#include "iostream"

std::vector <sf::Texture> PicturesHolder::m_pictures;

void FontHolder::loadFont()
{
	if (!m_font.loadFromFile("BombermanFont.TTF"))
		std::cerr << "faild to load file" << '\n';
}

sf::Text FontHolder::getText()
{
	sf::Text text;
	text.setFont(m_font);
	text.setCharacterSize(40);
	return text;
}