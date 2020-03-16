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
	string won;

public:
	Horse();
	Horse(int n, string sName, int o, string w);
	void print();
	int getNumber();
	string getName();
	int getOdds();
	string Won();
	void setWon(string b);

};// end of Horse class


