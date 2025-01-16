#pragma once
#include <SFML/Graphics.hpp>
#include <vector>


class PicturesHolder
{
public:
	static void loadPictures();
	static sf::Text getSprite();

private:
	static std::vector <sf::Texture> m_pictures;
};