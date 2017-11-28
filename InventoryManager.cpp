//
// Created by Alex Python on 11/27/17.
//

#include <string>
#include "InventoryManager.h"

InventoryManager::InventoryManager(std::string savefile) {
    //TODO
    
}

void InventoryManager::saveOutToFile(std::string savefile) {
    //TODO
}

bool InventoryManager::checkIfTitleExists(std::string title) {
    //TODO
    return false;
}

void InventoryManager::listInventory() {
    //TODO

}

void InventoryManager::inquireTitle(std::string title) {
    //TODO

}

void InventoryManager::inquireTitleOneLine(std::string title) {
    //TODO

}

void
InventoryManager::addToWaitlist(std::string title, std::string personName, std::string email, std::string phoneNumber,
                                std::string contactPref) {
    //TODO

}

bool InventoryManager::sell(std::string title) {
    //TODO
    return false;
}

void InventoryManager::addTitle(std::string title, int have, int want) {
    //TODO

}

bool InventoryManager::modifyWantValue(std::string title, int newWant) {
    //TODO
    return false;
}

void InventoryManager::createBulkOrder(std::string filename) {
    //TODO

}

void InventoryManager::loadDelivery(std::string filename) {
    //TODO

}

void InventoryManager::createReturnInvoice(std::string filename) {
    //TODO

}
