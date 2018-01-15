#include "Wallet.h"
#include "Assets.h"
#include <iostream>

using namespace std;

double Wallet::getValue() {

	double value = 0;
	for (Assets asset : this->list) {
		value += asset.getValue();
	}
	return value;
}

void Wallet::addAsset(Assets asset) {

	list.push_back(asset);

}

