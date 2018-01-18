#pragma once
#include<iostream>

using namespace std;
class Assets {

public:
	Assets(char[]);
	double getValue();
	void setValue(double value);
	int getId();
	string getName();
	virtual string getDetails();


protected:
	int id;
	string name;
	double value;
	double dailyRate;
};