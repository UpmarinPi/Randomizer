#include "DxLib.h"
#include "ListOfSubWindow.h"
#include "NameData.h"
#include "NameDataWindow.h"
#include "SetAlarmDataWindow.h"
#include "SetRandWindow.h"
#include "SubWindow.h"

void DrawTitleSubWindows()
{
	nameDataWindow.DrawSubWindow();
	NameDataWindow();
	
	SetFontSize(20);
	
	for (int i = 0; i < (int)nameData.size(); ++i)
	{
		int textX = 20 + (GetFontSize() + maxTextWidth) * (i / MAX_LISTWINDOW_COUNT);
		int textY = 20 + GetFontSize() * (i % MAX_LISTWINDOW_COUNT);
		nameData[i].SetDataXInTitle(textX + nameDataWindow.GetX());
		nameData[i].SetDataYInTitle(textY + nameDataWindow.GetY());
		if (!nameData[i].GetAppearFlag())
		{
			nameDataWindow.DrawStringInSub(
				textX,
				textY,
				nameData[i].GetNameOfData(),
				GetColor(255, 255, 255)
			);
		}
		else
		{
			nameDataWindow.DrawStringInSub(
				textX,
				textY,
				nameData[i].GetNameOfData(),
				GetColor(255 / 2, 255 / 2, 255 / 2)
			);
		}
	}

}

void DrawSetRandSubWindows()
{
	SetFontSize(30);
	setRandWindow.DrawStringInSub(-80, -40, "—”‚ð“ü—Í‚µ‚Ä‚­‚¾‚³‚¢", GetColor(255, 255, 255));

	setRandWindow.DrawSubWindow();
	SetFontSize(40);
	if (GetSetRandMax() != 0)
	{
		setRandWindow.DrawFormatStringInSub(10, 10, GetColor(255, 255, 255), "%d", GetSetRandMax());
	}

	WarningMessage();
}

void DrawSetAlarmSubWindows()
{
	AlarmDataWindow();
	alarmDataWindow.DrawSubWindow();
}

