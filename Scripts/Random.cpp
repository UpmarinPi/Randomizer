#include <random>
#include "DuplicateCheck.h"
#include "DxLib.h"
#include "NameData.h"
#include "Random.h"
#include <vector>

random_device rd;
mt19937 gen(rd());

int minRandNum = 1;
int maxRandNum = 2;
int nowRandOrder = 0;

vector<int> randNum;

int GetRandNum(int order)
{
	return randNum[order];
}
int GetNowRandOrder()
{
	return nowRandOrder;
}

bool SetNextRandOrder()
{
	if (nowRandOrder + 1 < (int)randNum.size())
	{
		if (!duplicateCheck.GetCheckFlag())
		{
			do
			{
				++nowRandOrder;
				if ((int)nameData.size() <= nowRandOrder)
				{
					return false;
				}
			} while (nameData[GetRandNum(GetNowRandOrder())].GetAppearFlag());
		}
		else
		{
			++nowRandOrder;
		}
		return true;
	}
	else
	{
		return false;
	}
}

void ResetRandOrder()
{
	nowRandOrder = 0;
	for (int i = 0; i < (int)randNum.size(); ++i)
	{
		randNum[i] = i;
	}
}
int GetRandRange(int min, int max)
{
	uniform_int_distribution<> dist(min, max);
	return dist(gen);
}

void ShuffleRand()
{
	if (duplicateCheck.GetCheckFlag())
	{
		for (int i = 0; i < (int)randNum.size(); i++)
		{
			int r = GetRandRange(minRandNum - 1, maxRandNum - 1);
			randNum[i] = r;
		}
	}
	else
	{
		for (int i = 0; i < (int)randNum.size(); i++)
		{
			do
			{
				int r = GetRandRange(minRandNum - 1, maxRandNum - 1);
				int tmp = randNum[i];
				randNum[i] = randNum[r];
				randNum[r] = tmp;
			} while (nameData[randNum[0]].GetAppearFlag());
		}
	}
}

void SetMaxRand(int _max)
{
	if (_max > 0)
	{
		maxRandNum = _max;
		randNum.resize(_max);
		ResetRandOrder();
	}
}

int GetMinRand()
{
	return minRandNum;
}
int GetMaxRand()
{
	return maxRandNum;
}