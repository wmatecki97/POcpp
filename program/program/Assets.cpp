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
	this->dailyRate = AdditionalFunctions::getRandom(10, 50) / 1000;
}

Assets::Assets(char type[]) {
	id = AdditionalFunctions::getID();
	string temp(type);
	temp += to_string(id);
	name = temp;
	dailyRate = AdditionalFunctions::getRandom(0, 50) / 1000;
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
	double result = value*pow((1 + dailyRate), days);
	if (result > 0 && result < 2000000000)
		return to_string(result);
	else
		return "Bardzo duzo pieniedzy";
}

void Assets::edit()
{
	bool isGood = true;
	string text;
	int userValue;
	int choose;
	while (isGood) {
		cout << "Ay edytowac nazwe wpisz: 1" << endl << "Aby edytowac wartosc wpisz:2" << endl << "Aby edytowac dzienny procent wzrostu wartosci wpisz: 3" << endl;;
		cout << "Aby wyjsc wpisz 0" << endl;
		cin >> choose;

		switch (choose) {
		case 0: isGood = false; break;
		case 1: cout << "Podaj nowa nazwe" << endl; cin >> text; name = text; break;
		case 2: cout << "Podaj nowa wartosc" << endl;
			try { cin >> userValue; value = userValue; }
			catch (exception e) { cout << "Niepoprawna wartosc" << endl; } break;
		case 3: cout << "Podaj nowy dzienny procent wzrostu jako wartosc z zakresu 0-100" << endl;
			try { cin >> userValue; dailyRate = userValue; if (userValue > 100 || userValue < 0) throw new exception; }
			catch (exception e) { cout << "Niepoprawna wartosc" << endl; } break;
		}
	}


}

string Assets::getInfo()
{
	string info = to_string(id) + ") " + name + " Wartosc: " + to_string(value) + " Dzienny procent wzrostu wartosci: " + to_string(dailyRate);
	return info;
}
