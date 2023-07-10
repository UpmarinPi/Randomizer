#pragma once

#ifndef SUBWINDOW_H
#define SUBWINDOW_H
#include <iostream>
#include "Button.h"
#include <vector>
using namespace std;

class SubWindow
{
public:
	bool showFlag;
private:
	int x;//����̍��W
	int y;

	int height;	//�c
	int width;	//��

	int boxSize;//�{�b�N�X�̑傫���B�悤�͐��̑���

	unsigned int boxColor;

public:
	SubWindow();
	SubWindow(int _x, int _y, int _height, int _width, int _boxSize);

	void DrawSubWindow();
	bool GetShowFlag();
	void DrawStringInSub(int textX, int textY, const char* text, unsigned int color);
	void DrawFormatStringInSub(int textX, int textY, unsigned int color, const char* text, ...);

	int GetX();
	int GetY();
	int GetHeight();
	int GetWidth();

	void SetX(int _x);
	void SetY(int _y);
	void SetHeight(int _height);
	void SetWidth(int _width);
	void SetBoxColor(unsigned int _boxColor);
};
#endif