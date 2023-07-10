#pragma once

#ifndef FPS_H
#define FPS_H
#include <iostream>
#include "Singleton.h"
using namespace std;

class Fps : public Singleton <Fps>
{
	int mStartTime;         //����J�n����
	int mCount;             //�J�E���^
	float mFps;             //fps
	static const int N = 60;//���ς����T���v����
	static const int FPS = 60;	//�ݒ肵��FPS

public:
	Fps();

	bool Update();

	void Draw();

	void Wait();
};
#endif