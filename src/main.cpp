#include <iostream>
#include "GeneralManager.h"

int main()
{
	FontHolder::loadFont();

	GeneralManager progManager;
	progManager.runProgram();
}