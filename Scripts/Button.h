#pragma once

#ifndef BUTTON_H
#define BUTTON_H
#include <iostream>
#include "SubWindow.h"
using namespace std;

#define CHAR_LENGTH 64
class Button
{
private:
	int x;//����̍��W
	int y;

	int height;	//�c
	int width;	//��

	bool fillBoxFlag;//�{�b�N�X�̒��g�𖄂߂邩
	int boxSize;//�{�b�N�X�̑傫���B�悤�͐��̑���

	char text[CHAR_LENGTH];
	int fontSize;

	unsigned int boxColor;
	unsigned int textColor;

	int clickTime;

public:
	Button();
	Button(int _x, int _y, int _height, int _width, bool _fillBoxFlag, int _boxSize, const char* _text,int _fontSize);

	void DrawButton();
	bool CheckMousePointInButton();
	bool CheckClickedButton();

	int GetX();
	int GetY();
	int GetHeight();
	int GetWidth();
	int GetFontSize();

	void SetButton(int _x, int _y, int _height, int _width, bool _fillBoxFlag, int _boxSize, const char* _text, int _fontSize);
	void SetX(int _x);
	void SetY(int _y);
	void SetHeight(int _height);
	void SetWidth(int _width);
	void SetBoxColor(unsigned int _boxColor);
	void SetTextColor(unsigned int _textColor);
};

#endif