//
// Created by Alex Python on 11/15/17.
//
#include <iostream>
#include "UI.h"
#include "InventoryManager.h"

void bookstoreMain() {
    InventoryManager* systemInventoryManager = new InventoryManager("savefile.json");
    UI* systemUI = new UI(systemInventoryManager);
    systemUI->run();
    delete systemUI;
}

