#include "Button.h"
#include "Scenes.h"
#include "SetAlarmButton.h"

Button setAlarmButton(800, 20, 30, 160, false, 1, "�ʒm���Ԃ�ݒ�", 20);

void  SetAlarmButton()
{
	if (setAlarmButton.CheckClickedButton())
	{
		SetScene(SceneEnum::SetAlarm);
	}
}