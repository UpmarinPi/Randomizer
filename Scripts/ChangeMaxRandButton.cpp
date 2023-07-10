#include "Button.h"
#include "ChangeMaxRandButton.h"
#include "Consts.h"
#include "DxLib.h"
#include "Scenes.h"
#include "SetRandWindow.h"
#include "SubWindow.h"

Button changeMaxRandButton(l_window_width - 185, l_window_height - 140, 30, 160, false, 1, "最大値を変更", 20);

void ChangeMaxRandButton()
{
	if (changeMaxRandButton.CheckClickedButton())
	{
		SetScene(SceneEnum::SetRand);
	}
}