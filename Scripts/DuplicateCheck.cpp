#include "CheckBox.h"
#include "Consts.h"
#include "DxLib.h"

CheckBox duplicateCheck
(
	l_window_width - 320, 300,
	"乱数の重複を許可する",
	20
);

void DuplicateCheck()
{
	if (duplicateCheck.CheckClickedCheckBox())
	{
		duplicateCheck.SetCheckFlag(!duplicateCheck.GetCheckFlag());
	}
}