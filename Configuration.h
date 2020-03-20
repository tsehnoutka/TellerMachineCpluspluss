#pragma once
#include <unordered_map>
#include "Horse.h"
#include <map>

//  make this a singleton!
class Configuration
{
private:
	static Configuration* instance;
	std::map<int, int> initDenomination;
	vector<int> denominations;
	vector<int> reverseDenominations;
	unordered_map<int, Horse> aHorses;
	int currentWinner;

public:
	Configuration();
	~Configuration();
	static Configuration* getInstance();
	map< int, int > getInitDenominations();
	vector<int> getDenominations();
	vector<int> getReverseDenominations();

	void readFile();
	void LoadHorses();

	unordered_map<int, Horse>* getHorses();
	void printHorses();

	int getCurrentWinner();
	void setCurrentWinner(int w);
};



