#pragma once

#ifndef NAMEDATA_H
#define NAMEDATA_H
#include <vector>
using namespace std;

class NameData
{
private:
	char name[CHAR_MAX];
	int dataXInTitle;
	int dataYInTitle;
	bool appearFlag;

public:
	int clickTime;
	NameData();

	NameData(const char* _name, int _dataXInTitle, int _dataYInTitle, bool _appearFlag);

	const char* GetNameOfData();
	int GetDataXInTitle();
	int GetDataYInTitle();
	bool GetAppearFlag();

	void SetNameOfData(char* _name);
	void SetDataXInTitle(int _dataXInTitle);
	void SetDataYInTitle(int _dataYInTitle);
	void SetAppearFlag(bool _appearFlag);

	void ToggleAppearFlag();
};
extern vector<NameData> nameData;

const char* GetNameOfData(int num);
void SetNumberData(int order);
void AddData(const char* _name, bool _appearFlag);
void DeleteData();

#endif