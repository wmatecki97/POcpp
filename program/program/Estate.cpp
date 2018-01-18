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
	details += " Adres: " + adress + " Powierzchnia:" + to_string(area)+"m2";
	return details;
}

void Estate::edit()
{
	bool isGood = false;
	int choose;
	string text;
	while (!isGood) {
		Assets::displayEditMessage();
		cout << "Aby edytowac adres wpisz: 4" << endl << "Aby edytowac powierzchnie wpisz: 5" << endl;
		cin >> choose;
		if (Assets::controlEditAction(choose))break;
		switch (choose) {
		case 4: cout << "Podaj nowy adres" << endl; cin >> text; adress = text; break;
		case 5: cout << "Podaj nowa powierzchnie" << endl;
			try { cin >> choose; if (choose < 10 || choose>2000000000) throw 0;; area = choose; }
			catch (int e) { cout << "Niepoprawna wartosc"; }
		}
	}
}
