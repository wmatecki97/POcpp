#include "AdditionalFunctions.h"
#include <iostream>
#include <ctime>
#include <cstdio>

int AdditionalFunctions::id = 0;


int AdditionalFunctions::getID() {
	return 0;
}

int AdditionalFunctions::getRandom(int min, int max) {
	srand(time(NULL));
	return rand() % (max - min + 1) + min;
}