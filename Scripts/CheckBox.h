#pragma once

#ifndef CHECKBOX_H
#define CHECKBOX_H
#include <iostream>
#include "Button.h"
using namespace std;

#define CHAR_LENGTH 64
class CheckBox
{
private:
	char check[3];
	int x;
	int y;
	Button checkBox;
	bool checkFlag;

	char text[CHAR_LENGTH];
	int fontSize;
	int boxSize;
	unsigned int textColor;

public:
	CheckBox();
	CheckBox(int _x, int _y, const char* _text, int _fontSize);

	void DrawCheckBox();

	int GetX();
	int GetY();
	Button GetCheckBoxButton();
	bool CheckClickedCheckBox();
	bool GetCheckFlag();

	void SetX(int _x);
	void SetY(int _y);
	void SetCheckFlag(bool _checkFlag);
	void SetBoxSize(int _boxSize);

};

#endif