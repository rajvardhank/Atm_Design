#include "SavingsAccount.h"

SavingsAccount::SavingsAccount(std::string name, std::string number, int amount,int fee) 
                : Account(name,number,amount), atmTransacftionFee(fee) {
                card = new Card(accountNumber,bankName, savings);
}

bool SavingsAccount::withdrawMoney(int amount){
    if (card->isCardValid())
        if (accountStatus == accActive)
            if (amount <= atmWithdrawLimit)
            {
                if (amount+atmTransacftionFee<=accountBalance)
                {
                    accountBalance -= amount+atmTransacftionFee;
                    Screen::savingsTransactionFee(atmTransacftionFee);
                    return true;
                }
                else Screen::errorLessBalance();
            }
            else Screen::amtMoreThanLimit(atmWithdrawLimit);
        else Screen::accStatus(accountStatus);
    return false;
}