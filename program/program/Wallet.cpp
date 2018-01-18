#include "Wallet.h"
#include "Assets.h"
#include <iostream>

using namespace std;

double Wallet::getValue() {

	double value = 0;
	for (Assets* asset : this->list) {
		value += asset->getValue();
	}
	return value;
}

void Wallet::addAsset(Assets* asset) {

	list.push_back(asset);

}

bool Wallet::erase(int id) {
	bool isGood = false;
	for (size_t i = 0; i < list.size(); i++) {
		if (list[i]->getId() == id) {
			list.erase(list.begin() + i);
			isGood = true;
			break;
		}			
	}
	return isGood;
}

vector<Assets*> Wallet::getList() {
	return list;
}

void Wallet::edit(int id)
{
	for (size_t i; i < list.size(); i++) {
		if (list[i]->getId() == id)
			list[i]->edit();
	}
}

Assets* Wallet::getAsset(int id) {
	for (size_t i = 0; i < list.size(); i++) {
		if (list[i]->getId() == id)
			return list[i];
	}
}
