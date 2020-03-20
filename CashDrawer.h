#pragma once
#include <string>
#include "Configuration.h"
#include <map>

using namespace std;

class CashDrawer
{
private:
	Configuration *config;
	std::map<int, int> myTill;

	int Total;

public:
	CashDrawer();
	void RestockDrawer();
	void Display();
	int pay(string horseName, int payout);
};

