/**
 * Created by Toby Dragon for Comp 220 lab
 * Modified 11-14-17
 */
#include <iostream>
#include "List.h"



void rangeErrorTests(List<int>* list){
    bool errors = false;
    printf("Testing out of range errors:\n");
    try {
        list->removeValueAt(100);
        printf("Failed on removing big index\n");
        errors = true;
    } catch(std::out_of_range& e) {
        
    }
    try {
        list->removeValueAt(-5);
        printf("Failed on removing negative index\n");
        errors = true;
    } catch(std::out_of_range& e) {
        
    }
    try {
        list->getValueAt(100);
        printf("Failed on getting big index\n");
        errors = true;
    } catch(std::out_of_range& e) {
        
    }
    try {
        list->getValueAt(-5);
        printf("Failed on getting negative index\n");
        errors = true;
    } catch(std::out_of_range& e) {
        
    }
    try {
        //list->(-5);
        printf("Failed on getting negative index\n");
        errors = true;
    } catch(std::out_of_range& e) {

    }
    if (!errors){
        std::cout << "pass"<<std::endl;
    }
    errors = false;
}

void insertAtFrontAndEndIsEmptyClearTester(List* insertAtEndList, List<int>* insertAtFrontList, int* testInputArray, int size){
    std::cout << "\n\ntestListOnArray: " << toString(testInputArray, size) << std::endl;

    std::cout << "Testing adds and get: "<< std::endl;
    bool errors = false;
    for (int i=0; i<size; i++){
        insertAtEndList->insertAtEnd(testInputArray[i]);
        insertAtFrontList->insertAtFront(testInputArray[i]);
        if (insertAtEndList->itemCount() != i+1){
            std::cout << "ERROR: AddToEnd wrong size for:"<< insertAtEndList->toString() << std::endl;
            errors = true;
        }
        if (insertAtFrontList->itemCount() != i+1){
            std::cout << "ERROR: AddToFront wrong size for:"<< insertAtFrontList->toString()<<std::endl;
            errors = true;
        }
    }
    for (int i=0; i<size; i++){
        if (insertAtEndList->getValueAt(i) != testInputArray[i]){
            std::cout << "AddToEnd wrong get for:"<< insertAtEndList->toString()<<std::endl;
            errors = true;
        }
        if (insertAtFrontList->getValueAt(size-1-i) != testInputArray[i]){
            std::cout << "AddToFront wrong size for :"<< insertAtFrontList->toString()<<std::endl;
            errors = true;
        }
    }
    if (!errors){
        std::cout << "pass"<<std::endl;
    }
    errors = false;

    std::cout << "Testing arrayList itemCount when full:" << std::endl;
    if (size != insertAtEndList->itemCount()) {
        std::cout << "FAIL: itemCount different on AddToEnd" << std::endl;
        errors = true;
    }
    if (size != insertAtFrontList->itemCount()) {
        std::cout << "FAIL: itemCount different on AddToFront" << std::endl;
        errors = true;
    }
    if (!errors){
        std::cout << "pass"<<std::endl;
    }
    errors = false;

    std::cout << "Testing remove from both lists:" << std::endl;
    for (int i=0; i<size; i++){
        int ans1 = insertAtEndList->removeValueAt(0);
        if (ans1 != testInputArray[i]  || insertAtEndList->itemCount() != size-i-1){
            errors = true;
            std::cout << "AddToEnd wrong remove: got "<< ans1 << " instead of " << testInputArray[i] << " for array:"<< insertAtEndList->toString()<<std::endl;
        }
        int ans2 = insertAtFrontList->removeValueAt(0);
        if (ans2 != testInputArray[size-i-1] || insertAtFrontList->itemCount() != size-i-1){
            errors = true;
            std::cout << "AddToFront wrong remove: got "<< ans2 << " instead of " << testInputArray[i] << " for array:"<< insertAtEndList->toString()<<std::endl;
        }
    }
    if (!errors){
        std::cout << "pass"<<std::endl;
    }
    errors = false;

    std::cout << ("Testing arrayList sizes when empty:\n");
    if (0 != insertAtEndList->itemCount()) {
        std::cout << ("FAIL: Size different on AddToEnd\n");
        errors = true;
    }
    if (0 != insertAtFrontList->itemCount()) {
        std::cout << ("FAIL: Size different on AddToFront\n");
        errors = true;
    }
    if (!errors){
        std::cout << "pass"<<std::endl;
    }
    errors = false;
}

