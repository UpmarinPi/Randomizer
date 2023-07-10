#include "Button.h"
#include "Consts.h"
#include "EndButton.h"
#include "Exit.h"

Button endButton(l_window_width - 125, 18, 30, 100, false, 1, "èIóπ", 20);

void EndButton()
{
	if (endButton.CheckClickedButton())
	{
		Exit();
	}
}