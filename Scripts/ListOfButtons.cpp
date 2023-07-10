#include "ChangeMaxRandButton.h"
#include "ConfirmButton.h"
#include "DeleteSansyoButton.h"
#include "EndButton.h"
#include "InitAppearButton.h"
#include "NextRandButton.h"
#include "ProcessButton.h"
#include "SansyoButton.h"
#include "SetAlarmButton.h"
#include "StopProcessButton.h"

void ClickTitleButtons()
{
	SansyoButton();
	DeleteSansyoButton();
	InitAppearButton();
	ProcessButton();
	ChangeMaxRandButton();
	SetAlarmButton();

	EndButton();
}

void ClickProcessButtons()
{
	NextRandButton();
	StopProcessButton();
}

void ClickSetRandButtons()
{
	ConfirmButton();
}

void ClickSetAlarmButtons()
{

}

void DrawTitleButtons()
{
	sansyoButton.DrawButton();
	deleteSansyoButton.DrawButton();
	processButton.DrawButton();
	changeMaxRandButton.DrawButton();
	initAppearButton.DrawButton();
	setAlarmButton.DrawButton();
	
	endButton.DrawButton();
}

void DrawProcessButtons()
{
	nextRandButton.DrawButton();
	stopProcessButton.DrawButton();
}

void DrawSetRandButtons()
{
	confirmButton.DrawButton();
}

void DrawSetAlarmButtons()
{

}