// TellerMachine.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "TellerMachine.h"
#include "Utilities.h"

Configuration* Configuration::instance = 0;

bool TellerMachine::containPeriod(string s)
{
	bool retval = true;
	if (s.find(".") != string::npos)
		retval = false;
	return retval;
}

bool TellerMachine::ValidateInput(string input) {
	int spacePos = input.find(' ');
	if (spacePos != string::npos) { //if there IS a space
		string first = input.substr(0, input.find(' '));
		string second = input.substr(input.find(' ') + 1);
		if (toupper(input[0]) == 'W' || is_number(first)) {
			if (!is_number(second))
				return false;
			else
				return true;
		}
		else
			return false;
	}
	else {
		if (toupper(input[0]) == 'Q' || toupper(input[0]) == 'R')
			return true;
		else
			return false;
	}	
}

void TellerMachine::handleInput() {
	string input;
	string command;
	string value = "";
	bool done = false;
	unordered_map<int, Horse>* localHorses = config->getHorses();

	while (!done) {
		getline(cin, input);
		input = trim(input);

		if (!ValidateInput(input)) {
			cout << "Invalid command : " << input << endl;
			continue;
		}
		command = input.substr(0, input.find(' '));
		if (is_number(command)) {  //  its a bet!!
			int bet = stoi(input.substr(input.find(' ') + 1));
			if(!containPeriod(input)) {
				cout << "Invalid Bet ( must be integer) : " << bet << endl;
				continue;
			}
			//  if number it's a bet, so pay the user
			int horseNumber = stoi(command);

			//  if horse is not present
			if (localHorses->find(horseNumber) == localHorses->end()) {
				cout << "Invalid Horse Number : " << horseNumber << endl;
				continue;
			}
			if (horseNumber == config->getCurrentWinner()) {
				int payme = bet * localHorses->at(horseNumber).getOdds();
				myTill.pay(localHorses->at(horseNumber).getName(), payme);
			}
			else {
				cout << "No Payout : " << localHorses->at(horseNumber).getName() << endl;
			}
		} //end if digit
		else {
			switch (toupper(input[0])) {
			case 'Q':{
				done = true;
				break;
			}
			case 'R': {
				myTill.RestockDrawer();
				break;
			}
			case 'W':{
				int horseNumber = stoi(input.substr(input.find(' ') + 1));
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
/*
 * TEST CASES:
 * 1 55 - payout 275
 * 2 25  - no payout
 * w 4 - set winning horse to 4
 * w 4 - winning horse is still 4
 * 4 10.25 - no payout invlaid bet
 * r - resets till
 * w 2 - sets winning horse to 2
 * 2 100 - payout
 * 2 30 - payout
 * 2 10 - no payout not enough money
 * r - reset till
 * w 4 - set winning horse to 4
 * 4 1 - payout
 * 4 1 - payout
 * 4 1 no payout not enough denomination
 * 10.25 - Invalid command
 * 1 - Invalid command  
 * 10 55 - invalid horse  
 * add a space before a command - it should work as expected  
 * 5 - invalid command
 * just a carriage return - invalid command
 */