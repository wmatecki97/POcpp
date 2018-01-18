#pragma once
#include "Assets.h"
#include<string>
class Contract : public Assets {

public:
	Contract();
	string getInfo();
	string simulateFutureValue(int days);
	void edit();

private:
	string subject;
	int expireTime; // Time after which wallets can add contract value
	int contractValue;

};
