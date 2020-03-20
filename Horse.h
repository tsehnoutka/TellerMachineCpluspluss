#pragma once
#include <iostream>
#include <string>
using namespace std;

class Horse
{
private:
	int number;
	string name;
	int odds;
	bool won;

public:
	Horse();
	Horse(int n, string sName, int o, bool w);
	void print();
	int getNumber();
	string getName();
	int getOdds();
	bool Won();
	void setWon(bool b);

};// end of Horse class


