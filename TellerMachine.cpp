// TellerMachine.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "TellerMachine.h"

Configuration* Configuration::instance = 0;

bool TellerMachine::validateInput(string s)
{
	bool retval = true;
	if (s.find(".") != string::npos)
		retval = false;
	return retval;
}

void TellerMachine::handleInput() {
	string input;
	char command;
	string value = "";
	bool done = false;
	unordered_map<int, Horse>* localHorses = config->getHorses();


	while (!done) {
		getline(cin, input);;
		if (!validateInput(input)) {
			cout << "Invalid command : " << input << endl;
			continue;
		}
		command = input[0];

		if (isdigit(command)) {
			//  if number it's a bet, so pay the user
			string str;
			str += command;
			int horseNumber = atoi(str.c_str());  //  convert command to integer
			//  if horse is not present
			if (localHorses->find(horseNumber) == localHorses->end()) {
				cout << "Invalid Horse Number : " << horseNumber << endl;
				continue;
			}
			value = input.substr(2);  // get bet
			//  check if bet is integer
			if (value.find(".") != string::npos) {
				cout << " invalid bet : " << value << "\n";
				continue;
			} //  end if find "."
			if (localHorses->at(horseNumber).Won() == "won") {
				int payme = atoi(value.c_str()) * localHorses->at(horseNumber).getOdds();
				myTill.pay(localHorses->at(horseNumber).getName(), payme);
			}
			else {
				cout << "No Payout : " << localHorses->at(horseNumber).getName() << endl;
			}

		} //end if digit
		else {
			switch (command) {
			case 'Q':  //  quit
			case 'q': {
				done = true;
				break;
			}
			case 'R': //  retock drawer
			case 'r': {
				myTill.RestockDrawer();
				break;
			}
			case 'W':  // set winning horse
			case 'w': {
				value = input.substr(2);  //  get horse number
				int horseNumber = atoi(value.c_str());
				int c = config->getCurrentWinner();
				localHorses->at(c).setWon("lost");
				localHorses->at(horseNumber).setWon("won");
				config->setCurrentWinner(horseNumber);
				break;
			}
			default: {
				cout << "Invalid command : " << input << endl;
				break;
			}
			} // end switch

		} // end if digit
		myTill.Display();
		config->printHorses();
	}   //  end while



}  //  end of handle Input

TellerMachine::TellerMachine()
{
	config = config->getInstance();
	myTill.Display();
	config->printHorses();
}




