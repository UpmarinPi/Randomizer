#include <Windows.h>
#include <string>
#include "UTF8toSJIS.h"

const char* UTF8toSjis(char* utf8)
{
	string srcUTF8 = utf8;
	//Unicode�֕ϊ���̕����񒷂𓾂�
	int lenghtUnicode = MultiByteToWideChar(CP_UTF8, 0, srcUTF8.c_str(), srcUTF8.size() + 1, NULL, 0);

	//�K�v�ȕ�����Unicode������̃o�b�t�@���m��
	wchar_t* bufUnicode = new wchar_t[lenghtUnicode];

	//UTF8����Unicode�֕ϊ�
	MultiByteToWideChar(CP_UTF8, 0, srcUTF8.c_str(), srcUTF8.size() + 1, bufUnicode, lenghtUnicode);

	//ShiftJIS�֕ϊ���̕����񒷂𓾂�
	int lengthSJis = WideCharToMultiByte(CP_THREAD_ACP, 0, bufUnicode, -1, NULL, 0, NULL, NULL);

	//�K�v�ȕ�����ShiftJIS������̃o�b�t�@���m��
	char* bufShiftJis = new char[lengthSJis];

	//Unicode����ShiftJIS�֕ϊ�
	WideCharToMultiByte(CP_THREAD_ACP, 0, bufUnicode, lenghtUnicode + 1, bufShiftJis, lengthSJis, NULL, NULL);

	std::string strSJis(bufShiftJis);

	delete bufUnicode;
	delete bufShiftJis;

	return strSJis.c_str();
}