//
// Created by Benjamin Welsh on 11/27/2017.
//
/**
 * Basic class representing a title (i.e. book) in the inventory.
 */
#ifndef COMP220BOOKSTORE_TITLE_H
#define COMP220BOOKSTORE_TITLE_H


#include "Person.h"
#include "Queue.h"

class Title {
public:
    std::string name;
    int have;
    int want;
    Queue<Person> waitlist;
};


#endif //COMP220BOOKSTORE_TITLE_H
