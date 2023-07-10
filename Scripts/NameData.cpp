#include "DxLib.h"
#include <iostream>
#include <string>
#include "NameData.h"
#include "NameDataWindow.h"
#include "Random.h"
#include <vector>

vector<NameData> nameData;

NameData::NameData()
{
	strcpy_s(name, CHAR_MAX, "");
	dataXInTitle = 0;
	dataYInTitle = 0;
	appearFlag = false;
	clickTime = 0;
}

NameData::NameData(const char* _name, int _dataXInTitle, int _dataYInTitle, bool _appearFlag)
{
	strcpy_s(name, CHAR_MAX, _name);
	dataXInTitle = _dataXInTitle;
	dataYInTitle = _dataYInTitle;
	appearFlag = _appearFlag;
	clickTime = 0;
}

const char* NameData::GetNameOfData()
{
	return name;
}
int NameData::GetDataXInTitle()
{
	return dataXInTitle;
}
int NameData::GetDataYInTitle()
{
	return dataYInTitle;
}
bool NameData::GetAppearFlag()
{
	return appearFlag;
}

void NameData::SetNameOfData(char* _name)
{
	strcpy_s(name, CHAR_MAX, _name);
}
void NameData::SetDataXInTitle(int _dataXInTitle)
{
	dataXInTitle = _dataXInTitle;
}
void NameData::SetDataYInTitle(int _dataYInTitle)
{
	dataYInTitle = _dataYInTitle;
}
void NameData::SetAppearFlag(bool _appearFlag)
{
	appearFlag = _appearFlag;
}

void NameData::ToggleAppearFlag()
{
	appearFlag = !appearFlag;
}

void SetNumberData(int order)
{
	nameData.clear();

	for (int i = 0; i < order; ++i)
	{
		char name[8];
		strcpy_s(name, 8, to_string(i + 1).c_str());
		AddData(name, false);

		int textWidth = GetDrawStringWidth(name, strlen(name));
		if (textWidth > maxTextWidth)
		{
			maxTextWidth = textWidth;
		}
	}
}

const char* GetNameOfData(int num)
{
	return nameData[num].GetNameOfData();
}
void AddData(const char* _name, bool _appearFlag)
{
	NameData kariNameData
	(
		_name,
		0,
		0,
		_appearFlag
	);
	nameData.push_back(kariNameData);
	int textWidth = GetDrawStringWidth(_name, strlen(_name));
	if (textWidth > maxTextWidth)
	{
		maxTextWidth = textWidth;
	}
}

void ResetAppearFlag()
{
	for (int i = 0; i < (int)nameData.size(); ++i)
	{
		nameData[i].SetAppearFlag(false);
	}

}

void DeleteData()
{
	nameData.clear();
	maxTextWidth = 0;
}