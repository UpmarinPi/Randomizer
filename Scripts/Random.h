#pragma once

#ifndef RANDOM_H
#define RANDOM_H
#include <vector>
using namespace std;

extern vector<int> randNum;

int GetRandNum(int order);
int GetNowRandOrder();
bool SetNextRandOrder();
void ResetAppearFlag();
void ResetRandOrder();
int GetRandRange(int min, int max);
void ShuffleRand();
void SetMaxRand(int _max);
int GetMinRand();
int GetMaxRand();

#endif