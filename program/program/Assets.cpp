#include "Assets.h"
#include <iostream>
#include "AdditionalFunctions.h"
#include <string>
#include <iomanip>
#include <sstream> 

using namespace std;

double Assets::getValue() {
	return this->value;
}

void Assets::setValue(double val)
{
	this->value = val;
	this->dailyRate = AdditionalFunctions::getRandom(10, 50) / 1000;
}

Assets::Assets(char type[]) {
	id = AdditionalFunctions::getID();
	string temp(type);
	temp += to_string(id);
	name = temp;
	dailyRate = double(AdditionalFunctions::getRandom(10, 50)) / 10;
}

int Assets::getId() {
	return id;
}

string Assets::getName() {
	return name;
}

string Assets::getDetails() {
	return "";
}

double Assets::getRate()
{
	return dailyRate;
}

string Assets::simulateFutureValue(int days)
{
	string output = name + ": ";
	double result = value*pow((1.0 + double(dailyRate/100)), days);
	if (result > 0 && result < 2000000000)
		output += to_string(result) + "zl";
	else
		output += "Bardzo duzo pieniedzy";
	return output;
}

void Assets::edit()
{
	bool isGood = false;
	int choose;
	while (!isGood) {
		displayEditMessage();
		cin >> choose;
		isGood = controlEditAction(choose);	
	}
}

string Assets::getInfo()
{
	stringstream streamValue, streamPercentage;
	streamValue << fixed << setprecision(2) << value;
	streamPercentage << fixed << setprecision(2) << dailyRate;

	string stringValue = streamValue.str(), stringPercentage=streamPercentage.str();
	string info = to_string(id) + ") " + name + " Wartosc: " + stringValue + "zl Dzienny procent wzrostu wartosci: " + stringPercentage +"%";
	return info;
}



void Assets::displayEditMessage()
{
	cout << "Aby wrocic wpisz 0" << endl;
	cout << "Ay edytowac nazwe wpisz: 1" << endl << "Aby edytowac wartosc wpisz:2" << endl << "Aby edytowac dzienny procent wzrostu wartosci wpisz: 3" << endl;
}

bool Assets::controlEditAction(int choose)
{
	bool isGood=false;
	int userValue;
	string text;
	switch (choose) {
	case 0: isGood = true; break;
	case 1: cout << "Podaj nowa nazwe" << endl; cin >> text; name = text; break;
	case 2: cout << "Podaj nowa wartosc" << endl;
		try { cin >> userValue; if (userValue < 0 || userValue>2000000000) 
			throw 0;; 
		value = userValue; }
		catch (int e) { cout << "Niepoprawna wartosc" << endl; } break;
	case 3: cout << "Podaj nowy dzienny procent wzrostu jako wartosc z zakresu 0-100" << endl;
		try { cin >> userValue;  if (userValue > 100 || userValue < 0) throw 0; dailyRate = userValue;}
		catch (int e) { cout << "Niepoprawna wartosc" << endl; } break;
	}
	return isGood;
}
