#include "Button.h"
#include "Scenes.h"
#include "SetAlarmButton.h"

Button setAlarmButton(800, 20, 30, 160, false, 1, "’Ê’mŠÔ‚ğİ’è", 20);

void  SetAlarmButton()
{
	if (setAlarmButton.CheckClickedButton())
	{
		SetScene(SceneEnum::SetAlarm);
	}
}