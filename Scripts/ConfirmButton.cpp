#include "Button.h"
#include "Consts.h"
#include "ConfirmButton.h"
#include "DxLib.h"
#include "Keyboard.h"
#include "Random.h"
#include "Scenes.h"
#include "SetRandWindow.h"

Button confirmButton(l_window_width / 2 + 125, (l_window_height - 30) / 2, 30, 100, false, 1, "Œˆ’è", 20);

void ConfirmButton()
{
	if (confirmButton.CheckClickedButton() || GetKeyPress(KEY_INPUT_RETURN, false))
	{
			SetMaxRand(GetSetRandMax());
			SetScene(SceneEnum::Title);
	}
	if (GetKeyPress(KEY_INPUT_ESCAPE, false))
	{
		SetSetRandMax(GetSetRandMax());
		SetScene(SceneEnum::Title);
	}
}