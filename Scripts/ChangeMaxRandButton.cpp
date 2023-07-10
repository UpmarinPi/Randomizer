#include "Button.h"
#include "ChangeMaxRandButton.h"
#include "Consts.h"
#include "DxLib.h"
#include "Scenes.h"
#include "SetRandWindow.h"
#include "SubWindow.h"

Button changeMaxRandButton(l_window_width - 185, l_window_height - 140, 30, 160, false, 1, "Å‘å’l‚ğ•ÏX", 20);

void ChangeMaxRandButton()
{
	if (changeMaxRandButton.CheckClickedButton())
	{
		SetScene(SceneEnum::SetRand);
	}
}