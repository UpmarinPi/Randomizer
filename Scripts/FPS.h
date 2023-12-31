#pragma once

#ifndef FPS_H
#define FPS_H
#include <iostream>
#include "Singleton.h"
using namespace std;

class Fps : public Singleton <Fps>
{
	int mStartTime;         //測定開始時刻
	int mCount;             //カウンタ
	float mFps;             //fps
	static const int N = 60;//平均を取るサンプル数
	static const int FPS = 60;	//設定したFPS

public:
	Fps();

	bool Update();

	void Draw();

	void Wait();
};
#endif