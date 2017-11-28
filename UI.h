//
// Created by Alex Python on 11/27/17.
//

#ifndef COMP220BOOKSTORE_UI_H
#define COMP220BOOKSTORE_UI_H

#include <string>
#include "InventoryManager.h"

class UI {
private:
    InventoryManager* systemInventory;
    int getNumberFromUser(); //handles number input and the try/catch
    std::string getCommandFromUser(); //get the single letter inputs
    std::string getStringFromUser(); //handles string input
    void printHelpMenu(); //prints out the list of commands
public:
    UI(InventoryManager* systemInventory); //constructor
    ~UI(); //destructor
    void run(); //runs the endless loop for UI
};

#endif //COMP220BOOKSTORE_UI_H
