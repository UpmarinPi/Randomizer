#pragma once

#ifndef SAVEFILE_H
#define SAVEFILE_H
#include <iostream>
#include "DxLib.h"
using namespace std;

class SaveData
{
	char lastFilePass[MAX_PATH];
public:
	char* GetLastFilePase();
};
bool SaveFile();


#endif