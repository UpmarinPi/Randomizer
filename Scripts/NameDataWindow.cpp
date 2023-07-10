#include "DxLib.h"
#include "NameData.h"
#include "NameDataWindow.h"
#include "SubWindow.h"

const int MAX_LISTWINDOW_COUNT = 25;

int maxTextWidth = 0;
SubWindow nameDataWindow(10, 160, 530, 16 * 20 + 20, 2);



void NameDataWindow()
{
	int gyo;
	if (nameData.size() != 0)
	{
		gyo = (nameData.size() - 1) / MAX_LISTWINDOW_COUNT + 1;
	}
	else
	{
		gyo = 1;
	}
	nameDataWindow.SetWidth(gyo * maxTextWidth + (gyo - 1) * 20 + 80);
	if ((int)nameData.size() < MAX_LISTWINDOW_COUNT)
	{
		nameDataWindow.SetHeight(nameData.size() * 20 + 40);
	}
	else
	{
		nameDataWindow.SetHeight(MAX_LISTWINDOW_COUNT * 20 + 40);
	}
}