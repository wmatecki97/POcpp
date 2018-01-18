#pragma once
#include "Wallet.h"
using namespace std;

class Menu {
public:
	static void start();
	static void addItem();
	static void deleteItem();
	static void editItem();
	static void simulateValue();
	static void display();
	static void init();
};