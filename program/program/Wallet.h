#pragma once
#include<vector>
#include "Assets.h"
#include <memory>

using namespace std;

class Wallet {

public:

	double getValue();
	Assets* getAsset(int id);
	void addAsset(Assets* asset);
	bool erase(int id);
	vector<Assets*> getList();
	void edit(int id);

private:
	vector<Assets*> list;
};

inline
void operator +=(Wallet &wallet, Assets* asset) {
	wallet.addAsset(asset);
}
inline
void operator -=(Wallet &wallet, int id) {
	wallet.erase(id);
}
