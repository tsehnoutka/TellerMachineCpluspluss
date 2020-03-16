#include "Horse.h"

Horse::Horse() {
}

Horse::Horse(int n, string sName, int o, string w) {
	number = n;
	name.assign(sName);
	odds = o;
	if (!w.compare("won") || !w.compare("lost"))
		won.assign(w);
}

void Horse::print() {
	std::cout << number << "," << name << "," << odds << "," << won << '\n';
} // end print

int Horse::getNumber() {
	return number;
}

string Horse::getName() {
	return name;
}

int Horse::getOdds() {
	return odds;
}

string Horse::Won() {
	return won;
}

void Horse::setWon(string b) {
	won.assign(b);
}
