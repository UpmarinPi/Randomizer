#pragma once

#ifndef READFILE_H
#define READFILE_H
#include <iostream>
#include "DxLib.h"
#include <vector>
using namespace std;

bool ReadFile();
void InputFile(const char* _inputline);
bool CompareExt(char* data, const char* ext);


#endif