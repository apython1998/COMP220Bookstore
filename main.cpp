//
// Created by Alex Python on 11/10/17.
//
#include <iostream>
#include "List.h"
#include "ListTests.h
bool DO_TESTS=true;

void testAllForList(IntList* list1, IntList* list2){
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


    testList1 = new LinkedList<int>();
    testList2 = new LinkedList<int>();
    printf("\n*************************\nTESTING WITH LINKED LIST:\n*************************\n");
    testAllForList(testList1, testList2);
    delete testList1;
    delete testList2;
    printf("\n*************************\nWOOT TESTS FINISHED WOOT\n*************************\n");
}
int main() {
    std::cout<< "HELLO WORL" ;
    if(DO_TESTS){

    }else{

    }
    return 0;
}