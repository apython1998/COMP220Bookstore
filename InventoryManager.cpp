//
// Created by Alex Python on 11/27/17.
//

#include <string>
#include <iostream>
#include "InventoryManager.h"

InventoryManager::InventoryManager(std::string savefile) {
    std::cout << "Pretending to load from "<<savefile<< std::endl;

    //TODO
}

void InventoryManager::saveOutToFile(std::string savefile) {
    std::cout << "Pretending to save to "<<savefile<< std::endl;
    //TODO
}

bool InventoryManager::checkIfTitleExists(std::string title) {
    std::cout << "Do "<<title<<" exist? I have no idea. I'll just say no." << std::endl;
    //TODO
    return false;
}

void InventoryManager::listInventory() {
    std::cout << "Check out this list:\n1) cube\n2) sphere\n3) torus\n4) the dreaded cone"<< std::endl;
    //TODO

}

void InventoryManager::inquireTitle(std::string title) {
    std::cout << "Title: "<<title<<"\nhave: work\nwant: time"<< std::endl;
    //TODO

}

void InventoryManager::inquireTitleOneLine(std::string title) {
    std::cout << "Title: "<<title<<"\thave: work\twant: time"<< std::endl;
    //TODO
}

void
InventoryManager::addToWaitlist(std::string title, std::string personName, std::string email, std::string phoneNumber,
                                std::string contactPref) {
    std::cout << "you want the book, yes? too bad, we don't have it. come back later."<< std::endl;
    //TODO

}

bool InventoryManager::sell(std::string title) {
    std::cout << "here, sell book"<< std::endl;
    //TODO
    return false;
}

void InventoryManager::addTitle(std::string title, int have, int want) {
    std::cout << "adding the books wowowowo" << std::endl;
    //TODO
}

bool InventoryManager::modifyWantValue(std::string title, int newWant) {
    std::cout << "want "<<newWant<< std::endl;
    //TODO
    return false;
}

void InventoryManager::createBulkOrder(std::string filename) {
    std::cout << "Pretending to save to "<<filename<< std::endl;
    //TODO

}

void InventoryManager::loadDelivery(std::string filename) {
    std::cout << "Pretending to load from "<<filename<< std::endl;
    //TODO

}

void InventoryManager::createReturnInvoice(std::string filename) {
    std::cout << "Pretending to save to "<<filename<< std::endl;
    auto list=titleList->getSortedList();
    for(int i=0;i<list->itemCount();i++){

    }
    //TODO

}
