//
// Created by Alex Python on 11/27/17.
//

#include <string>
#include <iostream>
#include "InventoryManager.h"
#include "ArrayTitleList.h"

InventoryManager::InventoryManager(std::string savefile) {
    std::cout << "Pretending to load from "<<savefile<< std::endl;
    titleList=new ArrayTitleList();
    titleList->add(Title("Book a",1,2));
    titleList->add(Title("Book b",3,2));
    titleList->add(Title("Book c",0,4));
    //TODO
}

void InventoryManager::saveOutToFile(std::string savefile) {
    std::cout << "Pretending to save to "<<savefile<< std::endl;
    //TODO
}

bool InventoryManager::checkIfTitleExists(const std::string& title) {
    //std::cout << "Do "<<title<<" exist? I have no idea. I'll just say no." << std::endl;
    return titleList->find(title)!=nullptr;
    //TODO
}

void InventoryManager::listInventory() {
    //std::cout << "Check out this list:\n1) Book 1\n2) Book 2\n3) Book 3\n4) Book 4"<< std::endl;
    ArrayList<Title>* titles=titleList->getSortedList();
    std::cout << "-------------------------------------------------------------"<<std::endl;
    std::cout.width(40);
    std::cout << std::left<<"Name";
    std::cout.width(6);
    std::cout << std::left << "Have";
    std::cout.width(6);
    std::cout << std::left << "Want";
    std::cout.width(6);
    std::cout << std::left << "Waitlist?" << std::endl;
    std::cout << "-------------------------------------------------------------"<<std::endl;
    for(int i=0;i<titles->itemCount();i++){
        Title* t=titles->getPointerAt(i);
        std::cout.width(40);
        std::cout << std::left<<t->name;
        std::cout.width(6);
        std::cout << std::left << t->have;
        std::cout.width(6);
        std::cout << std::left << t->want;
        std::cout.width(6);
        std::cout << std::left << (t->waitlistHasNext()?"yes":"no") << std::endl;
    }
    //TODO

}

void InventoryManager::inquireTitle(std::string title) {
    Title* t = titleList->find(title);
    std::cout << "-----------------\nTitle: "<<t->name<<"\n-----------------\n\thave: "<<t->have<<"\n\twant: "<<t->want<< std::endl;
    if(t->waitlistHasNext())t->printWaitlist();
    else std::cout << "\tno waitlist"<< std::endl;
}

void InventoryManager::inquireTitleOneLine(std::string title) {
    Title* t = titleList->find(title);
    std::cout << "Title: "<<t->name<<"\thave: "<<t->have<<"\twant: "<<t->want<< std::endl;
    //TODO
}

void
InventoryManager::addToWaitlist(std::string title, std::string personName, std::string email, std::string phoneNumber,
                                std::string contactPref) {
    //std::cout << "you want the book, yes? too bad, we don't have it. come back later."<< std::endl;
    Title* t = titleList->find(title);
    t->addToWaitlist(Person(personName,phoneNumber,email,contactPref));
    //TODO
}

bool InventoryManager::sell(std::string title) {
    std::cout << "selling book: " << title << std::endl;
    if(titleList->find(title)->have<1)return false;
    titleList->find(title)->have--;
    return true;
    //TODO
}

void InventoryManager::addTitle(std::string title, int have, int want) {
    //std::cout << "adding the book: " << title <<  std::endl;
    titleList->add(Title(title,have,want));
    //TODO
}

void InventoryManager::modifyWantValue(std::string title, int newWant) {
    titleList->find(title)->want=newWant;
}

void InventoryManager::createBulkOrder(std::string filename) {
    std::cout << "Will save to "<<filename<< std::endl;
    //TODO
    ArrayList<Title>* titles=titleList->getSortedList();
    Title* t;
    for(int i=0;i<titles->itemCount();i++) {
        t=titles->getPointerAt(i);
        if(t->want>t->have){
            // get more of the book
            std::cout << "Get "<<t->want-t->have<<" "<<t->name<< std::endl;
        }
    }
}

void InventoryManager::loadDelivery(std::string filename) {
    std::cout << "Will load from "<<filename<< std::endl;
    //TODO

}

void InventoryManager::createReturnInvoice(std::string filename) {
    std::cout << "Pretending to save to "<<filename<< std::endl;
    ArrayList<Title>* titles=titleList->getSortedList();
    Title* t;
    for(int i=0;i<titles->itemCount();i++) {
        t=titles->getPointerAt(i);
        if(t->want<t->have){
            // get more of the book
            std::cout << "Return "<<t->have-t->want<<" "<<t->name<< std::endl;
        }
    }
    //TODO

}
