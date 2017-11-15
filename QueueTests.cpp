//
// Created by benja on 11/15/2017.
//

#include <iostream>
#include "QueueTests.h"
#include "LinkedQueue.h"
void queueCopyConstructorTest(){
    // test for length 0
    std::cout << "LinkedQueue copy constructor" << std::endl;
    LinkedQueue<std::string> emptyQ = LinkedQueue<std::string>();
    LinkedQueue<std::string> tmp1 = LinkedQueue<std::string>(emptyQ);
    if(emptyQ.isEmpty()&&tmp1.isEmpty())std::cout << "PASSED" << std::endl;
    else std::cout << "Empty LinkedQueue failed" << std::endl;
    LinkedQueue<std::string> q1 = LinkedQueue<std::string>();
    q1.enqueue("HELLO I AM BOB I AM FIRST");
    q1.enqueue("2nd");
    q1.enqueue("3rd");
    q1.enqueue("4th");
    LinkedQueue<std::string> q1_cp = LinkedQueue<std::string>(q1);
    bool allgood= true;
    try{
        if(q1_cp.dequeue()!="HELLO I AM BOB I AM FIRST")allgood= false;
        if(q1_cp.dequeue()!="2nd")allgood= false;
        if(q1_cp.dequeue()!="3rd")allgood= false;
        if(q1_cp.dequeue()!="4th")allgood= false;
    } catch (std::out_of_range& e){
        std::cout << "Not all elements copied" << std::endl;
        allgood=false;
    }
    if(allgood)std::cout << "PASSED" << std::endl;
    else std::cout << "Copy of LinkedQueue failed" << std::endl;
    try{
        q1_cp.dequeue();
        std::cout << "Failed: did not throw out_of_range for dequeue past length" << std::endl;
    }catch (std::out_of_range& e) {
        std::cout << "PASSED" << std::endl;
    }

    // assn operator
    LinkedQueue<std::string> q1_assn = LinkedQueue<std::string>(q1);
    allgood= true;
    try{
        if(q1_assn.dequeue()!="HELLO I AM BOB I AM FIRST")allgood= false;
        if(q1_assn.dequeue()!="2nd")allgood= false;
        if(q1_assn.dequeue()!="3rd")allgood= false;
        if(q1_assn.dequeue()!="4th")allgood= false;
    } catch (std::out_of_range& e){
        std::cout << "Not all elements copied" << std::endl;
        allgood=false;
    }
    if(allgood)std::cout << "PASSED" << std::endl;
    else std::cout << "Assn of LinkedQueue failed" << std::endl;
    try{
        q1_assn.dequeue();
        std::cout << "Failed: did not throw out_of_range for dequeue past length" << std::endl;
    }catch (std::out_of_range& e) {
        std::cout << "PASSED" << std::endl;
    }

    allgood = true;
    try{
        if(q1.dequeue()!="HELLO I AM BOB I AM FIRST")allgood= false;
        if(q1.dequeue()!="2nd")allgood= false;
        if(q1.dequeue()!="3rd")allgood= false;
        if(q1.dequeue()!="4th")allgood= false;
    } catch (std::out_of_range& e){
        std::cout << "Not all elements remain" << std::endl;
        allgood=false;
    }
    if(allgood)std::cout << "PASSED" << std::endl;
    else std::cout << "Copied LinkedQueue failed" << std::endl;
}

void simpleStackQueueTest(){
    std::cout << "simpleStackQueueTest" << std::endl;
    LinkedQueue<std::string> testQueue;

    for (int i=0; i<4; i++){
        std::string personToAdd = "person" + std::to_string(i+1);
        testQueue.enqueue(personToAdd);
    }
    std::cout << "Queue:" << std::endl;
    int count=1;
    while( ! testQueue.isEmpty()){
        std::cout << count << ":" << testQueue.dequeue()<< std::endl;
        count++;
    }
    std::cout << "\nStack:" << std::endl;
    count=1;
    while( ! testQueue.isEmpty()) {
        try {
            testQueue.dequeue();
            std::cout << "FAIL: should have thrown exception from dequeue" << std::endl;
        }
        catch (std::out_of_range &e) {
            std::cout << "pass: caught exception: " << e.what() << std::endl;
        }
    }
    testQueue.enqueue("Maria");
    testQueue.enqueue("Janice");
    testQueue.dequeue();
    testQueue.enqueue("Paul");
    testQueue.enqueue("Johan");
    testQueue.dequeue();
    std::cout << testQueue.dequeue()<< std::endl;
}