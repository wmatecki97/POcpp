#pragma once
#include "Estate.h"
#include "Assets.h"
#include <iostream>
#include "AdditionalFunctions.h"
#include "Contract.h"


using namespace std;

Contract::Contract():Assets("Kontrakt"){
	value = 0;
	subject = "Przedsiebiorca nr " + to_string(AdditionalFunctions::getUniqueInteger());
	expireTime = AdditionalFunctions::getRandom(2, 50);
}

string Contract::getDetails()
{
	string details = "Podmiot: " + subject + " Ilosc dni do  otrzymania pieniedzy: " + to_string(expireTime);
	return details;
}

string Contract::simulateFutureValue(int days)
{
	if (days > expireTime)
		return to_string(contractValue);
	else
		return "0";
}
