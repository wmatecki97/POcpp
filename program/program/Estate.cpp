#pragma once
#include "Estate.h"
#include "Assets.h"
#include <iostream>
#include "AdditionalFunctions.h"
#include <string>


using namespace std;

Estate::Estate() : Assets("Posiadlosc")
{

	adress = "Programowo Ul. Obiektowa ";
	adress += to_string(AdditionalFunctions::getUniqueInteger());
	area = AdditionalFunctions::getRandom(20, 1000);
	value = area * 5000;
}

string Estate::getInfo()
{
	
	string details=Assets::getInfo();
	details += " Adres: " + adress + " Powierzchnia:" + to_string(area);
	return details;
}
