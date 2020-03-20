#pragma once

#include "Configuration.h"
#include "CashDrawer.h"

using namespace std;

class TellerMachine {
private:
    Configuration* config;
    CashDrawer myTill;

public:
    TellerMachine(); 
    bool containPeriod(string s);
    bool ValidateInput(string input);
    void handleInput();
}; //  end of class
