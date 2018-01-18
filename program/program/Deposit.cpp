#pragma once
#include <iostream>
#include "Deposit.h"
#include "AdditionalFunctions.h"
using namespace std;

string Deposit::getDetails() {
	string details = "Zdeponowana w banku: " + bank;
	return details;
}


Deposit::Deposit() : Assets("Lokata"){
	value = AdditionalFunctions::getRandom(1000, 10000);
	dailyRate = AdditionalFunctions::getRandom(1, 50) / 1000;//daily rate is 0.5-5 %
	bank = "Bank nr ";
	bank += to_string(AdditionalFunctions::getRandom(1, 5));

}