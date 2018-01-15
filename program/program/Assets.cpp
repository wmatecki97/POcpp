#include "Assets.h"
#include <iostream>
#include "AdditionalFunctions.h"

using namespace std;

double Assets::getValue() {
	return this->value;
}

void Assets::setValue(double val)
{
	this->value = val;
}

Assets::Assets() {
	id = AdditionalFunctions::getID();
	name = 
}