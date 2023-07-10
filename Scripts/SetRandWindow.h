#pragma once

#ifndef SETRANDWINDOW_H
#define SETRANDWINDOW_H
#include <iostream>
#include "SubWindow.h"
using namespace std;

extern SubWindow setRandWindow;
void SetSetRandMax(int num);
int GetSetRandMax();
void InputRandMax();
void WarningMessage();
#endif