#include "InvestmentFund.h"
#include <iostream>
#include <ctime>
#include <cstdio>
#include "AdditionalFunctions.h"

using namespace std;

InvestmentFund::InvestmentFund(int a) {
	if (a > 0)
		value = AdditionalFunctions::getRandom();
	else
		cout << endl << "BLEDNA WARTOSC" << endl;

}