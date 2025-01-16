#include <iostream>
#include "BasicWindow.h"
#include "FontHolder.h"
#include "Button.h"
#include "WelcomeWindow.h"


int main()
{
	FontHolder::loadFont();

	WelcomeWindow window(WelcomeConsts::WELCOME_WINDOW_SIZE, WelcomeConsts::WINDOW_NAME);

	window.draw();
	std::cout << window.handleEvent();
}
