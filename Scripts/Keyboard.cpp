#include "Keyboard.h"
#include <DxLib.h>
#define WAIT_KEY_FRAME 30

Keyboard::Keyboard()
{
	memset(mKeyPressingCount, 0, sizeof(mKeyPressingCount));
}

//更新
bool Keyboard::KeyUpdate()
{
	char nowKeyStatus[KEY_NUM];
	GetHitKeyStateAll(nowKeyStatus);       //今のキーの入力状態を取得
	for (int i = 0; i < KEY_NUM; i++)
	{
		if (nowKeyStatus[i] != 0)
		{            //i番のキーが押されていたら
			mKeyPressingCount[i]++;          //押されカウンタを増やす
		}
		else
		{                             //i番のキーが離されていたら
			if (mKeyPressingCount[i] > 0)
			{ //押されカウンタが0より大きければ
				mKeyPressingCount[i] = 0;    //0に戻す
			}
		}
	}
	return true;
}

//keyCodeのキーが押されているフレーム数を返す
int Keyboard::GetPressingCount(int keyCode)
{
	if (!Keyboard::IsAvailableCode(keyCode))
	{
		return -1;
	}
	return mKeyPressingCount[keyCode];
}

//keyCodeが有効な値かチェックする
bool Keyboard::IsAvailableCode(int keyCode)
{
	return (0 <= keyCode && keyCode < KEY_NUM);
}

bool GetKeyPress(int keyCode, bool nagaoshiFlag)
{
	if (Keyboard::Instance()->GetPressingCount(keyCode) == 1)
	{
		return true;
	}
	else
	{
		return (nagaoshiFlag &&
			Keyboard::Instance()->GetPressingCount(keyCode) >= WAIT_KEY_FRAME);
	}
}