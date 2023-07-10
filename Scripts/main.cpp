#include "DxLib.h"
#include "Consts.h"
#include "Controll.h"
#include "Draw.h"
#include "Error.h"
#include "Exit.h"
#include "FPS.h"
#include "Init.h"
#include "OpenFile.h"
#include "Random.h"
#include "SetRandWindow.h"
#include "Scenes.h"

int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_  HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nShowCmd)
{
	SetUseCharCodeFormat(DX_CHARCODEFORMAT_SHIFTJIS);

	SetWindowIconID(101);
	SetGraphMode(l_window_width, l_window_height, 32);
	ChangeWindowMode(TRUE);
	SetAlwaysRunFlag(true);
	SetMainWindowText("Randomizer");
	DxLib_Init();
	SetDrawScreen(DX_SCREEN_BACK);


    enum class EventControllerEnum
    {
        Start,
        Update,
    };

    EventControllerEnum eventController = EventControllerEnum::Start;

    Fps fps;				//fpsを管理。1/60で常に動作する
    bool endFlag = false;	//endFlagがtrueになったときにゲームを終了。
	fileName[0] = '\0';
	SetMaxRand(GetSetRandMax());

    // while( 裏画面を表画面に反映, メッセージ処理, 画面クリア )
    while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0 && !endFlag)
    {
		fps.Update();	//更新

		switch (eventController)
		{
		case EventControllerEnum::Start:
			Init();											//初期化
			eventController = EventControllerEnum::Update;	//updateへの移行
			break;

		case EventControllerEnum::Update:
			Draw();
			Controll();
			if (UpdateScene())//シーンが更新されたら
			{
				eventController = EventControllerEnum::Start;//startへ移行
			}
			break;
		}
		if (GetErrorFlag() || GetExitFlag())//エラーが起きた際プログラムを終了する
		{
			endFlag = true;
		}

		fps.Wait();
    }

    DxLib_End(); // DXライブラリ終了処理
    return 0;
}