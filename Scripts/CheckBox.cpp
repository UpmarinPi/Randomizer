#include "Button.h"
#include "CheckBox.h"
#include "Draw.h"
#include "DxLib.h"
#include "SubWindow.h"

CheckBox::CheckBox()
{
	strcpy_s(check, "Åö");
	x = 0;
	y = 0;
	checkFlag = false;
	strcpy_s(text, "");
	fontSize = 20;
	boxSize = 2;

	textColor = GetColor(255, 255, 255);
	checkBox.SetButton
	(
		x, y,
		fontSize, fontSize,
		false, boxSize,
		"", fontSize
	);
}

CheckBox::CheckBox
(
	int _x, int _y,
	const char* _text,
	int _fontSize = 20
)
{
	strcpy_s(check, "Åö");
	x = _x;
	y = _y;
	checkFlag = false;
	strcpy_s(text, _text);
	fontSize = _fontSize;
	boxSize = 2;

	textColor = GetColor(255, 255, 255);
	checkBox.SetButton
	(
		x, y,
		fontSize, fontSize,
		false, boxSize,
		"", fontSize
	);
}

void CheckBox::DrawCheckBox()
{
	unsigned int bgColor =
		SetFontSize(fontSize);

	int textWidth = GetDrawStringWidth(text, strlen(text));//ï∂éöóÒÇÃÉhÉbÉgêîÇãÅÇﬂÇÈ

	checkBox.DrawButton();

	DrawString(x + fontSize + 10, y, text, textColor);

	SetFontSize(fontSize - 4);
	if (checkFlag)
	{
		if (checkBox.CheckMousePointInButton())
		{
			DrawString(x + 2, y + 2, check, backgroundColor.GetBackgroundColor());
		}
		else
		{
			DrawString(x + 2, y + 2, check, textColor);
		}
	}
}

int CheckBox::GetX()
{
	return x;
}
int CheckBox::GetY()
{
	return y;
}
Button CheckBox::GetCheckBoxButton()
{
	return checkBox;
}
bool CheckBox::CheckClickedCheckBox()
{
	return checkBox.CheckClickedButton();
}
bool CheckBox::GetCheckFlag()
{
	return checkFlag;
}

void CheckBox::SetX(int _x)
{
	x = _x;
}
void CheckBox::SetY(int _y)
{
	y = _y;
}
void CheckBox::SetCheckFlag(bool _checkFlag)
{
	checkFlag = _checkFlag;
}
void CheckBox::SetBoxSize(int _boxSize)
{
	boxSize = _boxSize;
}