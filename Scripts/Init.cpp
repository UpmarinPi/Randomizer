#include "Consts.h"
#include "DuplicateCheck.h"
#include "DxLib.h"
#include "Init.h"
#include "NameData.h"
#include "PinWindow.h"
#include "Random.h"
#include "Scenes.h"

/// <summary>
/// �J�n�Ɠ����ɌĂ΂��֐�
/// </summary>
/// <returns></returns>
void Init()
{
	InitGraph();
	switch (GetScene())
	{
	case SceneEnum::Title://�^�C�g�����
		SetGraphMode(l_window_width, l_window_height, 32);	//�E�B���h�E�T�C�Y�ύX
		DepinWindow(l_window_width, l_window_height);
		break;
	case SceneEnum::Process:
		if (nameData[GetRandNum(GetNowRandOrder())].GetAppearFlag() && !duplicateCheck.GetCheckFlag())
		{
			SetNextRandOrder();
		}
		SetGraphMode(s_window_width, s_window_height, 32);	//�E�B���h�E�T�C�Y�ύX
		PinWindow(s_window_width, s_window_height);
		break;
	}


	bool succeedFlag = true;//�S�����������Ƃ���true��Ԃ�
}