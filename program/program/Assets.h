#pragma once
#include<iostream>
#include<math.h>

using namespace std;
class Assets {

public:
	Assets(char[]);
	double getValue();
	void setValue(double value);
	int getId();
	string getName();
	virtual string getDetails();
	double getRate();
	virtual string simulateFutureValue(int days);
	virtual void edit();
	virtual string getInfo();
	void displayEditMessage();
	bool controlEditAction(int choose);


protected:
	int id;
	string name;
	double value;
	double dailyRate;
};