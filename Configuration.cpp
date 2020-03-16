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


void Configuration::readXML() {
} // end read XML


void Configuration::readFile() {
	// Read Input file
	string fileName = "Input.txt";
	string line;
	ifstream myfile(fileName);
	if (myfile.is_open()){
		string inLine;
		getline(myfile, inLine); // read inventory line

		getline(myfile, inLine); // read One line
		ONES_INIT = stoi(inLine.substr(inLine.find(',') + 1));
		getline(myfile, inLine); // read Five line
		FIVES_INIT = stoi(inLine.substr(inLine.find(',') + 1));
		getline(myfile, inLine); // read Ten line
		TENS_INIT = stoi(inLine.substr(inLine.find(',') + 1));
		getline(myfile, inLine); // read Twenty line
		TWENTYS_INIT = stoi(inLine.substr(inLine.find(',') + 1));
		getline(myfile, inLine); // read Hundred line
		HUNDREDS_INIT = stoi(inLine.substr(inLine.find(',') + 1));
		/*
				cout << "ONES is intialaized to      : " << ONES_INIT << '\n';
				cout << "FIVES is intialaized to     : " << FIVES_INIT << '\n';
				cout << "TENS is intialaized to      : " << TENS_INIT << '\n';
				cout << "TWNETYS is intialaized to   : " << TWENTYS_INIT << '\n';
				cout << "HUNDREDS is intialaized to  : " << HUNDREDS_INIT << '\n';
		*/
	} //  end if file open
	else{
		cout << "Unable to open file :" << fileName << '\n';
	}  //  end if / else file open
	// Close the input stream
	myfile.close();

}// end readFile

Configuration::Configuration()
{
	// open and read files
	// populate the Configuration class

	readFile();   //  populate the INIT variables
	//readXML();  //  populate the Horses
	aHorses = {
			{1,{1, "That Darn Grey Cat", 5, "won"} },
			{2,{2, "Fort Utopis"       ,10, "lost"}},
			{3,{3, "Count Sheep"       , 9, "lost"}},
			{4,{4, "Ms Traitou"        , 4, "lost"}},
			{5,{5, "Real Princess"     , 3, "lost"}},
			{6,{6, "Pa Kettle"         , 5, "lost"}},
			{7,{7, "Gin Stinger"       , 6, "lost"}}
	};
	currentWinner = 1;
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
