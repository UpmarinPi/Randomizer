#include "Time.h"

vector<Time> alarmTime;
Time::Time()
{
	hour = 0;
	minute = 0;
	appearFlag = false;
	clickTime = 0;
}

Time::Time(int _hour, int _minute, bool _appearFlag)
{
	hour = _hour;
	minute = _minute;
	appearFlag = _appearFlag;
	clickTime = 0;
}

int Time::GetHour()
{
	return hour;
}
int Time::GetMinute()
{
	return minute;
}
bool Time::GetAppearFlag()
{
	return appearFlag;
}

void Time::SetHour(int _hour)
{
	hour = _hour;
}
void Time::SetMinute(int _minute)
{
	minute = _minute;
}
void Time::SetAppearFlag(bool _appearFlag)
{
	appearFlag = _appearFlag;
}
void Time::ToggleAppearFlag()
{
	appearFlag = !appearFlag;
}

bool AddTime(int _hour, int _minute, bool _appearFlag)
{
	for (int i = 0; i < (int)alarmTime.size(); ++i)
	{
		if (alarmTime[i].GetHour() == _hour && alarmTime[i].GetMinute() == _minute)
		{
			//“¯Žž‚ª‚ ‚Á‚½ê‡false‚ð•Ô‚·
			return false;
		}
	}
	Time karitime(_hour, _minute, _appearFlag);
	alarmTime.push_back(karitime);
	return true;
}

void DeleteTime(int num)
{
	alarmTime.erase(alarmTime.begin() + num - 1);
}

void DeleteAllTime()
{
	alarmTime.clear();
}