#pragma once

#ifndef DRAW_H
#define DRAW_H
#include <iostream>
#include "DxLib.h"
#include "Singleton.h"
#include <vector>
using namespace std;

class BackgroundColor: public Singleton <BackgroundColor>
{
	unsigned int backgroundColor;
public:
	unsigned int r;
	unsigned int g;
	unsigned int b;

public:
	BackgroundColor();
	BackgroundColor(unsigned int _r, unsigned int _g, unsigned int _b);
	int SetBG();
	void SetBGColor(unsigned int _r, unsigned int _g, unsigned int _b);
	unsigned int GetBackgroundColor();
};
extern BackgroundColor backgroundColor;
void Draw();

#endif