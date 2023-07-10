#pragma once

#ifndef OPENFILE_H
#define OPENFILE_H
#include <iostream>
#include "DxLib.h"
using namespace std;

extern char fileName[MAX_PATH * 2];
char* OpenFile();
int ShowWindow(HWND hwnd, LPCSTR Filter, char* FileName, DWORD Flags);

#endif