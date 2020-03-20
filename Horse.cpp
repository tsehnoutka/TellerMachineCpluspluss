#include "Horse.h"

Horse::Horse() {
}

Horse::Horse(int n, string sName, int o, bool w) {
	number = n;
	name.assign(sName);
	odds = o;
	won = w;
}

void Horse::print() {
	string strWon = won ? "won" : "lost";
	std::cout << number << "," << name << "," << odds << "," << strWon << '\n';
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

bool Horse::Won() {
	return won;
}

void Horse::setWon(bool b) {
	won = b;
}