void insertAtFrontAndEndIsEmptyClearTester(List<int>* tester) {
    int errorCount = 0;
    std::cout << ("\nTesting adding to the end and front simultaneously:\n");
    //add to the end and to the front
    tester->insertAtFront(20);
    tester->insertAtEnd(30);
    tester->insertAtFront(10);
    tester->insertAtEnd(40);
    for (int i = 10; i < 40; i += 10) {
        if (i != tester->getValueAt((i / 10) - 1)) {
            errorCount++;
            std::cout << "FAIL: list incorrect, should be {10, 20, 30, 40}, is:" << tester->toString() << "\n";
        }
    }
    //std::cout << tester.toString() << std::endl;
    if (tester->itemCount() != 4) {
        errorCount++;
        std::cout << ("FAIL: itemCount() failed\n");
    }
    if (tester->isEmpty()) {
        errorCount++;
        std::cout << ("FAIL: isEmpty() returned true when should be false\n");
    }

    tester->clearList();
    if (0 != tester->itemCount()) {
        errorCount++;
        std::cout << ("FAIL: clearList() failed, item count not zero\n");
    }
    if (!tester->isEmpty()) {
        errorCount++;
        std::cout << ("FAIL: isEmpty() returned false when should be true\n");
    }
    if (errorCount ==0){
        std::cout << "pass"<<std::endl;
    }
    else {
        std::cout << "FAIL: with " << errorCount << "errors" << std::endl;
    }
}

void insertAtTester(List<int>* tester){
    std::cout << ("\nTesting insertAt:\n");
    //std::cout << ("Adding to a bunch of indexes\n");
    //fill up a list with 1-5
    bool errors = false;
    for (int j = 0; j < 5; j++) {
        tester->insertAtEnd(j);
    }
    for (int i = 5; i > -1; i--) {
//        try{
            tester->insertAt(333, i);
//        }catch(std::out_of_range& e){
//            std::cout << "HELLO" << std::endl;
//        }
    }
    //std::cout << tester.toString() <<std::endl;
    //check to see if 333 is at every other index
    for (int i=0; i < tester->itemCount(); i+=2) {
        //std::cout << tester.get(i) <<std::endl;
        if (tester->getValueAt(i) != 333) {
            errors = true;
            std::cout << ("FAIL: missing an add of 333\n");
        }
    }
    if (!errors){
        std::cout << "pass"<<std::endl;
    }
    errors = false;

}

void findTester(List<int>* tester) {
    std::cout << ("\nTesting find\n");
    bool errors = false;
    //fill up tester 0-9
    for (int i=0; i< 10; i++) {
        tester->insertAtEnd(i);
    }

    //std::cout << tester.toString() << std::endl;
    //find 0-9
    for (int i = 0; i < 10; i++) {
        if (i != tester->find(i)) {
            std::cout << "Failed to find " <<  i << std::endl;
            errors = true;
        }
    }
    if (tester->findMaxIndex() != 9){
        std::cout << ("FindMax failed at array end\n");
        errors = true;
    }
    tester->insertAtFront(100);
    if (tester->findMaxIndex() != 0){
        std::cout << ("FindMax failed at array start\n")<<tester->toString()<<std::endl;
        errors = true;
        //std::cout << tester.toString() << tester.findMax() <<std::endl;
    }
    tester->insertAtEnd(2);
    if (tester->findLast(2) != tester->itemCount()-1) {
        std::cout << ("FindLast failed\n");
        errors = true;
    }
    tester->clearList();
    if(tester->findMaxIndex()!=-1){
        std::cout << ("FindMax failed to return -1\n");
        errors = true;
    }
    //test negative numbers
    for (int i=-10; i < 0; i++) {
        tester->insertAtEnd(i);
    }
    //std::cout << tester.toString() << std::endl;
    if (tester->findMaxIndex() != 9){
        std::cout << ("FindMax failed at array end with negative numbers\n");
        errors = true;
    }
    tester->insertAtFront(100);
    if (tester->findMaxIndex() != 0){
        std::cout << ("FindMax failed at array start\n");
        errors = true;
    }
    if (!errors){
        std::cout << "pass"<<std::endl;
    }
}