#pragma once
#include <iostream>
#include "Deposit.h"
#include "AdditionalFunctions.h"
using namespace std;

string Deposit::getInfo() {
	string details = Assets::getInfo();
	details += " Zdeponowana w banku: " + bank;
	return details;
}

void Deposit::edit()
{
	bool isGood = false;
	int choose;
	string text;
	while (!isGood) {
		Assets::displayEditMessage();
		cout << "Aby edytowac bank wpisz: 4" << endl;
		cin >> choose;
		if (Assets::controlEditAction(choose))break;
		switch (choose) {
		case 4: cout << "Podaj nowy bank" << endl; cin >> text; bank = text; break;
		}
	}
}


Deposit::Deposit() : Assets("Lokata"){
	value = AdditionalFunctions::getRandom(1000, 10000);
	bank = "Bank nr ";
	bank += to_string(AdditionalFunctions::getRandom(1, 5));

}