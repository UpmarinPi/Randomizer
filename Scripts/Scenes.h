#pragma once

#ifndef SCENES_H
#define SCENES_H
#include <iostream>
using namespace std;
enum class SceneEnum
{
	Title = 0,
	Process = 1,
	SetRand = 2,
	SetAlarm = 3,
};

SceneEnum GetScene();
void SetScene(SceneEnum);
bool UpdateScene();

#endif