//
// Created by Alex Python on 11/27/17.
// Interface class for controlling a bookstore inventory
//

#ifndef COMP220BOOKSTORE_UI_H
#define COMP220BOOKSTORE_UI_H

#include <string>
#include "InventoryManager.h"

class UI {
private:
    InventoryManager* systemInventory;
public:
    UI(InventoryManager* systemInventory); //constructor
    ~UI(); //destructor
    void run(); //runs the endless loop for UI
};

#endif //COMP220BOOKSTORE_UI_H
