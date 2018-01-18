#pragma once
#include "Assets.h"
#include<string>
class Estate : public Assets {

public:
	Estate();
	string getInfo();
	void edit();

private:
	string adress;
	int area;


};
