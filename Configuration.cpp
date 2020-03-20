#include "Configuration.h"
#include <iostream>
#include <fstream>

using namespace std;

unordered_map<int, Horse>* Configuration::getHorses()
{
	return &aHorses;
}

void Configuration::printHorses() {
	int size = aHorses.size();
	cout << "Horses:\n";
	// starting at one cause the Horse numbers start at 1
	for (int i = 1; i <= size; i++) {
		Horse temp;
		temp = aHorses[i];
		temp.print();
	} // end while

}// end print horses

int Configuration::getCurrentWinner() {
	return currentWinner;
}
void Configuration::setCurrentWinner(int w) {
	currentWinner = w;
}

void Configuration::readFile() {
	// Read Input file
	string fileName = "Input.txt";
	string line;
	ifstream myfile(fileName);

	if (myfile.is_open()){	
		string inLine;
		getline(myfile, inLine); // read inventory line

		while (getline(myfile, inLine)) {
			string denom = inLine.substr(0, inLine.find(','));
			denom = denom.erase(0,1);  //  remove '$'
			initDenomination.insert(pair<int,int> (stoi(denom), stoi(inLine.substr(inLine.find(',') + 1))));
		}  // end while
	} //  end if file open
	else{
		cout << "Unable to open file :" << fileName << '\n';
	}  //  end if / else file open
	// Close the input stream
	myfile.close();
	for (map<int, int>::iterator it = initDenomination.begin(); it != initDenomination.end(); ++it) {
		denominations.push_back(it->first);
	}
	for (map<int, int>::reverse_iterator  it = initDenomination.rbegin(); it != initDenomination.rend(); ++it) {
		reverseDenominations.push_back(it->first);
	}
}// end readFile
void Configuration::LoadHorses() {
	aHorses = {
		{1,{1, "That Darn Grey Cat", 5, true }},
		{2,{2, "Fort Utopis"       ,10, false}},
		{3,{3, "Count Sheep"       , 9, false}},
		{4,{4, "Ms Traitou"        , 4, false}},
		{5,{5, "Real Princess"     , 3, false}},
		{6,{6, "Pa Kettle"         , 5, false}},
		{7,{7, "Gin Stinger"       , 6, false}}
	};
	currentWinner = 1;
}

Configuration::Configuration()
{
	// open and read files
	// populate the Configuration class
	readFile();   //  populate the INIT variables
	LoadHorses();
}

Configuration::~Configuration()
{
	if (instance)
	 delete instance;
}

Configuration* Configuration::getInstance()
{
	if (!instance)
		instance = new Configuration;
	return instance;
}
map<int, int> Configuration::getInitDenominations()
{
	return initDenomination;
}
vector<int> Configuration::getDenominations()
{
	return denominations;
}
vector<int> Configuration::getReverseDenominations()
{
	return reverseDenominations;
}
/*
int Configuration::getONES_INIT() { return ONES_INIT; }
int Configuration::getFIVES_INIT() { return FIVES_INIT; }
int Configuration::getTENS_INIT() { return TENS_INIT; }
int Configuration::getTWENTYS_INIT() { return TWENTYS_INIT; }
int Configuration::getHUNDREDS_INIT() { return HUNDREDS_INIT; }

void Configuration::setONES_INIT(int x ) { ONES_INIT = x; }
void Configuration::setFIVES_INIT(int x) { FIVES_INIT = x; }
void Configuration::setTENS_INIT(int x) { TENS_INIT = x; }
void Configuration::setTWENTYS_INIT(int x) { TWENTYS_INIT = x; }
void Configuration::setHUNDREDS_INIT(int x) {HUNDREDS_INIT = x; }
*/