//
// Created by Alex Python on 11/10/17.
//
#include <iostream>
#include "List.h"
#include "ArrayList.h"
//#include "LinkedList.h"
#include "ListTests.h"
#include "QueueTests.h"
#include "UITester.h"
#include "ArrayTitleList.h"

bool DO_TESTS=true;

void testAllForList(List<int>* list1, List<int>* list2){
    rangeErrorTests(list1);

    int a1[] {3, 5, 7, 9};
    insertAtFrontAndEndIsEmptyClearTester(list1, list2, a1, 4);
    list1->clearList();
    list2->clearList();

    int a2[] {-1, -3, -43, -654, -3, 0, -2, -24};
    insertAtFrontAndEndIsEmptyClearTester(list1, list2, a2,8);
    list1->clearList();
    list2->clearList();

    insertAtTester(list1);
    list1->clearList();

    findTester(list1);
    list1->clearList();
}
void testQueues(){
    printf("\n*************************\nTESTING QUEUES:\n*************************\n");
    queueCopyConstructorTest();
    simpleStackQueueTest();
}
void testLists(){
    List<int>* testList1 = new ArrayList<int>();
    List<int>* testList2 = new ArrayList<int>();
    printf("\n*************************\nTESTING WITH ARRAY LIST:\n*************************\n");
//    try {
    testAllForList(testList1, testList2);
//    }catch(std::out_of_range e){
//        std::cout << "Why tho" << std::endl;
//    }
    delete testList1;
    delete testList2;


//    testList1 = new LinkedList<int>();
//    testList2 = new LinkedList<int>();
//    printf("\n*************************\nTESTING WITH LINKED LIST:\n*************************\n");
//    testAllForList(testList1, testList2);
//    delete testList1;
//    delete testList2;
}

void testArrayTitleList() {
    printf("\n*************************\nTESTING ArrayTitleList:\n*************************\n");
    TitleList testList = ArrayTitleList();
    Title bookA = Title();
    Title bookB = Title();
    Title bookC = Title();
    Title bookD = Title();
    Title bookE = Title();
    bookA.name = "bookA";
    bookB.name = "bookB";
    bookC.name = "bookC";
    bookD.name = "bookD";
    bookE.name = "bookE";

    testList.add(bookA);
    testList.add(bookC);
    testList.add(bookE);
    testList.add(bookD);
    testList.add(bookB);
    testList.add(bookA);

    std::cout << "Following numbers should be -1 -1 -1 -1 -1 followed by the book names, if they are not it FAILED" << std::endl;
    std::cout << testList.findLocation("bookA") << std::endl;
    std::cout << testList.findLocation("bookB") << std::endl;
    std::cout << testList.findLocation("bookC") << std::endl;
    std::cout << testList.findLocation("bookD") << std::endl;
    std::cout << testList.findLocation("bookE") << std::endl;
    std::cout << testList.find("bookA")->name << std::endl;
    std::cout << testList.find("bookB")->name << std::endl;
    std::cout << testList.find("bookC")->name << std::endl;
    std::cout << testList.find("bookD")->name << std::endl;
    std::cout << testList.find("bookE")->name << std::endl;
}

void runTests() {
    if(DO_TESTS){
        testLists();
        testQueues();
        testArrayTitleList();
        std::cout << std::endl;
        testUI();
        printf("\n*************************\nWOOT TESTS FINISHED WOOT\n*************************\n");
    }else{

    }
}