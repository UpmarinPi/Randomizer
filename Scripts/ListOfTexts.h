#pragma once

#ifndef LISTOFTEXTS_H
#define LISTOFTEXTS_H
#include <iostream>
#include "Button.h"
#include "DxLib.h"
using namespace std;

extern bool noAppearWarningFlag;
void DrawTitleTexts();
void DrawProcessTexts();
void DrawSetRandTexts();
void DrawSetAlarmTexts();
void ClickTitleTexts();
void ClickSetAlarmTexts();
bool CheckClickedText(int num);
#endif