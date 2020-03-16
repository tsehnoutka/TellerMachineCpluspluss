#pragma once
#include <string>
#include "Configuration.h"

using namespace std;

class CashDrawer
{
private:
	Configuration *config;
	int Ones;
	int Fives;
	int Tens;
	int Twentys;
	int Hundreds;
	int Total;

public:
	CashDrawer();
	void RestockDrawer();
	void Display();
	int pay(string horseName, int payout);
};

