#include "Assets.h"
#include <iostream>
#include "AdditionalFunctions.h"
#include <string>

using namespace std;

double Assets::getValue() {
	return this->value;
}

void Assets::setValue(double val)
{
	this->value = val;
}

Assets::Assets(char type[]) {
	id = AdditionalFunctions::getID();
	string temp(type);
	temp += to_string(id);
	name = temp;
}

int Assets::getId(){
	return id;
}
string Assets::getName() {
	return name;
}



string Assets::getDetails() {
	return "";
}
