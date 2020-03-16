#pragma once
#include <unordered_map>
#include "Horse.h"

//  make this a singleton!
class Configuration
{
private:
	static Configuration* instance;

	int ONES_INIT;
	int FIVES_INIT;
	int TENS_INIT;
	int TWENTYS_INIT;
	int HUNDREDS_INIT;

	unordered_map<int, Horse> aHorses;

	int currentWinner;

public:
	Configuration();
	~Configuration();
	static Configuration* getInstance();

	int getONES_INIT();
	int getFIVES_INIT();
	int getTENS_INIT();
	int getTWENTYS_INIT();
	int getHUNDREDS_INIT();	
	
	void setONES_INIT(int x);
	void setFIVES_INIT(int x);
	void setTENS_INIT(int x);
	void setTWENTYS_INIT(int x);
	void setHUNDREDS_INIT(int x);

	void readXML();
	void readFile();

	unordered_map<int, Horse>* getHorses();
	void printHorses();

	int getCurrentWinner();
	void setCurrentWinner(int w);
};



