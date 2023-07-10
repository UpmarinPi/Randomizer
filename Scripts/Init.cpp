#include "Consts.h"
#include "DuplicateCheck.h"
#include "DxLib.h"
#include "Init.h"
#include "NameData.h"
#include "PinWindow.h"
#include "Random.h"
#include "Scenes.h"

/// <summary>
/// 開始と同時に呼ばれる関数
/// </summary>
/// <returns></returns>
void Init()
{
	InitGraph();
	switch (GetScene())
	{
	case SceneEnum::Title://タイトル画面
		SetGraphMode(l_window_width, l_window_height, 32);	//ウィンドウサイズ変更
		DepinWindow(l_window_width, l_window_height);
		break;
	case SceneEnum::Process:
		if (nameData[GetRandNum(GetNowRandOrder())].GetAppearFlag() && !duplicateCheck.GetCheckFlag())
		{
			SetNextRandOrder();
		}
		SetGraphMode(s_window_width, s_window_height, 32);	//ウィンドウサイズ変更
		PinWindow(s_window_width, s_window_height);
		break;
	}


	bool succeedFlag = true;//全部成功したときにtrueを返す
}