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

    Fps fps;				//fps���Ǘ��B1/60�ŏ�ɓ��삷��
    bool endFlag = false;	//endFlag��true�ɂȂ����Ƃ��ɃQ�[�����I���B
	fileName[0] = '\0';
	SetMaxRand(GetSetRandMax());

    // while( ����ʂ�\��ʂɔ��f, ���b�Z�[�W����, ��ʃN���A )
    while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0 && !endFlag)
    {
		fps.Update();	//�X�V

		switch (eventController)
		{
		case EventControllerEnum::Start:
			Init();											//������
			eventController = EventControllerEnum::Update;	//update�ւ̈ڍs
			break;

		case EventControllerEnum::Update:
			Draw();
			Controll();
			if (UpdateScene())//�V�[�����X�V���ꂽ��
			{
				eventController = EventControllerEnum::Start;//start�ֈڍs
			}
			break;
		}
		if (GetErrorFlag() || GetExitFlag())//�G���[���N�����ۃv���O�������I������
		{
			endFlag = true;
		}

		fps.Wait();
    }

    DxLib_End(); // DX���C�u�����I������
    return 0;
}