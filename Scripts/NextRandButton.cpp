#include "Button.h"
#include "Consts.h"
#include "DxLib.h"
#include "Keyboard.h"
#include "NextRandButton.h"
#include "Random.h"
#include "Scenes.h"

Button nextRandButton(s_window_width - 110,s_window_height - 40, 30, 100, false, 1, "ŽŸ‚Ö", 20);

void NextRandButton()
{
	if (nextRandButton.CheckClickedButton() || GetKeyPress(KEY_INPUT_RIGHT, true))
	{
		if (!SetNextRandOrder())
		{
			ResetAppearFlag();
			ResetRandOrder();
			SetScene(SceneEnum::Title);
		}
	}
	if (GetKeyPress(KEY_INPUT_ESCAPE, true))
	{

	}
}
