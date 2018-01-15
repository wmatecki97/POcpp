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
	switch (input) {
	case 1: wallet.addAsset(InvestmentFund());break;
	}
	start();

}

void Menu::display() {

}

void Menu::deleteItem()
{

}

void Menu::editItem()
{

}

void Menu::getValue()
{

}


