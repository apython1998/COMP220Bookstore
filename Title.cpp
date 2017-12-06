//
// Created by benja on 11/27/2017.
//

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

