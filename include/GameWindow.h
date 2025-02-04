#pragma once
#include <vector>
#include "BasicWindow.h"
#include "GameWindowConsts.h"
#include "MovementConsts.h"

#include <iostream>


class GameWindow : public BasicWindow
{
public:
	//constructor
	GameWindow();

	//public functions
	sf::Vector2f getLocationByIndex(const int row, const int col);
	sf::Vector2f getTopLeft(const sf::Vector2f& newLocation) const;
	sf::Vector2f getNextTopLeft(const sf::Vector2f& location, const sf::Vector2f& direction) const;
	
	void initializer(int row, int col); 
	
	const sf::Vector2f getTileSize() const;
	const sf::Event pollEvent();
	bool inArea(const sf::Vector2f& newLocation) const;
	
	
	void draw(const sf::RectangleShape& rectangle);
	void draw(const sf::Text& text);
	void draw(const sf::Sprite& picture);
	
private:
	//members
	int m_rows;
	int m_cols;
	sf::Vector2f m_tileSize;
	std::vector <std::vector <sf::Vector2f>> m_boardIndex;

	//private functions
	void resetIndex();
};