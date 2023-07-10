#include "Consts.h"
#include "DxLib.h"
#include "PinWindow.h"
using namespace std;

int GetWindowX(int windowWidth)
{
	int screenWidth = GetSystemMetrics(SM_CXSCREEN);
	if (screenWidth > windowWidth)
	{
		return (screenWidth - windowWidth) / 2;
	}
	else
	{
		return 0;
	}
}

int GetWindowY(int windowHeight)
{
	int screenHeight = GetSystemMetrics(SM_CYSCREEN);
	if (screenHeight > windowHeight)
	{
		return (screenHeight - windowHeight) / 2;
	}
	else
	{
		return 0;
	}
}

void PinWindow(int wwidth, int wheight)
{
	SetWindowPos(GetMainWindowHandle(), HWND_TOPMOST, GetWindowX(wwidth), GetWindowY(wheight), wwidth, wheight, (SWP_NOSIZE | SWP_SHOWWINDOW));
}

void DepinWindow(int wwidth, int wheight)
{
	SetWindowPos(GetMainWindowHandle(), HWND_NOTOPMOST, GetWindowX(wwidth), GetWindowY(wheight), wwidth, wheight, (SWP_NOSIZE | SWP_SHOWWINDOW));
}