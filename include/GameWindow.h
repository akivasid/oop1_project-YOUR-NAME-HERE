#pragma once
#include <vector>
#include "BasicWindow.h"
#include "GameWindowConsts.h"


class GameWindow : public BasicWindow
{
public:
	//constructor
	GameWindow();

	//public functions
	sf::Vector2f getTopLeft(const sf::Vector2f& newLocation) const;
	void initializer(int row, int col);
	void resetIndex();
	const sf::Vector2f getTileSize() const;
	
	void draw(const sf::RectangleShape& rectangle);
	void draw(const sf::Text& text);
	void draw(const sf::Sprite& picture);
	
private:
	//members
	int m_rows;
	int m_cols;
	sf::Vector2f m_tileSize;
	std::vector <std::vector <sf::Vector2f>> m_boardIndex;
};