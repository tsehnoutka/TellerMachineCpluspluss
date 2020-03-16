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
    bool validateInput(string s);
    void handleInput();
}; //  end of class
