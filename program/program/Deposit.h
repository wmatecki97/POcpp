#pragma once
#include "Assets.h"
#include<string>
class Deposit: public Assets {

public:
	Deposit();
	string getInfo();
	void edit();

private:
	string bank;

};