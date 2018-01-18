#pragma once
#include "Assets.h"
#include<string>
class Estate : public Assets {

public:
	Estate();
	string getInfo();

private:
	string adress;
	int area;


};
