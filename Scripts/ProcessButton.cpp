#include "Button.h"
#include "Consts.h"
#include "DxLib.h"
#include "ListOfTexts.h"
#include "NameData.h"
#include "ProcessButton.h"
#include "Random.h"
#include "Scenes.h"

Button processButton(l_window_width - 225, l_window_height - 90, 60, 200, false, 1, "ŠJŽn", 40);

void ProcessButton()
{
	if (processButton.CheckClickedButton())
	{
		if ((int)nameData.size() < GetMaxRand())
		{
			SetNumberData(GetMaxRand());
		}
		bool checkActiveElement = false;
		for (int i = 0; i < (int)nameData.size(); ++i)
		{
			if (!nameData[i].GetAppearFlag())
			{
				checkActiveElement = true;
				break;
			}
		}
		
		if (!checkActiveElement)
		{
			noAppearWarningFlag = true;
		}
		else
		{
			noAppearWarningFlag = false;
			ShuffleRand();
			SetScene(SceneEnum::Process);
		}
	}
}