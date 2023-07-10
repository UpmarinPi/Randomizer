#include "DxLib.h"
#include "NameData.h"
#include "SetAlarmDataWindow.h"
#include "SubWindow.h"
#include "Time.h"

const int MAX_LISTALARM_COUNT = 25;
const int timeTextWidth = 50;

SubWindow alarmDataWindow(10, 160, 530, 16 * 20 + 20, 2);


void AlarmDataWindow()
{
	int gyo;
	if (alarmTime.size() != 0)
	{
		gyo = (alarmTime.size() - 1) / MAX_LISTALARM_COUNT + 1;
	}
	else
	{
		gyo = 1;
	}
	alarmDataWindow.SetWidth(gyo * timeTextWidth + (gyo - 1) * 20 + 40);
	if ((int)alarmTime.size() < MAX_LISTALARM_COUNT)
	{
		alarmDataWindow.SetHeight(alarmTime.size() * 20 + 40);
	}
	else
	{
		alarmDataWindow.SetHeight(MAX_LISTALARM_COUNT * 20 + 40);
	}
}