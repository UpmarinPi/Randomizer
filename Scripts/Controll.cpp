#include "ListOfButtons.h"
#include "ListOfCheckBoxes.h"
#include "ListOfTexts.h"
#include "Controll.h"
#include "Keyboard.h"
#include "SetRandWindow.h"
#include "Scenes.h"

void Controll()
{
	Keyboard::Instance()->KeyUpdate();
	switch (GetScene())
	{
	case SceneEnum::Title://�^�C�g��
		ClickTitleButtons();//�{�^���������Ƃ��̏���
		ClickTitleTexts();
		ClickTitleCheckBoxes();
		break;
	case SceneEnum::Process:
		ClickProcessButtons();
		break;
	case SceneEnum::SetRand:
		ClickSetRandButtons();
		InputRandMax();
		break;
	case SceneEnum::SetAlarm:
		ClickSetAlarmButtons();
		ClickSetAlarmTexts();
		ClickSetAlarmCheckBoxes();
		break;
	}
}