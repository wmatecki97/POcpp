#pragma once
#include<vector>
#include "Assets.h"

using namespace std;

class Wallet {

public:

	double getValue();
	Assets getAsset(int id);
	void addAsset(Assets asset);
	void erase(int id);

private:
	vector<Assets> list;
};

Wallet operator +=(Wallet wallet, Assets asset) {
	wallet.addAsset(asset);
}
Wallet operator -=(Wallet wallet, int id) {
	wallet.erase(id);
}
