#pragma once
#include "Assets.h"

class Deposit: public Assets {

public:
	Deposit();
	double getValue();
	double getRate(); 

private:
	double value;
	double rate;

};