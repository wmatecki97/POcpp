#include<iostream>
#include "Menu.h"
#include "InvestmentFund.h"

using namespace std;

static Wallet wallet;

void Menu::init() {

}

void Menu::start()
{
	cout << "Co chcesz zrobic?" << endl << "Aby dodac aktywa wpisz: 1" << endl << "Aby wyswietlic aktywa wpisz: 2" << endl << "Aby usunac aktywa wpisz: 3" << endl << "Aby edytowac aktywa wpisz: 4"<<endl;
	int input;
	cin >> input;
	switch (input) {
	case 1: addItem(); break;
	case 2: display(); break;
	case 3: deleteItem(); break;
	case 4: editItem(); break;

	}
}

void Menu::addItem()
{
	cout << "Co chcesz dodac?" << endl << "Aby dodac fundusz inwestycyjny wpisz 1"<<endl;
	int input;
	cin >> input;
	Assets* asset=NULL;
	bool isGood = false;
	switch (input) {
	case 1: asset = new InvestmentFund(); isGood = true; break; // wallet.addAsset(InvestmentFund());break;
	}
	if(isGood)
		wallet += asset;
	start();

}

void Menu::display() {

	auto list = wallet.getList();
	if (list.size() > 0) {
		cout << "Lista aktywow w portfelu:" << endl;
		for (size_t i = 0; i < list.size(); i++) {
			auto a = list[i];
			auto name = a->getName();
			auto id = a->getId();
			auto details = a->getDetails();
			
			printf("%d) %s %s\n", id, name.c_str(), details.c_str());
		}
	}
	else cout << "BRAK AKTYWOW W PORTFELU" << endl << endl;
	start();

}

void Menu::deleteItem()
{
	auto list = wallet.getList();
	if (list.size() > 0) {
		cout << "Ktory przedmiot chcesz usunac?" << endl;
		for (size_t i = 0; i < list.size(); i++) {
			auto name = list[i]->getName();
			auto id = list[i]->getId();
			printf("%d) %s \n", id, name.c_str());
		}
		int choose;
		cin >> choose;

		wallet.erase(choose);
	}
	else cout << "BRAK AKTYWOW W PORTFELU"<<endl<<endl;
	start();

}

void Menu::editItem()
{

}

void Menu::getValue()
{

}


