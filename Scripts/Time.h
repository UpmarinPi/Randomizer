#pragma once

#ifndef TIME_H
#define TIME_H
#include <vector>
using namespace std;

class Time
{
private:
	int hour;
	int minute;
	bool appearFlag;

public:
	int clickTime;
	Time();

	Time(int hour, int minute, bool appearFlag);

	int GetHour();
	int GetMinute();
	bool GetAppearFlag();

	void SetHour(int _hour);
	void SetMinute(int _minute);
	void SetAppearFlag(bool _appearFlag);

	void ToggleAppearFlag();
};
extern vector<Time> alarmTime;

bool AddTime(int _hour, int _minute, bool _appearFlag);
void DeleteTime(int num);
void DeleteAllTime();

#endif