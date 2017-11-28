//
// Created by Alex Python on 11/15/17.
//
#include <iostream>
#include "testMain.h"
#include "bookstoreMain.h"

/**
 * used to get a number from the user
 * @return
 */
int getNumberFromUser(){
    int userInputNumber;
    std::cin >> userInputNumber;
    while (std::cin.fail()) {
        std::cout<< "\n Error: Please Enter a Number: ";
        std::cin.clear();
        std::cin.ignore(256, '\n');
        std::cin >> userInputNumber;
    }
    return userInputNumber;
}

int main() {
    //bookstoreMain();
    //runTests();
    std::cout<< getNumberFromUser();
    return 0;
}