//
// Created by benja on 12/18/2017.
//

#include "InventoryTester.h"
//
// Created by benja on 12/13/2017.
//

#include <fstream>
#include <iostream>
#include "InventoryTester.h"
#include "InventoryManager.h"

void ::InvTester::assertFilesEqual(std::string fileA, std::string fileB) {
    std::ifstream fA (fileA);
    std::ifstream fB (fileB);
    if(!fA.is_open()){
        std::cout << "Not able to open "<<fileA << std::endl;
        return;
    }
    if(!fB.is_open()){
        std::cout << "Not able to open "<<fileB << std::endl;
        return;
    }
    std::string la,lb;
    int line_counter=0;
    while(std::getline(fA,la)&&std::getline(fB,lb)) {
        line_counter++;
        if(la!=lb){
            std::cout << "FAIL: line "<<line_counter<<" does not match (comparing "<<fileA<<" and "<<fileB<<")"<< std::endl;
            return;
        }
    }
    std::cout << "pass"<< std::endl;
}

void ::InvTester::runInvTests() {
    std::cout << "=== TESTING INVENTORY MANAGER ==="<< std::endl;
    InventoryManager* manager1=new InventoryManager("testfiles/null.json");
    manager1->listInventory();
    manager1->saveOutToFile("testfiles/s1.json");
    manager1->saveOutToFile("testfiles/s2.json");
    assertFilesEqual("testfiles/s1.json","testfiles/s2.json");
    delete manager1;

    std::cout << "Testing IO"<< std::endl;
    testIO();
    std::cout << "=== DONE TESTING INVENTORY MANAGER ==="<< std::endl;

}

void ::InvTester::testIO() {
    InventoryManager* manager1=new InventoryManager("testfiles/null.json");
    manager1->addTitle("BOOK 1",0,1);
    manager1->addTitle("BOOK 2",5,3);
    manager1->addTitle("BOOK 3",1,3);
    manager1->addToWaitlist("BOOK 1","bob","bob@bob.com","1234567890","doot");
    manager1->saveOutToFile("testfiles/comp.json");
    assertFilesEqual("testfiles/comp.json","testfiles/testsave.json");

    // make sure manager1==manager2
    InventoryManager* manager2=new InventoryManager("testfiles/testsave.json");
    delete manager1;
    delete manager2;
}
