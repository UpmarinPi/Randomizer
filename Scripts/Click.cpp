#include "Button.h"
#include "Click.h"
#include "DxLib.h"

bool CheckMousePoint(int x, int y, int width, int height)
{
	int mouseX, mouseY;
	GetMousePoint(&mouseX, &mouseY);
	return (
		x < mouseX&& mouseX < x + width &&
		y < mouseY&& mouseY < y + height
		);
}