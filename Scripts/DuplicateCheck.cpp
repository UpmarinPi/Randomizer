#include "CheckBox.h"
#include "Consts.h"
#include "DxLib.h"

CheckBox duplicateCheck
(
	l_window_width - 320, 300,
	"�����̏d����������",
	20
);

void DuplicateCheck()
{
	if (duplicateCheck.CheckClickedCheckBox())
	{
		duplicateCheck.SetCheckFlag(!duplicateCheck.GetCheckFlag());
	}
}