#include "DxLib.h"
#include "OpenFile.h"
#include <string>
using namespace std;

char fileName[MAX_PATH * 2];


char* OpenFile()
{
	ZeroMemory(fileName, MAX_PATH * 2);

	ShowWindow(GetMainWindowHandle(), "*.txt", fileName, 0);
	return fileName;
}


int ShowWindow(HWND hwnd, LPCSTR Filter, char* FileName, DWORD Flags)
{
	OPENFILENAME OFN;

	// �\���̂�ݒ�
	ZeroMemory(&OFN, sizeof(OPENFILENAME));
	OFN.lStructSize = sizeof(OPENFILENAME);
	OFN.hwndOwner = hwnd;
	OFN.lpstrFilter = Filter;
	OFN.lpstrFile = FileName;
	OFN.nMaxFile = MAX_PATH * 2;
	OFN.Flags = Flags;
	OFN.lpstrTitle = "�t�H���_���J��";
	return (GetOpenFileName(&OFN));
}