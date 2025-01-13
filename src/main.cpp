#include "iostream"
#include "BasicWindow.h"
#include "FontHolder.h"
#include "Button.h"


int main()
{
	sf::RenderWindow window(sf::VideoMode(1000.0f, 1000.0f), "waht ever");
	FontHolder::loadFont();
	
	Button button1(sf::Vector2f(200.0f, 200.0f), sf::Vector2f(600.0f, 600.0f), "JUVENTUS");
	

	window.clear();
	button1.drawButton(window);
	window.display();

	int y;
	std::cin >> y;
	if (!y)
		window.close();
}
