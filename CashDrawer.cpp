#include "CashDrawer.h"
#include "Configuration.h"

CashDrawer::CashDrawer() {
	config = config->getInstance();
	RestockDrawer();
} // end constructor

void CashDrawer::RestockDrawer() {
	vector<int> denoms = config->getDenominations();
	map<int, int> initDenom = config->getInitDenominations();
	Total = 0;
	for (vector<int>::iterator it = denoms.begin(); it != denoms.end(); ++it) {
		int denom = *it;
		int qty = initDenom.at(denom);
		myTill[denom] = qty;
		Total += denom * qty;
	}
} // end of re-stock drawer

void CashDrawer::Display() {
	vector<int> denoms = config->getDenominations();

	cout << "Invetory:\n";
	for (vector<int>::iterator it = denoms.begin(); it != denoms.end(); ++it) {
		int denom = *it;
		int qty = myTill.at(denom);
		cout << "$" << denom << "," << qty << "\n";
	} //  end for
}

int CashDrawer::pay(string horseName, int payout) {
	std::map<int, int> toPayOut;

	int tempTotal = payout;

	// if there isn't enough in the till, return error
	if (Total < payout) {
		cout << "Insuficient Funds (Total) : " << payout << endl;
		return 0;
	}

	vector<int> revDenom = config->getReverseDenominations();
	for (vector<int>::iterator it = revDenom.begin(); it != revDenom.end(); ++it) {
		int denom = *it;
		int qty = myTill.at(denom);
		int cashOut = 0;
		while ((tempTotal >= denom) && (qty > 0)) {
			cashOut++;
			qty--;
			tempTotal -= denom;
		}
		toPayOut.insert(pair<int, int>(denom, cashOut));
	}

	if (0 == tempTotal) {
		//  We can pay it out
		Total -= payout;

		cout << "Payout : " << horseName << "," << payout << endl;
		cout << "Dispensing" << endl;
		vector<int> denoms = config->getDenominations();
		for (vector<int>::iterator it = denoms.begin(); it != denoms.end(); ++it) {
			int denom = *it;
			int qty = toPayOut.at(denom);
			int diff = myTill.at(denom) - qty;
			cout << "$" << denom << "," << qty << "\n";
			myTill[denom] = diff;
		} //  end for
	}
	else {
		//  We CAN'T pay it out cause we don't have the right quantity of bills
		cout << "Insufficient Funds (Denominations) : " << payout << endl;
	}
	return 1;
}// end pay
