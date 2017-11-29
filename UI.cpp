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
    std::cout << "\n Available Commands: ";
    std::cout << "\n H : Display all available commands";
    std::cout << "\n I : Inquire about a title's information";
    std::cout << "\n L : List the inventory of titles";
    std::cout << "\n A : Add a book to the inventory";
    std::cout << "\n M : Modify the want value of a title";
    std::cout << "\n S : Sell a copy of a title";
    std::cout << "\n O : Order copies of titles";
    std::cout << "\n D : Accept a delivery";
    std::cout << "\n R : Prepare a return shipment";
    std::cout << "\n Q : Quit inventory manager program \n";
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
        if (command == "h") {
            printHelpMenu();
        } else if (command == "i") {
            std::cout << "\n Please Enter a Title: ";
            std::string title = getStringFromUser();
            if (systemInventory->checkIfTitleExists(title)) {
                systemInventory->inquireTitle(title);
            } else {
                std::cout << "\n Title Does Not Exist";
            }
        } else if (command == "l") {
            systemInventory->listInventory();
        } else if (command == "a") {
            std::cout << "\n Please Enter a Title: ";
            std::string title = getStringFromUser();
            if (systemInventory->checkIfTitleExists(title)) {
                systemInventory->inquireTitleOneLine(title);
            } else {
                std::cout << "\n How many do you have: ";
                int have = getNumberFromUser();
                std::cout << "\n How many do you want: ";
                int want = getNumberFromUser();
                systemInventory->addTitle(title, have, want);
            }
        } else if (command == "m") {
            std::cout << "\n Please Enter a Title: ";
            std::string title = getStringFromUser();
            if (systemInventory->checkIfTitleExists(title)) {
                std::cout << "\n Enter a new want value for " << title << ": ";
                int want = getNumberFromUser();
                systemInventory->modifyWantValue(title, want);
            } else {
                std::cout << "\n Title Does Not Exist";
            }
        } else if (command == "s") {
            std::cout << "\n Please Enter a Title: ";
            std::string title = getStringFromUser();
            if (systemInventory->checkIfTitleExists(title)) {
                if (!systemInventory->sell(title)) {
                    std::cout << "\n Please Enter Your Name: ";
                    std::string name = getStringFromUser();
                    std::cout << "\n Please Enter Your Email: ";
                    std::string email = getStringFromUser();
                    std::cout << "\n Please Enter Your Phone Number: ";
                    int phoneNumber = getNumberFromUser();
                    while (std::to_string(phoneNumber).length() != 10) {
                        std::cout << "\n Invalid Phone Number";
                        std::cout << "\n Please Re-Enter Your Phone Number: ";
                        phoneNumber = getNumberFromUser();
                    }
                    std::cout << "\n What is Your Preferred Contact Method?";
                    std::cout << "\n Please Enter (1) for Call, (2) for Text, or (3) for Email: ";
                    int preferredMethod = getNumberFromUser();
                    while (preferredMethod != 1 && preferredMethod != 2 && preferredMethod != 3) {
                        std::cout << "\n Invalid Contact Method. Please Re-Enter Your Preferred Contact Method: ";
                        preferredMethod = getNumberFromUser();
                    }
                    std::string preferredMethodString;
                    if (preferredMethod == 1) {
                        preferredMethodString = "Call";
                    } else if (preferredMethod == 2) {
                        preferredMethodString = "Text";
                    } else if (preferredMethod == 3) {
                        preferredMethodString = "Email";
                    }
                    systemInventory->addToWaitlist(title, name, email, std::to_string(phoneNumber), preferredMethodString);
                }
            } else {
                //TODO
            }
        } else if (command == "o") {
            systemInventory->createBulkOrder("orderFile");
        } else if (command == "d") {
            systemInventory->loadDelivery("deliveryFile");
        } else if (command == "r") {
            systemInventory->createReturnInvoice("returnFile");
        }
        std::cout<< "Enter a Command (Press 'H' for Help): ";
        command = getCommandFromUser();
        while ((command != "h") && (command != "q") && (command != "i") && (command != "l") && (command != "a") && (command != "m") && (command != "s") && (command != "o") && (command != "d") && (command != "r")) {
            std::cout << "\n Invalid Command. Please Re-Enter a Command: ";
            getCommandFromUser();
        }
    }
    systemInventory->saveOutToFile("inventoryFile");
}
