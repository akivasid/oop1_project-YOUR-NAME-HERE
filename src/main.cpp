#include <iostream>
#include "BasicWindow.h"
#include "FontHolder.h"
#include "Button.h"
#include "WelcomeWindow.h"
#include "GameWindow.h"
#include "GameInformation.h"


int main()
{
	FontHolder::loadFont();

	WelcomeWindow window;

	window.draw();
	if (window.handleEvent())
	{
		GameWindow gameWindow(8, 10);
		GameInformation gameInfo(7);
		gameWindow.clear();
		gameWindow.draw(gameInfo.getInfoRec());
		gameWindow.draw(gameInfo.getInfoOutput());
		gameWindow.display();

		/*std::cout << gameWindow.getTopLeft(sf::Vector2f(250.f, 300.f)).x << ',';
		std::cout << gameWindow.getTopLeft(sf::Vector2f(250.f, 300.f)).y;*/

		int y;
		std::cin >> y;
	}

	
}
