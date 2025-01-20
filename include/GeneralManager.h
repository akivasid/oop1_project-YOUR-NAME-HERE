#pragma once
#include <iostream>
#include "FontHolder.h"
#include "Images.h"
#include "WelcomeWindow.h"
#include "GameWindow.h"
#include "GameManager.h"


class GeneralManager
{
public:
	//constructor
	GeneralManager();

	//public functions
	void runProgram();

private:
	//members
	WelcomeWindow m_welcomeWindow;
};