#include "Draw.h"
#include "DxLib.h"
#include "ListOfButtons.h"
#include <stdarg.h>
#include "SubWindow.h"

SubWindow::SubWindow()
{
	showFlag = true;
	x = 0;
	y = 0;

	height = 0;
	width = 0;

	boxSize = 1;

	boxColor = GetColor(255, 255, 255);
}

SubWindow::SubWindow(int _x, int _y, int _height, int _width, int _boxSize)
{
	showFlag = true;
	x = _x;
	y = _y;
	height = _height;
	width = _width;

	boxSize = _boxSize;

	boxColor = GetColor(255, 255, 255);
}

void SubWindow::DrawSubWindow()
{
	if (!showFlag)
	{
		return;
	}

	DrawBox(x, y, x + width, y + height, backgroundColor.GetBackgroundColor(), true);

	for (int i = 0; i < boxSize; ++i)//太さ分ボックスの中にボックスを追加で描く
	{
		DrawBox(x + i, y + i, x + width - i, y + height - i, boxColor, false);
	}
}

bool SubWindow::GetShowFlag()
{
	return showFlag;
}

void SubWindow::DrawStringInSub(int textX, int textY, const char* text, unsigned int color)
{
	DrawString(x + textX, y + textY, text, color);
}
void SubWindow::DrawFormatStringInSub(int textX, int textY, unsigned int color, const char* text, ...)
{
	va_list args;
	va_start(args, text);
	DrawFormatString(x + textX, y + textY, color, text, va_arg(args, int));
	va_end(args);
}


int SubWindow::GetX()
{
	return x;
}
int SubWindow::GetY()
{
	return y;
}
int SubWindow::GetHeight()
{
	return height;
}
int SubWindow::GetWidth()
{
	return width;
}

void SubWindow::SetX(int _x)
{
	x = _x;
}
void SubWindow::SetY(int _y)
{
	y = _y;
}
void SubWindow::SetHeight(int _height)
{
	height = _height;
}
void SubWindow::SetWidth(int _width)
{
	width = _width;
}

void SubWindow::SetBoxColor(unsigned int _boxColor)
{
	boxColor = _boxColor;
}