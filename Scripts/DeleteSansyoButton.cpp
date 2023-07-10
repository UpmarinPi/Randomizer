#include "Button.h"
#include "DeleteSansyoButton.h"
#include "NameData.h"
#include "OpenFile.h"

Button deleteSansyoButton(10, 50, 30, 200, false, 1, "QÆ“à—e‚ğíœ", 20);

void DeleteSansyoButton()
{
	if (deleteSansyoButton.CheckClickedButton())
	{
		DeleteData();
		strcpy_s(fileName,MAX_PATH * 2, "");
	}
}