#include "Button.h"
#include "DeleteSansyoButton.h"
#include "NameData.h"
#include "OpenFile.h"

Button deleteSansyoButton(10, 50, 30, 200, false, 1, "参照内容を削除", 20);

void DeleteSansyoButton()
{
	if (deleteSansyoButton.CheckClickedButton())
	{
		DeleteData();
		strcpy_s(fileName,MAX_PATH * 2, "");
	}
}