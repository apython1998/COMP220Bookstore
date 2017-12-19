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

bool assertEquals(int expected, int got){
    if(expected==got)std::cout << "pass"<< std::endl;
    else std::cout << "FAIL: expected "<< expected << " got "<<got<< std::endl;
    return expected==got;
}

bool assertEquals(bool expected, bool got){
    if(expected==got)std::cout << "pass"<< std::endl;
    else std::cout << "FAIL: expected "<< expected << " got "<<got<< std::endl;
    return expected==got;
}

bool assertEquals(Person a,Person b){
    if(a.name==b.name&&a.email==b.email&&a.phoneNumber==b.phoneNumber&&a.contactPreference==b.contactPreference){
        std::cout << "pass"<< std::endl;
        return true;
    }
    else
        std::cout << "people are not equivalent"<< std::endl;
    return false;

}

bool assertEquals(Title a, Title b){
    bool pass=true;
    if(a.name!=b.name)pass= false;
    if(a.have!=b.have)pass= false;
    if(a.want!=b.want)pass= false;
    if(::assertEquals(a.waitlistCount(),b.waitlistCount())&&a.waitlistCount()>0){
        //waitlists are good
        Queue<Person>::QueueIterator* iterator1 = a.waitlist->getIterator();
        Queue<Person>::QueueIterator* iterator2 = b.waitlist->getIterator();
        bool isgood=true;
        while(iterator1->hasNext()){
            if(!::assertEquals(iterator1->getNext(),iterator2->getNext()))
                isgood=false;
        }
        if(isgood)std::cout << "pass"<< std::endl;
        else{
            std::cout<<"people are not equal"<<std::endl;
            pass= false;
        }
    }

    if(pass)std::cout << "pass"<< std::endl;
    else std::cout<<"titles are not equal"<<std::endl;
}

void assertFileEmpty(std::string fileA) {
    std::ifstream fA (fileA);
    if(!fA.is_open()){
        std::cout << "Not able to open "<<fileA << std::endl;
        return;
    }
    std::string la;
    while(std::getline(fA,la)){
        if(la.length()>1){
            std::cout<<"FAIL: line "<< la <<" is not empty for file "<<fileA<<std::endl;
            return;
        }
    }
    std::cout<<"pass"<<std::endl;
}

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
        //std::cout << la.length()<<" "<<lb.length()<< std::endl;
        if(la!=lb){
            std::cout << "FAIL: line "<<line_counter<<" does not match (comparing "<<fileA<<" and "<<fileB<<")"<< std::endl;
            std::cout<<"'"<<la<<"'"<<std::endl;
            std::cout <<"'"<< lb<<"'"<< std::endl;
            return;
        }
    }
    std::cout << "pass"<< std::endl;
}

void makeDeliveryFile(){
    std::ofstream fA ("testfiles/delivery.txt");
    if(!fA.is_open()){
        std::cout << "Not able to open "<<"testfiles/delivery.txt" << std::endl;
        return;
    }
    fA<<"2 BOOK 1"<<std::endl;
    fA<<"2 BOOK 3"<<std::endl;
    fA<<"1 Go Dog Go"<<std::endl;
    fA.close();
}

void ::InvTester::runInvTests() {
    std::cout << "=== TESTING INVENTORY MANAGER ==="<< std::endl;
    InventoryManager* manager1;//=new InventoryManager("testfiles/null.json");
//    manager1->listInventory();
//    manager1->saveOutToFile("testfiles/s1.json");
//    manager1->saveOutToFile("testfiles/s2.json");
//    assertFilesEqual("testfiles/s1.json","testfiles/s2.json");
//    delete manager1;

    std::cout << "=== Testing IO (implicitly tests addTitle and addToWaitlist)"<< std::endl;
    testIO();
    // done IO

    manager1=new InventoryManager("testfiles/testsave.json");

    std::cout << "=== Testing checkIfTitleExists"<< std::endl;
    assertEquals(false,manager1->checkIfTitleExists(""));
    assertEquals(false,manager1->checkIfTitleExists("sadfasdfasdf"));
    assertEquals(true,manager1->checkIfTitleExists("BOOK 1"));

    std::cout << "=== Testing sell and modifyWantValue"<< std::endl;
    manager1->sell("BOOK 2");
    manager1->modifyWantValue("BOOK 2",1);
    manager1->saveOutToFile("testfiles/tmp.json");
    assertFilesEqual("testfiles/tmp.json","testfiles/test1.json");

    std::cout << "=== Testing order and return"<< std::endl;
    manager1->createBulkOrder("testfiles/tmp.txt");
    assertFilesEqual("testfiles/tmp.txt","testfiles/order.txt");
    manager1->createReturnInvoice("testfiles/tmp.txt");
    assertFilesEqual("testfiles/tmp.txt","testfiles/return.txt");

    makeDeliveryFile(); // because deliveryfile gets wiped
    std::cout << "=== Testing delivery, order, and return"<< std::endl;
    std::cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"<<std::endl;
    std::cout << "should print out to send 'BOOK 1' to bob "<<std::endl;
    std::cout<< "(bob@bob.com, phone 1234567890, contact preference 'doot')"<<std::endl;
    std::cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"<<std::endl;
    manager1->loadDelivery("testfiles/delivery.txt");
    manager1->saveOutToFile("testfiles/tmp.json");
    assertFilesEqual("testfiles/tmp.json","testfiles/test2.json");
    assertFileEmpty("testfiles/delivery.txt");
    //assertFilesEqual("testfiles/tmp.json","testfiles/test2.json");
//    manager1->saveOutToFile("testfiles/tmp.json");
//    assertFilesEqual("testfiles/tmp.json","testfiles/test1.json");

    delete manager1;
    std::cout << "=== DONE TESTING INVENTORY MANAGER ==="<< std::endl;

}

// also tests addTitle and addToWaitlist
void ::InvTester::testIO() {
    InventoryManager* manager1=new InventoryManager("testfiles/null.json");
    manager1->addTitle("BOOK 1",0,1);
    manager1->addTitle("BOOK 2",5,3);
    manager1->addTitle("BOOK 3",1,3);
    manager1->addToWaitlist("BOOK 1","bob","bob@bob.com","1234567890","doot");
    manager1->saveOutToFile("testfiles/tmp.json");
    assertFilesEqual("testfiles/tmp.json","testfiles/testsave.json");

    // make sure manager1==manager2
    InventoryManager* manager2=new InventoryManager("testfiles/testsave.json");

    TitleList* list1=manager1->titleList;
    TitleList* list2=manager2->titleList;
    ArrayList<Title>* arrayList1=list1->getSortedList();
    ArrayList<Title>* arrayList2=list2->getSortedList();
    if(::assertEquals(arrayList1->itemCount(),arrayList2->itemCount())){
        // arrays are the same size
        for(int i=0;i<arrayList1->itemCount();i++){
            if(!assertEquals(arrayList1->getValueAt(i),arrayList2->getValueAt(i)))return;
        }
    }

    delete manager1;
    delete manager2;
}
