#pragma once
#include<vector>
#include "Assets.h"

using namespace std;

class Wallet {

public:

	double getValue();
	Assets getAsset(int id);
	void addAsset(Assets asset);

private:
	vector<Assets> list;
};