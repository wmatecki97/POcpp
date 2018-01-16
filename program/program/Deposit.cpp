#include <iostream>
#include "Deposit.h"
#include "AdditionalFunctions.h"
using namespace std;

double Deposit::getRate() {
	return dailyRate;
}

double Deposit::getValue() {

	return value;

}

Deposit::Deposit() : Assets("Lokata"){
	value = AdditionalFunctions::getRandom(1000, 10000);
	dailyRate = AdditionalFunctions::getRandom(1, 50) / 1000;//daily rate is 0.5-5 %
}