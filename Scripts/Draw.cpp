#include "Button.h"
#include "Draw.h"
#include "DxLib.h"
#include "ListOfButtons.h"
#include "ListOfCheckBoxes.h"
#include "ListOfTexts.h"
#include "ListOfSubWindow.h"
#include "NameData.h"
#include "OpenFile.h"
#include "Scenes.h"


/// <summary>
/// ï`âÊèàóù
/// </summary>
/// #include <list>

BackgroundColor::BackgroundColor()
{
	r = 0;
	g = 0;
	b = 0;
	backgroundColor = GetColor(r, g, b);
}
BackgroundColor::BackgroundColor(unsigned int _r, unsigned int _g, unsigned int _b)
{
	r = _r;
	g = _g;
	b = _b;
	backgroundColor = GetColor(r, g, b);
}
int BackgroundColor::SetBG()
{
	return SetBackgroundColor(r, g, b);
}
void BackgroundColor::SetBGColor(unsigned int _r, unsigned int _g, unsigned int _b)
{
	r = _r;
	g = _g;
	b = _b;
	backgroundColor = GetColor(r, g, b);
}
unsigned int BackgroundColor::GetBackgroundColor()
{
	return backgroundColor;
}

BackgroundColor backgroundColor;

void Draw()
{
	backgroundColor.SetBG();
	switch (GetScene())
	{
	case SceneEnum::Title://É^ÉCÉgÉã
		DrawTitleSubWindows();
		DrawTitleTexts();
		DrawTitleButtons();
		DrawTitleCheckBoxes();
		break;

	case SceneEnum::Process:
		DrawProcessTexts();
		DrawProcessButtons();
		break;
	case SceneEnum::SetRand:
		DrawSetRandTexts();
		DrawSetRandButtons();
		DrawSetRandSubWindows();
		break;
	case SceneEnum::SetAlarm:
		DrawSetAlarmTexts();
		DrawSetAlarmButtons();
		DrawSetAlarmSubWindows();
		DrawSetAlarmCheckBoxes();
	}
}