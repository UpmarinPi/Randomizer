#include "Button.h"
#include "Consts.h"
#include "DxLib.h"
#include "Keyboard.h"
#include "Scenes.h"
#include "StopProcessButton.h"

Button stopProcessButton(10, 10, 30, 100, false, 1, "èIóπ", 20);

void StopProcessButton()
{
	if (stopProcessButton.CheckClickedButton() ||
		GetKeyPress(KEY_INPUT_ESCAPE, true))
	{
		SetScene(SceneEnum::Title);
	}
}
