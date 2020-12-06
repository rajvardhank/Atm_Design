#include <iostream>
#include "header_files/Atm.h"
#include "header_files/Bankobjs.h"

std::unordered_map<std::string, Bank*> banks;

int main(){

    createbanks();
    createAccounts();
    Atm atm;
    int input = 1;

    while (input)
    {
        atm.doTransaction();
        std::cout<<"Please press 0 to exit ATM or any other key to do another transaction.\n";
        std::cin>>input;
    }

    for (auto i: banks)
    {
        delete i.second;
    }

    return 0;
}