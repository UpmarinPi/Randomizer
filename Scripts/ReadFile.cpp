#include "Draw.h"
#include <fstream>
#include "NameData.h"
#include "NameDataWindow.h"
#include "OpenFile.h"
#include "Random.h"
#include "ReadFile.h"
#include "SetRandWindow.h"
#include <string>
#include "UTF8toSJIS.h"
#include <vector>

bool ReadFile()
{

	ifstream ifs(fileName);
	if (ifs.fail())
	{
		printfDx("failed to read the file");
		return false;//ÉtÉ@ÉCÉãÇÃì«Ç›çûÇ›é∏îs
	}
	nameData.clear();
	maxTextWidth = 0;
	char inputline[CHAR_MAX];
	while (ifs.getline(inputline, CHAR_MAX))
	{
		InputFile(inputline);
	}
	SetSetRandMax(nameData.size());
	ResetRandOrder();
	return true;
}

void InputFile(const char* _inputline)
{
	int countline = 0;
	bool appearFlag = false;
	while (1)
	{
		char* input = new char[CHAR_MAX];
		for (int i = 0; i < CHAR_MAX; ++i)
		{
			input[i] = _inputline[countline];
			++countline;
			if (input[0] == '/' || input[0] == '\0')
			{
				return;
			}
			else if (input[0] == '*')
			{
				appearFlag = true;
				i = -1;
				continue;
			}
			else if (input[i] == ',')
			{
				input[i] = '\0';
				AddData(input, appearFlag);
				break;
			}
			else if (input[i] == '\0')
			{
				AddData(input, appearFlag);
				return;
			}
		}

	}
}


bool CompareExt(char* data, const char* ext)
{
	return strcmp(ext, data);
}