#pragma once
#ifndef KEYBOARD_H
#define KEYBOARD_H
#include "Singleton.h"

class Keyboard : public Singleton<Keyboard>
{

	Keyboard();
	friend Singleton< Keyboard >;

public:
	bool KeyUpdate();	//更新
	int GetPressingCount(int keyCode);//keyCodeのキーが押されているフレーム数を取得

private:
	static const int KEY_NUM = 256;	//キー総数
	int mKeyPressingCount[KEY_NUM];//押されカウンタ

	bool IsAvailableCode(int keyCode);//keyCodeが有効なキー番号か問う
};
bool GetKeyPress(int keyCode, bool nagaoshiFlag);
#endif