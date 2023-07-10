#include "Keyboard.h"
#include <DxLib.h>
#define WAIT_KEY_FRAME 30

Keyboard::Keyboard()
{
	memset(mKeyPressingCount, 0, sizeof(mKeyPressingCount));
}

//�X�V
bool Keyboard::KeyUpdate()
{
	char nowKeyStatus[KEY_NUM];
	GetHitKeyStateAll(nowKeyStatus);       //���̃L�[�̓��͏�Ԃ��擾
	for (int i = 0; i < KEY_NUM; i++)
	{
		if (nowKeyStatus[i] != 0)
		{            //i�Ԃ̃L�[��������Ă�����
			mKeyPressingCount[i]++;          //������J�E���^�𑝂₷
		}
		else
		{                             //i�Ԃ̃L�[��������Ă�����
			if (mKeyPressingCount[i] > 0)
			{ //������J�E���^��0���傫�����
				mKeyPressingCount[i] = 0;    //0�ɖ߂�
			}
		}
	}
	return true;
}

//keyCode�̃L�[��������Ă���t���[������Ԃ�
int Keyboard::GetPressingCount(int keyCode)
{
	if (!Keyboard::IsAvailableCode(keyCode))
	{
		return -1;
	}
	return mKeyPressingCount[keyCode];
}

//keyCode���L���Ȓl���`�F�b�N����
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