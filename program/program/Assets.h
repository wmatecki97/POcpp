#pragma once
#include<iostream>

using namespace std;
class Assets {

public:
	Assets(char[]);
	double getValue();
	void setValue(double value);
	char getInfo();
	int getId();
	string getName();



protected:
	int id;
	string name;
	double value;
};