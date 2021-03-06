﻿#include<iostream>
#include "Menu.h"
#include "InvestmentFund.h"
#include "Contract.h"
#include "Estate.h"
#include "Deposit.h"
#include "Save.h"

using namespace std;

static Wallet wallet;

void Menu::init() {

}

void Menu::start()
{
	cout << endl << endl;
	cout << "Co chcesz zrobic?" << endl <<"Aby wyjsc wpisz: 0"<<endl<< "Aby dodac aktywa wpisz: 1" << endl << "Aby wyswietlic aktywa wpisz: 2" << endl;
	cout << "Aby usunac aktywa wpisz: 3" << endl << "Aby edytowac aktywa wpisz: 4" << endl << "Aby symulowac wartosc portfela w przyszlosci wpisz: 5" << endl;
	int input;
	cin >> input;
	switch (input) {
	case 0: break;
	case 1: addItem(); break;
	case 2: display(); break;
	case 3: deleteItem(); break;
	case 4: editItem(); break;
	case 5: simulateValue(); break;
	default: cout << "NIEPOPRAWNA KOMENDA" << endl; start();
	}
}

void Menu::addItem()
{
	system("cls");
	cout << "Co chcesz dodac?" << endl << "Aby dodac fundusz inwestycyjny wpisz: 1" << endl << "Aby dodac Konrtakt wpisz: 2" << endl;
	cout << "Aby dodac Lokate wpisz: 3" << endl << "Aby dodac Nieruchomosc wpisz: 4" << endl;
	int input;
	cin >> input;
	Assets* asset = NULL;
	bool isGood = false;
	switch (input) {
	case 1: asset = new InvestmentFund(); isGood = true; break;
	case 2: isGood = true; asset = new Contract(); break;
	case 3: isGood = true; asset = new Deposit(); break;
	case 4: isGood = true; asset = new Estate(); break;
	default: cout << "NIEPOPRAWNA KOMENDA" << endl;
	}
	if (isGood) {
		wallet += asset;
		cout << "POMYSLNIE DODANO" << endl;
	}
	else
		cout << "Niepoprawna wartosc" << endl;
	start();

}

void Menu::display() {
	system("cls");
	auto list = wallet.getList();
	if (list.size() > 0) {
		cout << "Lista aktywow w portfelu:" << endl;
		for (size_t i = 0; i < list.size(); i++) {
			auto a = list[i];
			auto info = a->getInfo();
			printf("%s\n", info.c_str());
		}
	}
	else cout << "BRAK AKTYWOW W PORTFELU" << endl << endl;
	start();

}

void Menu::deleteItem()
{
	system("cls");
	auto list = wallet.getList();
	if (list.size() > 0) {
		cout << "Ktory przedmiot chcesz usunac?" << endl << "Aby wrocic wpisz: 0" << endl;
		for (size_t i = 0; i < list.size(); i++) {
			auto name = list[i]->getName();
			auto id = list[i]->getId();
			printf("%d) %s \n", id, name.c_str());
		}
		int choose;
		cin >> choose;
		if (choose != 0)
			if (wallet.erase(choose))
				cout << "POMYSLNIE USUNIETO" << endl;
			else
				cout << "BLEDNA WARTOSC" << endl;
	}
	else cout << "BRAK AKTYWOW W PORTFELU" << endl << endl;
	start();

}

void Menu::editItem()
{
	system("cls");
	auto list = wallet.getList();
	if (list.size() > 0) {
		cout << "Ktory przedmiot chcesz edytowac?" << endl << "Aby wrocic wpisz: 0" << endl;
		for (size_t i = 0; i < list.size(); i++) {
			auto name = list[i]->getName();
			auto id = list[i]->getId();
			printf("%d) %s \n", id, name.c_str());
		}
		int choose;
		cin >> choose;
		if (choose != 0)
			wallet.edit(choose);
	}
	else cout << "BRAK AKTYWOW W PORTFELU" << endl << endl;
	start();
}

void Menu::simulateValue()
{
	system("cls");
	cout << "Aby ujrzec przyszla wartosc aktywow wprowadz liczbę dni" << endl << "Za ile dni: ";
	int choose;
	try {
		cin >> choose;
		wallet.simulate(choose);
	}
	catch (int e) {
		cout << "Niepoprawna wartosc";
	}
	start();
}


