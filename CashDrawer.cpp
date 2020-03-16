#include "CashDrawer.h"
#include "Configuration.h"

CashDrawer::CashDrawer() {
	config = config->getInstance();
	RestockDrawer();
} // end constructor

void CashDrawer::RestockDrawer() {
	Ones = config->getONES_INIT();
	Fives = config->getFIVES_INIT();
	Tens = config->getTENS_INIT();
	Twentys = config->getTWENTYS_INIT();
	Hundreds = config->getHUNDREDS_INIT();
	Total = 1 * Ones + 5 * Fives + 10 * Tens + 20 * Twentys + 100 * Hundreds;
} // end of re-stock drawer

void CashDrawer::Display() {
	cout << "Invetory:\n";
	cout << "$1," << Ones << "\n";
	cout << "$5," << Fives << "\n";
	cout << "$10," << Tens << "\n";
	cout << "$20," << Twentys << "\n";
	cout << "$100," << Hundreds << "\n";
}

int CashDrawer::pay(string horseName, int payout) {
	int oneOut = 0, fiveOut = 0, tenOut = 0, twentyOut = 0, hundredOut = 0;
	int cOnes = Ones;
	int cFives = Fives;
	int cTens = Tens;
	int cTwentys = Twentys;
	int cHundres = Hundreds;
	int tempTotal = payout;

	// if there isn't enough in the till, return error
	if (Total < payout) {
		cout << "Insuficient Funds : " << payout << endl;
		return 0;
	}

	while ((tempTotal >= 100) && (cHundres > 0)) {
		hundredOut++;
		cHundres--;
		tempTotal -= 100;
	}
	while ((tempTotal >= 20) && (cTwentys > 0)) {
		twentyOut++;
		cTwentys--;
		tempTotal -= 20;
	}
	while ((tempTotal >= 10) && (cTens > 0)) {
		tenOut++;
		cTens--;
		tempTotal -= 10;
	}
	while ((tempTotal >= 5) && (cFives > 0)) {
		fiveOut++;
		cFives--;
		tempTotal -= 5;
	}
	while ((tempTotal >= 1) && (cOnes > 0)) {
		oneOut++;
		cOnes--;
		tempTotal -= 1;
	}


	if (0 == tempTotal) {
		//  We can pay it out
		Total -= payout;

		cout << "Payout : " << horseName << "," << payout << endl;
		cout << "Dispensing" << endl;
		cout << "$1," << oneOut << endl;
		cout << "$5," << fiveOut << endl;
		cout << "$10," << tenOut << endl;
		cout << "$20," << twentyOut << endl;
		cout << "$100," << hundredOut << endl;

		Hundreds -= hundredOut;
		Twentys -= twentyOut;
		Tens -= tenOut;
		Fives -= fiveOut;
		Ones -= oneOut;
	}
	else {
		//  We CAN'T pay it out cause we don't have the right quantity of bills
		cout << "Insufficient Funds : " << payout << endl;
	}
	return 1;
}// end pay
