#include "CheckBox.h"
#include "Consts.h"
#include "DxLib.h"

CheckBox showNextCheck
(
	l_window_width - 320, 330,
	"���̃��[����\������",
	20
);

void ShowNextCheck()
{
	if (showNextCheck.CheckClickedCheckBox())
	{
		showNextCheck.SetCheckFlag(!showNextCheck.GetCheckFlag());
	}
}