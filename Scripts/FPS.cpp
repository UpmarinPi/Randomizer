#include <math.h>
#include "DxLib.h"
#include "FPS.h"

Fps::Fps()
{
	mStartTime = 0;
	mCount = 0;
	mFps = 0;
}

bool Fps::Update()
{
	if (mCount == 0)
	{ //1�t���[���ڂȂ玞�����L��
		mStartTime = GetNowCount();
	}
	if (mCount == N)
	{ //60�t���[���ڂȂ畽�ς��v�Z����
		int t = GetNowCount();
		mFps = 1000.f / ((t - mStartTime) / (float)N);
		mCount = 0;
		mStartTime = t;
	}
	mCount++;
	return true;
}

void Fps::Draw()
{
	SetFontSize(20);
	DrawFormatString(0, 0, GetColor(255, 255, 255), "%.1f", mFps);
}

void Fps::Wait()
{
	int tookTime = GetNowCount() - mStartTime;	//������������
	int waitTime = mCount * 1000 / FPS - tookTime;	//�҂ׂ�����
	if (waitTime > 0)
	{
		Sleep(waitTime);	//�ҋ@
	}
}