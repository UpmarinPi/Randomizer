#pragma once

#ifndef INFOBUTTON_H
#define INFOBUTTON_H
#include <iostream>
#include "SubWindow.h"
using namespace std;

#define CHAR_LENGTH 64
class InfoButton
{
private:
	int x;//����̍��W
	int y;

	int height;	//�c
	int width;	//��

	int fontSize;

	unsigned int color;

	SubWindow subWindow;
public:
	InfoButton();
	InfoButton(int _x, int _y, SubWindow _subWindow);

	void DrawInfoButton();
	bool CheckMousePoint();
	bool CheckClickedButton();
};

#endif