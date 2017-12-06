//
// Created by benja on 11/27/2017.
//

#include <iostream>
#include "Title.h"
#include "LinkedQueue.h"

Title::Title() {
    waitlist=new LinkedQueue<Person>();
}

//Title::Title(const Title &toCopy){
//    name=toCopy.name;
//    have=toCopy.have;
//    want=toCopy.want;
//    waitlist=new LinkedQueue<Person>(); //fixme
//    //waitlist=new LinkedQueue<Person>((LinkedQueue)*toCopy.waitlist);

//}

Title::Title(const std::string &name, int have, int want) : name(name), have(have), want(want) {
    waitlist=new LinkedQueue<Person>();
}

void Title::addToWaitlist(const Person &person) {
    waitlist->enqueue(person);
}

Person Title::getNextFromWaitlist() {
    return waitlist->dequeue();
}

bool Title::waitlistHasNext() {
    return !waitlist->isEmpty();
}

void Title::printWaitlist() {
    Queue<Person>::QueueIterator* iterator = waitlist->getIterator();
    std::cout << "\t----------------------------------------------------------------------------------------"<<std::endl;
    std::cout<<"\t";
    std::cout.width(25);
    std::cout << std::left<<"Name";
    std::cout.width(35);
    std::cout << std::left << "email";
    std::cout.width(15);
    std::cout << std::left << "phone #";
    std::cout.width(20);
    std::cout << std::left << "Contact pref" << std::endl;
    std::cout << "\t----------------------------------------------------------------------------------------"<<std::endl;
    while(iterator->hasNext()){
        Person person=iterator->getNext();
        std::cout<<"\t";
        std::cout.width(25);
        std::cout << std::left<<person.name;
        std::cout.width(35);
        std::cout << std::left<<person.email;
        std::cout.width(15);
        std::cout << std::left <<person.phoneNumber;
        std::cout.width(20);
        std::cout << std::left << person.contactPreference << std::endl;
    }
    delete iterator;
}

