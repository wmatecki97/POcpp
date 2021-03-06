#include "AdditionalFunctions.h"
#include <iostream>
#include <ctime>
#include <cstdio>

static int id;
static clock_t begin;
static int getTimePeriods();
static int uniqueInteger;

void AdditionalFunctions::initialize() {
	id = 0;
	begin = clock();
	uniqueInteger = 0;
}


int AdditionalFunctions::getID() {
	id++;
	return id;
}

int AdditionalFunctions::getRandom(int min, int max) {
	srand(time(NULL));
	return rand() % (max - min + 1) + min;
}

int AdditionalFunctions::getTimePeriods() {
	int periods = (int)double(clock() - begin) / CLOCKS_PER_SEC / 5;
	return periods;
}

int AdditionalFunctions::getUniqueInteger() {
	uniqueInteger++;
	return uniqueInteger;
}