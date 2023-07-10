#include "Click.h"
#include "Consts.h"
#include "DuplicateCheck.h"
#include "ListOfTexts.h"
#include "NameData.h"
#include "NameDataWindow.h"
#include "OpenFile.h"
#include "Random.h"
#include "SansyoButton.h"
#include "ShowNextCheck.h"

bool noAppearWarningFlag = false;

void DrawTitleTexts()
{
	SetFontSize(20);
	if ((int)nameData.size() != 0)
	{
		DrawFormatString(
			10, 130,
			GetColor(255, 255, 255),
			"%2d個の要素数を取得", nameData.size());
	}

	int fileNameX = sansyoButton.GetX() + sansyoButton.GetWidth() + 10;
	int fileNameY = sansyoButton.GetY() + sansyoButton.GetHeight() - sansyoButton.GetFontSize();
	DrawString(fileNameX, fileNameY, fileName, GetColor(255, 255, 255));
	DrawFormatString
	(
		l_window_width - 320,
		l_window_height - 170,
		GetColor(255, 255, 255),
		"%d～%5dの範囲でロールします", GetMinRand(), GetMaxRand()
	);
	DrawString(fileNameX, fileNameY, fileName, GetColor(255, 255, 255));
	if (noAppearWarningFlag)
	{
		SetFontSize(15);
		DrawString(830, 670, "表示できる要素がありません\n", GetColor(255, 0, 0));
		
	}
}
void DrawProcessString(int textX, int textY, int nexttextY, int fontsize, int nextfontsize)
{
	SetFontSize(fontsize);
	DrawFormatString
	(
		textX,
		textY,
		GetColor(255, 255, 255),
		"%s", GetNameOfData(GetRandNum(GetNowRandOrder()))
	);
	SetFontSize(nextfontsize);
	if (showNextCheck.GetCheckFlag() &&
		GetNowRandOrder() + 1 < GetMaxRand())
	{
		DrawFormatString
		(
			textX,
			nexttextY,
			GetColor(255, 255, 255),
			"NEXT: %s", GetNameOfData(GetRandNum(GetNowRandOrder() + 1))
		);
	}
	else
	{
		DrawString
		(
			textX,
			nexttextY,
			"NEXT: 非表示",
			GetColor(255, 255, 255)
		);
	}
}


void DrawProcessTexts()
{
	SetFontSize(20);
	DrawString(10, 50, "ESC: 終了", GetColor(255, 255, 255));
	DrawString(10, 70, "→  : 次へ", GetColor(255, 255, 255));

	int fontsize = 30;
	int nextfontsize = fontsize / 2;
	int textX = 10;
	int textY = s_window_height - fontsize - nextfontsize;
	int nextTextY = s_window_height - nextfontsize;

	SetFontSize(fontsize);

	DrawProcessString(textX, textY, nextTextY, fontsize, nextfontsize);
	if (!duplicateCheck.GetCheckFlag())
	{
		nameData[GetRandNum(GetNowRandOrder())].SetAppearFlag(true);
	}
}

void DrawSetRandTexts()
{

}
void DrawSetAlarmTexts()
{

}

void ClickTitleTexts()
{
	for (int i = 0; i < (int)nameData.size(); ++i)
	{
		if (CheckClickedText(i))
		{
			nameData[i].ToggleAppearFlag();
		}
	}
}

void ClickSetAlarmTexts()
{

}

bool CheckClickedText(int num)
{
	bool checkMousePointFlag =
		CheckMousePoint
		(
			nameData[num].GetDataXInTitle(),
			nameData[num].GetDataYInTitle(),
			maxTextWidth, 20
		);

	if ((GetMouseInput() & MOUSE_INPUT_LEFT) != 0 && checkMousePointFlag)
	{
		++nameData[num].clickTime;
		return (nameData[num].clickTime == 1);
	}
	else
	{
		nameData[num].clickTime = 0;
		return false;
	}
}