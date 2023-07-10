#include "Exit.h"

bool exitFlag = false;

bool GetExitFlag() 
{
	return exitFlag;
}

void Exit()
{
	exitFlag = true;
}