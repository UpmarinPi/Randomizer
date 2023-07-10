#include "Button.h"
#include "Consts.h"
#include "InitAppearButton.h"
#include "NameData.h"
#include "NameDataWindow.h"

Button initAppearButton(l_window_width - 435, l_window_height - 70, 30, 195, false, 1, "要素を全て未出現に変更", 15);

void InitAppearButton()
{
	int x = nameDataWindow.GetX() + nameDataWindow.GetWidth() + 10;
	int y = nameDataWindow.GetY() + nameDataWindow.GetHeight() - initAppearButton.GetHeight();
	initAppearButton.SetX(x);
	initAppearButton.SetY(y);

	if (initAppearButton.CheckClickedButton())
	{
		for (int i = 0; i < (int)nameData.size(); ++i)
		{
			nameData[i].SetAppearFlag(false);
		}
	}
}