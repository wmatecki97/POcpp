#include "InvestmentFund.h"
#include <iostream>
#include <ctime>
#include <cstdio>
#include "AdditionalFunctions.h"

using namespace std;

InvestmentFund::InvestmentFund():Assets("FunduszInwestycyjny"){
	value = AdditionalFunctions::getRandom(1000, 10000);	
	dailyRate = AdditionalFunctions::getRandom(0, 5) / 100;
}

string InvestmentFund::getDetails() {
	return "qweqweqweqwe";
}