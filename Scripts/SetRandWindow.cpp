#include "Consts.h"
#include "DxLib.h"
#include "Keyboard.h"
#include "NameData.h"
#include "Random.h"
#include "SetRandWindow.h"
#include "SubWindow.h"

#define RANDMAX 500
int height = 60;
int width = 150;
SubWindow setRandWindow(
	(l_window_width - width) / 2,
	(l_window_height - height) / 2,
	height, width, 2);

int setRandMax = 1;

void SetSetRandMax(int num)
{
	setRandMax = num;
	SetMaxRand(num);
}

int GetSetRandMax()
{
	if (setRandMax > RANDMAX)
	{
		return RANDMAX;
	}
	else
	{
		return setRandMax;
	}
}

void AddRandMax(int num)
{
	if (setRandMax <= RANDMAX)
	{
		setRandMax = setRandMax * 10 + num;
	}
}

void TakeoutRandMax()
{
	int rand = setRandMax / 10;
	if (rand > 0)
	{
		setRandMax = rand;
	}
	else
	{
		setRandMax = 0;
	}
}

void InputRandMax()
{
	if (GetKeyPress(KEY_INPUT_1, true) || GetKeyPress(KEY_INPUT_NUMPAD1, true))
	{
		AddRandMax(1);
	}
	if (GetKeyPress(KEY_INPUT_2, true) || GetKeyPress(KEY_INPUT_NUMPAD2, true))
	{
		AddRandMax(2);
	}
	if (GetKeyPress(KEY_INPUT_3, true) || GetKeyPress(KEY_INPUT_NUMPAD3, true))
	{
		AddRandMax(3);
	}
	if (GetKeyPress(KEY_INPUT_4, true) || GetKeyPress(KEY_INPUT_NUMPAD4, true))
	{
		AddRandMax(4);
	}
	if (GetKeyPress(KEY_INPUT_5, true) || GetKeyPress(KEY_INPUT_NUMPAD5, true))
	{
		AddRandMax(5);
	}
	if (GetKeyPress(KEY_INPUT_6, true) || GetKeyPress(KEY_INPUT_NUMPAD6, true))
	{
		AddRandMax(6);
	}
	if (GetKeyPress(KEY_INPUT_7, true) || GetKeyPress(KEY_INPUT_NUMPAD7, true))
	{
		AddRandMax(7);
	}
	if (GetKeyPress(KEY_INPUT_8, true) || GetKeyPress(KEY_INPUT_NUMPAD8, true))
	{
		AddRandMax(8);
	}
	if (GetKeyPress(KEY_INPUT_9, true) || GetKeyPress(KEY_INPUT_NUMPAD9, true))
	{
		AddRandMax(9);
	}
	if (GetKeyPress(KEY_INPUT_0, true) || GetKeyPress(KEY_INPUT_NUMPAD0, true))
	{
		AddRandMax(0);
	}
	if (GetKeyPress(KEY_INPUT_BACK, true))
	{
		TakeoutRandMax();
	}
}

void WarningMessage()
{
	SetFontSize(20);
	int i = 1;

	if (GetSetRandMax() == RANDMAX)
	{
		DrawFormatString
		(
			5,
			l_window_height - 10 - 20 * i,
			GetColor(255, 255, 255),
			"※最大値は%dです",
			RANDMAX
		);
		++i;
	}
	if (nameData.size() != 0)
	{
		if (GetSetRandMax() > (int)nameData.size())
		{
			DrawFormatString
			(
				5,
				l_window_height - 10 - 20 * i,
				GetColor(255, 255, 255),
				"※要素数(%d)より多い値のため、出力乱数は全て値になります",
				nameData.size()
			);
			++i;
		}
		else if (GetSetRandMax() < (int)nameData.size())
		{
			DrawFormatString
			(
				5,
				l_window_height - 10 - 20 * i,
				GetColor(255, 255, 255),
				"※要素数(%d)より小さいため、出力されない要素が存在します",
				nameData.size()
			);
			++i;
		}
	}
	DrawFormatString
	(
		5,
		l_window_height - 10 - 20 * i,
		GetColor(255, 255, 255),
		"ESCキーで戻ります",
		RANDMAX
	);
	++i;
}