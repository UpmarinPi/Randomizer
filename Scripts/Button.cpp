#include "Button.h"
#include "Click.h"
#include "Draw.h"
#include "DxLib.h"
#include "SubWindow.h"

Button::Button()
{
	x = 0;
	y = 0;

	height = 0;
	width = 0;

	fillBoxFlag = false;
	boxSize = 1;

	strcpy_s(text, "");
	fontSize = 20;
	boxColor = GetColor(255, 255, 255);
	textColor = GetColor(255, 255, 255);

	clickTime = 0;
}

Button::Button
(
	int _x, int _y,
	int _height, int _width,
	bool _fillBoxFlag, int _boxSize,
	const char* _text, int _fontSize = 20
)
{
	x = _x;
	y = _y;

	height = _height;
	width = _width;

	fillBoxFlag = _fillBoxFlag;
	boxSize = _boxSize;

	strcpy_s(text, _text);
	fontSize = _fontSize;

	boxColor = GetColor(255, 255, 255);
	textColor = GetColor(255, 255, 255);

	clickTime = 0;
}

void Button::DrawButton()
{
	unsigned int bgColor =
		SetFontSize(fontSize);

	int textWidth = GetDrawStringWidth(text, strlen(text));//文字列のドット数を求める
	int textX = x + (width - textWidth) / 2;
	int textY = y + (height - fontSize) / 2;

	if ((CheckMousePoint(x, y, width, height) && fillBoxFlag || !CheckMousePoint(x, y, width, height) && !fillBoxFlag))
	{
		for (int i = 0; i < boxSize; ++i)//太さ分ボックスの中にボックスを追加で描く
		{
			DrawBox(x + i, y + i, x + width - i, y + height - i, boxColor, false);
		}
		DrawString(textX, textY, text, textColor);
	}
	else
	{
		DrawBox(x + boxSize, y + boxSize, x + width - boxSize, y + height - boxSize, textColor, true);

		DrawString(textX, textY, text, backgroundColor.GetBackgroundColor());
	}
}

bool Button::CheckMousePointInButton()
{
	return CheckMousePoint(x, y, width, height);
}

bool Button::CheckClickedButton()
{
	if ((GetMouseInput() & MOUSE_INPUT_LEFT) != 0 && CheckMousePointInButton())
	{
		++clickTime;
		return (clickTime == 1);
	}
	else
	{
		clickTime = 0;
		return false;
	}
}

int Button::GetX()
{
	return x;
}
int Button::GetY()
{
	return y;
}
int Button::GetHeight()
{
	return height;
}
int Button::GetWidth()
{
	return width;
}
int Button::GetFontSize()
{
	return fontSize;
}

void Button::SetButton(int _x, int _y, int _height, int _width, bool _fillBoxFlag, int _boxSize, const char* _text, int _fontSize)
{
	x = _x;
	y = _y;

	height = _height;
	width = _width;

	fillBoxFlag = _fillBoxFlag;
	boxSize = _boxSize;

	strcpy_s(text, _text);
	fontSize = _fontSize;
}
void Button::SetX(int _x)
{
	x = _x;
}
void Button::SetY(int _y)
{
	y = _y;
}
void Button::SetHeight(int _height)
{
	height = _height;
}
void Button::SetWidth(int _width)
{
	width = _width;
}
void Button::SetBoxColor(unsigned int _boxColor)
{
	boxColor = _boxColor;
}
void Button::SetTextColor(unsigned int _textColor)
{
	textColor = _textColor;
}