//
// Created by Alex Python on 11/27/17.
//
#include <algorithm>
#include <string>
#include <iostream>
#include <limits>
#include "UI.h"
#include "InventoryManager.h"

/**
 * constructor for UI
 * @param systemInventoryIn
 */
UI::UI(InventoryManager* systemInventoryIn){
    systemInventory = systemInventoryIn;
}

/**
 * Destrutor for UI
 */
UI::~UI() {
    delete systemInventory;
}

/**
 * used to get a number from the user
 * @return
 */
int UI::getNumberFromUser(){
    int userInputNumber;
    std::cin >> userInputNumber;
    while (std::cin.fail()) {
        std::cout<< "\n Error: Please Re-Enter a Number: ";
        std::cin.clear();
        std::cin.ignore(256, '\n');
        std::cin >> userInputNumber;
    }
    return userInputNumber;
}

/**
 * used to get any string separate from the commands from the user
 * @return
 */
std::string UI::getStringFromUser() {
    std::string userInputString;
    std::cin >> userInputString;
    while (std::cin.fail()) {
        std::cout<< "\n Error: Invalid Input. Please Re-Enter a String: ";
        std::cin.clear();
        std::cin >> userInputString;
    }
    return userInputString;
}

/**
 * used to get a single letter command from the user
 * @return
 */
std::string UI::getCommandFromUser() {
    std::string command;
    std::cin >> command;
    while (std::cin.fail()) {
        std::cout<< "\n Error: Invalid Input. Please Re-Enter a Command: ";
        std::cin.clear();
        std::cin >> command;
    }
    std::transform(command.begin(), command.end(), command.begin(), ::tolower);
    return command;
}

/**
 * prints out the help menu when the 'H' command is entered
 */
void UI::printHelpMenu() {

}

/**
 * will run the actual User Interface and the endless loop until you enter the Q command
 */
void UI::run() {
    std::cout<< "Inventory Manager" << std::endl << std::endl;
    std::cout<< "Enter a Command (Press 'H' for Help): ";
    std::string command = getCommandFromUser();
    while ((command != "h") && (command != "q") && (command != "i") && (command != "l") && (command != "a") && (command != "m") && (command != "s") && (command != "o") && (command != "d") && (command != "r")) {
        std::cout << "\n Invalid Command. Please Re-Enter a Command: ";
        getCommandFromUser();
    }
    while (command != "q") {

    }
}
