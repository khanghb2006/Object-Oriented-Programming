#include <iostream>

// incldude header files
#include "Account.h"  
#include "SavingAccount.h"

int main() {
    try {
        SavingAccount person1(1000 , 6 , 5);
        person1.IncreaseDuration();
        person1.Deposit(500);
        std::cout << "Balance of person1: " << person1.getBalance() << "\n";
    }
    catch (const std::invalid_argument &e) {
        std::cout << e.what() << "\n";
    }
}