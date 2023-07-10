#include "Button.h"
#include "DxLib.h"
#include "NameData.h"
#include "OpenFile.h"
#include "ReadFile.h"
#include "SansyoButton.h"

Button sansyoButton(10, 10, 30, 100, false, 1, "éQè∆", 20);

void SansyoButton()
{
	sansyoButton.SetX(sansyoButton.GetX());
	if (sansyoButton.CheckClickedButton())
	{
		OpenFile();
		ReadFile();
	}
}
