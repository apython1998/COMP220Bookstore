//
// Created by Alex Python on 11/27/17.
//

#include <string>
#include <iostream>
#include <fstream>
#include "InventoryManager.h"
#include "ArrayTitleList.h"

InventoryManager::InventoryManager(std::string savefile) {
    // init titleList
    titleList=new ArrayTitleList();

    std::cout << "Loading from "<<savefile<< std::endl;
    // open file and make sure it opened
    std::ifstream infile (savefile);
    if (!infile.is_open()){
        std::cout << "ERROR: cannot open file "<< savefile<<" for reading"<< std::endl;
    }else {
        nlohmann::json loaded;
        infile >> loaded;
        infile.close();
        for (auto &it : loaded) {
            try{
                titleList->add(Title(it));
            }catch (std::domain_error& e){
                std::cout << "BAD DATA:"<<it<< std::endl;
            }
        }
        //TODO
    }
}

void InventoryManager::saveOutToFile(std::string savefile) {
    std::cout << "Saving to "<<savefile<< std::endl;
    // open file and make sure it opened
    std::ofstream outfile (savefile);
    if (!outfile.is_open()){
        std::cout << "ERROR: cannot open file "<<savefile<<" for writing"<< std::endl;
        return;
    }

    ArrayList<Title>* titles=titleList->getSortedList();
    nlohmann::json books=nlohmann::json();

    for(int i=0;i<titles->itemCount();i++) {
        books.push_back(titles->getPointerAt(i)->toJSON());
    }

    outfile <<std::setw(2)<< books; //setw is overrided to set indent
    outfile.close();
    //TODO
}

bool InventoryManager::checkIfTitleExists(const std::string& title) {
    return titleList->find(title)!=nullptr;
    //TODO
}

void InventoryManager::listInventory() {
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
}
void printTitle(Title *t) {
    std::cout << "-----------------\nTitle: "<<t->name<<"\n-----------------\n\thave: "<<t->have<<"\n\twant: "<<t->want<< std::endl;
    if(t->waitlistHasNext())t->printWaitlist();
    else std::cout << "\tno waitlist"<< std::endl;
}

void InventoryManager::inquireTitle(std::string title){
    ::printTitle(titleList->find(title));
}

void printTitleOneLine(Title* t){
    std::cout << "Title: "<<t->name<<"\thave: "<<t->have
              <<"\twant: "<<t->want<<"\twaitlist?: "<<(t->waitlistHasNext()?"yes":"no")<< std::endl;
}

void InventoryManager::inquireTitleOneLine(std::string title) {
    printTitleOneLine(titleList->find(title));
    //TODO
}

void
InventoryManager::addToWaitlist(std::string title, std::string personName, std::string email, std::string phoneNumber,
                                std::string contactPref) {
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
    std::cout << "Added";
    titleList->add(Title(title,have,want));
    inquireTitleOneLine(title);
    //TODO
}

void InventoryManager::modifyWantValue(std::string title, int newWant) {
    titleList->find(title)->want=newWant;
}

void InventoryManager::createBulkOrder(std::string filename) {
    std::cout << "Will save to "<<filename<< std::endl;
    std::ofstream outfile (filename);
    if (!outfile.is_open()){
        std::cout << "ERROR: cannot open file "<<filename<<" for writing"<< std::endl;
        return;
    }

    ArrayList<Title>* titles=titleList->getSortedList();
    Title* t;
    nlohmann::json books=nlohmann::json();//=new nlohmann::json[ct];
    for(int i=0;i<titles->itemCount();i++) {
        t=titles->getPointerAt(i);
        if(t->want>t->have){
            std::cout << "Get "<<t->want-t->have<<" "<<t->name<< std::endl;
           books.push_back(t->toJSON());
        }
    }
    outfile <<std::setw(2)<< books; //setw is overrided to set indent
    outfile.close();
}

void InventoryManager::loadDelivery(std::string filename) {
    std::cout << "Will load from "<<filename<< std::endl;
    //TODO
    std::ifstream infile (filename);
    if (!infile.is_open()){
        std::cout << "ERROR: cannot open file "<<filename<<" for reading"<< std::endl;
        return;
    }
    nlohmann::json loaded;
    infile>>loaded;
    infile.close();
    for (auto &it : loaded) {
        try{
            Title tmp=Title(it);
            std::cout << "Loaded"<< std::endl;
            printTitleOneLine(&tmp);
        }catch (std::domain_error& e){
            std::cout << "BAD DATA:"<< it << std::endl;
        }
    }
}

void InventoryManager::createReturnInvoice(std::string filename) {
    std::cout << "Will save to " << filename << std::endl;
    std::ofstream outfile(filename);
    if (!outfile.is_open()) {
        std::cout << "ERROR: cannot open file " << filename << " for writing" << std::endl;
        return;
    }

    ArrayList<Title> *titles = titleList->getSortedList();
    Title *t;
    nlohmann::json books = nlohmann::json();
    for (int i = 0; i < titles->itemCount(); i++) {
        t = titles->getPointerAt(i);
        if (t->want < t->have) {
            std::cout << "Return " << t->have - t->want << " " << t->name << std::endl;
            books.push_back(t->toJSON());
        }
    }
    outfile << std::setw(2) << books; //setw is overrided to set indent
    outfile.close();
}


InventoryManager::~InventoryManager() {
    delete titleList;
}
