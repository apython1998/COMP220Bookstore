//
// Created by Alex Python on 11/27/17.
//
#include <algorithm>
#include <string>
#include <iostream>
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
 * used to get a positive number from the user
 * @return
 */
int getNumberFromUser(){
    std::cin.clear();
    int userInputNumber;
    std::cin >> userInputNumber;
    while (std::cin.fail()) {
        std::cout<< "\nError: Please Re-Enter a Number: ";
        std::cin.clear();
        std::cin.ignore(256, '\n');
        std::cin >> userInputNumber;
    }
    while (userInputNumber < 0) {
        std::cout<< "\nError: Please Re-Enter a Number: ";
        std::cin >> userInputNumber;
        while (std::cin.fail()) {
            std::cout<< "\nError: Please Re-Enter a Number: ";
            std::cin.clear();
            std::cin.ignore(256, '\n');
            std::cin >> userInputNumber;
        }
    }
    return userInputNumber;
}

std::string getPhoneNumberFromUser() {
    std::cin.clear();
    bool isValid = false;
    std::string phoneNumber;
    std::getline(std::cin, phoneNumber);
    while (!isValid) {
        while (std::cin.fail()) {
            std::cout << "\nError: Invalid Input. Please Re-Enter Your Phone Number: ";
            std::cin.clear();
            std::getline(std::cin, phoneNumber);
        }
        if (phoneNumber.length() == 10) {
            for (int i=0; i<=9; i++) {
                if (!isdigit(phoneNumber[i])) {
                    std::cout<< "\nError: Input Should Only be Numbers.";
                    isValid = false;
                    break;
                } else {
                    isValid = true;
                }
            }
        } else {
            std::cout << "\nError: Invalid Input. Please Re-Enter Your Phone Number: ";
        }
        if (!isValid) {
            phoneNumber = "";
            std::cin.clear();
            std::getline(std::cin, phoneNumber);
        }
    }
    phoneNumber.insert(0, "(");
    phoneNumber.insert(4, ")");
    phoneNumber.insert(8, "-");
    return phoneNumber;
}

/**
 * used to get any string separate from the commands from the user
 * @return
 */
std::string getStringFromUser() {
    std::cin.clear();
    std::string userInputString;
    std::getline(std::cin, userInputString);
    while (std::cin.fail()) {
        std::cout<< "\nError: Invalid Input. Please Re-Enter a String: ";
        std::cin.clear();
        std::cin.ignore(256, '\n');
        std::getline(std::cin, userInputString);
    }
    return userInputString;
}

/**
 * used to get a single letter command from the user
 * @return
 */
std::string getCommandFromUser() {
    std::cin.clear();
    std::string command;
    std::getline(std::cin, command);
    while (std::cin.fail()) {
        std::cout<< "\nError: Invalid Input. Please Re-Enter a Command: ";
        std::cin.clear();
        std::cin.ignore(256, '\n');
        std::getline(std::cin, command);
    }
    std::transform(command.begin(), command.end(), command.begin(), ::tolower);
    return command;
}

/**
 * prints out the help menu when the 'H' command is entered
 */
