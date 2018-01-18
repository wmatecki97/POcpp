#pragma once
#include "Assets.h"
#include<string>
class Deposit: public Assets {

public:
	Deposit();
	string getDetails();

private:
	string bank;

};