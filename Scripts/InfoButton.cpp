#include "InfoButton.h"
#include "DxLib.h"

InfoButton::InfoButton()
{
	x = 0;//左上の座標
	y = 0;

	height = 18;	//縦
	width = 18;	//横

	color = GetColor(255, 255, 255);
	fontSize = 15;
}

InfoButton::InfoButton(int _x, int _y, SubWindow _subWindow)
{
	x = _x;
	y = _y;

	height = 18;
	width = 18;

	color = GetColor(255, 255, 255);

	fontSize = 15;

	subWindow = _subWindow;
}

void InfoButton::DrawInfoButton()
{
	unsigned int bgColor =
		SetFontSize(fontSize);

	int textWidth = GetDrawStringWidth("？", strlen("？"));//文字列のドット数を求める
	int textX = x + (width - textWidth) / 2;
	int textY = y + (height - fontSize) / 2;

	if ((this->CheckMousePoint()))
	{
		for (int i = 0; i < 2; ++i)//太さ分ボックスの中にボックスを追加で描く
		{
			DrawBox(x + i, y + i, x + width - i, y + height - i, color, false);
		}
	}
	else
	{
		DrawBox(x + 2, y + 2, x + width - 2, y + height - 2, color, true);
	}
	subWindow.DrawSubWindow();
}

bool InfoButton::CheckMousePoint()
{
	int mouseX, mouseY;
	GetMousePoint(&mouseX, &mouseY);
	if (x < mouseX && mouseX < x + width && y < mouseY && mouseY < y + height)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool InfoButton::CheckClickedButton()
{
	if ((GetMouseInput() & MOUSE_INPUT_LEFT) != 0 && CheckMousePoint())
	{
		return true;
	}
	else
	{
		return false;
	}
}