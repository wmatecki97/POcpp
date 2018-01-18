#pragma once
#include "Estate.h"
#include "Assets.h"
#include <iostream>
#include "AdditionalFunctions.h"
#include "Contract.h"
#include <iomanip>
#include <sstream> 


using namespace std;

Contract::Contract() :Assets("Kontrakt") {
	value = 0;
	subject = "Przedsiebiorca nr " + to_string(AdditionalFunctions::getUniqueInteger());
	expireTime = AdditionalFunctions::getRandom(2, 50);
	contractValue = AdditionalFunctions::getRandom(1000, 10000);
}


string Contract::getInfo()
{
	stringstream streamValue;
	streamValue << fixed << setprecision(2) << contractValue;
	string details = Assets::getInfo();
	details += " Kwota kontraktu: " + streamValue.str() + "zl Podmiot: " + subject + " Ilosc dni do  otrzymania pieniedzy: " + to_string(expireTime);
	return details;
}


string Contract::simulateFutureValue(int days)
{
	if (days > expireTime)
		return to_string(contractValue);
	else
		return "0";
}

void Contract::edit()
{
	bool isGood = false;
	int choose;
	string text;
	while (!isGood) {
		Assets::displayEditMessage();
		cout << "Aby edytowac podmiot wpisz: 4" << endl << "Aby edytowac termin realizacji wpisz: 5" << endl << "Aby edytowac wartosc kontraktu wpisz: 6" << endl;
		cin >> choose;
		if (Assets::controlEditAction(choose))break;
		switch (choose) {
		case 4: cout << "Podaj nowy podmiot" << endl; cin >> text; subject = text; break;
		case 5: cout << "Podaj nowy termin realizacji" << endl;
			try { cin >> choose; if (choose < 0 || choose>2000000000) throw 0;; expireTime = choose; }
			catch (int e) { cout << "Niepoprawna wartosc"; }
		case 6: cout << "Podaj nowa wartosc kontraktu" << endl;
			try { cin >> choose; if (choose < 0 || choose >2000000000) throw 0;; contractValue = choose; }
			catch (int e) { cout << "Niepoprawna wartosc"; }
		}
	}

}
