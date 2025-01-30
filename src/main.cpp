#include <iostream>
#include "GeneralManager.h"

int main()
{
	FontHolder::loadFont();
	Images::loadAllTextures();
	//singelton

	GeneralManager progManager;
	progManager.runProgram();
}