void printHelpMenu() {
    std::cout << "\nAvailable Commands: ";
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
    std::cout<< "Inventory Manager" << std::endl;
    std::cout<< "\nEnter a Command (Press 'H' for Help): ";
    std::string command = ::getCommandFromUser();
    while ((command != "h") && (command != "q") && (command != "i") && (command != "l") && (command != "a") && (command != "m") && (command != "s") && (command != "o") && (command != "d") && (command != "r")) {
        std::cout << "\nInvalid Command. Please Re-Enter a Command: ";
        command = ::getCommandFromUser();
    }
    while (command != "q") { //endless loop until you enter the quit command
        if (command == "h") { //help functionality
            ::printHelpMenu();
        } else if (command == "i") { //inquiry functionality
            std::cout << "\nPlease Enter a Title: ";
            std::string title = ::getStringFromUser();
            if (systemInventory->checkIfTitleExists(title)) {
                systemInventory->inquireTitle(title);
            } else {
                std::cout << "\nTitle Does Not Exist";
            }
        } else if (command == "l") { //list the inventory
            systemInventory->listInventory();
        } else if (command == "a") { //adds a title
            std::cout << "\nPlease Enter a Title: ";
            std::string title = ::getStringFromUser();
            if (systemInventory->checkIfTitleExists(title)) {
                std::cout << "Title already exists:"<< std::endl;
                systemInventory->inquireTitleOneLine(title);
            } else {
                std::cout << "\nHow many do you have: ";
                int have = ::getNumberFromUser();
                std::cout << "\nHow many do you want: ";
                int want = ::getNumberFromUser();
                systemInventory->addTitle(title, have, want);
            }
        } else if (command == "m") { //modifies a title
            std::cout << "\nPlease Enter a Title: ";
            std::string title = ::getStringFromUser();
            if (systemInventory->checkIfTitleExists(title)) {
                std::cout << "\nEnter a new want value for " << title << ": ";
                int want = ::getNumberFromUser();
                systemInventory->modifyWantValue(title, want);
            } else {
                std::cout << "\nTitle Does Not Exist";
            }
        } else if (command == "s") { //sells a title
            std::cout << "\nPlease Enter a Title: ";
            std::string title = ::getStringFromUser();
            if (systemInventory->checkIfTitleExists(title)) {
                bool didSell = systemInventory->sell(title);
                if (didSell == false) {
                    std::cout << "\nBook is out of stock.";
                    std::cout << "\nPlease Enter Your Name: ";
                    std::string name = ::getStringFromUser();
                    std::cout << "\nPlease Enter Your Email: ";
                    std::string email = ::getStringFromUser();
                    std::cout << "\nPlease Enter Your Phone Number: ";
                    std::string phoneNumber = ::getPhoneNumberFromUser();
                    std::cout << "\nWhat is Your Preferred Contact Method?";
                    std::cout << "\nPlease Enter (1) for Call, (2) for Text, or (3) for Email: ";
                    int preferredMethod = ::getNumberFromUser();
                    while (preferredMethod != 1 && preferredMethod != 2 && preferredMethod != 3) {
                        std::cout << "\nInvalid Contact Method. Please Re-Enter Your Preferred Contact Method: ";
                        preferredMethod = ::getNumberFromUser();
                    }
                    std::string preferredMethodString;
                    if (preferredMethod == 1) {
                        preferredMethodString = "Call";
                    } else if (preferredMethod == 2) {
                        preferredMethodString = "Text";
                    } else if (preferredMethod == 3) {
                        preferredMethodString = "Email";
                    }
                    systemInventory->addToWaitlist(title, name, email, phoneNumber, preferredMethodString);
                }
            } else {
                systemInventory->addTitle(title, 0, 1);
                std::cout << "\nPlease Enter Your Name: ";
                std::string name = ::getStringFromUser();
                std::cout << "\nPlease Enter Your Email: ";
                std::string email = ::getStringFromUser();
                std::cout << "\nPlease Enter Your Phone Number: ";
                std::string phoneNumber = ::getPhoneNumberFromUser();
                std::cout << "\nWhat is Your Preferred Contact Method?";
                std::cout << "\nPlease Enter (1) for Call, (2) for Text, or (3) for Email: ";
                int preferredMethod = ::getNumberFromUser();
                while (preferredMethod != 1 && preferredMethod != 2 && preferredMethod != 3) {
                    std::cout << "\nInvalid Contact Method. Please Re-Enter Your Preferred Contact Method: ";
                    preferredMethod = ::getNumberFromUser();
                }
                std::string preferredMethodString;
                if (preferredMethod == 1) {
                    preferredMethodString = "Call";
                } else if (preferredMethod == 2) {
                    preferredMethodString = "Text";
                } else if (preferredMethod == 3) {
                    preferredMethodString = "Email";
                }
                systemInventory->addToWaitlist(title, name, email, phoneNumber, preferredMethodString);
            }
        } else if (command == "o") { //calls the create Order function
            systemInventory->createBulkOrder("orderFile");
        } else if (command == "d") { //calls the load delivery function
            systemInventory->loadDelivery("deliveryFile");
        } else if (command == "r") { //calls the create return function
            systemInventory->createReturnInvoice("returnFile");
        }
        std::cout<< "\nEnter a Command (Press 'H' for Help): ";
        command = ::getCommandFromUser();
        while ((command != "h") && (command != "q") && (command != "i") && (command != "l") && (command != "a") && (command != "m") && (command != "s") && (command != "o") && (command != "d") && (command != "r")) {
            std::cout << "\nInvalid Command. Please Re-Enter a Command: ";
            command = ::getCommandFromUser();
        }
    }
    systemInventory->saveOutToFile("inventoryFile");
}
