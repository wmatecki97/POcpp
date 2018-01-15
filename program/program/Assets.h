#pragma once

class Assets {

public:
	Assets();
	double getValue();
	void setValue(double value);
	char getInfo();

protected:
	int id;
	string name;
	double value;
};