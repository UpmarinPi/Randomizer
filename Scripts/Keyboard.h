#pragma once
#ifndef KEYBOARD_H
#define KEYBOARD_H
#include "Singleton.h"

class Keyboard : public Singleton<Keyboard>
{

	Keyboard();
	friend Singleton< Keyboard >;

public:
	bool KeyUpdate();	//�X�V
	int GetPressingCount(int keyCode);//keyCode�̃L�[��������Ă���t���[�������擾

private:
	static const int KEY_NUM = 256;	//�L�[����
	int mKeyPressingCount[KEY_NUM];//������J�E���^

	bool IsAvailableCode(int keyCode);//keyCode���L���ȃL�[�ԍ����₤
};
bool GetKeyPress(int keyCode, bool nagaoshiFlag);
#endif