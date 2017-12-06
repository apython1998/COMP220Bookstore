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
private:
    Queue<Person>* waitlist;
public:
    std::string name;
    int have;
    int want;

    Title();

    //Title(const Title &toCopy);
    Title(const std::string &name, int have, int want);

    /**
     * Adds a person to the waitlist
     */
    void addToWaitlist(const Person& person);
    /**
     * Gets the next person from the waitlist
     * @pre the waitlist must first be checked with waitlistHasNext()
     */
    Person getNextFromWaitlist();
    /**
     * Returns true if the waitlist is not empty
     */
    bool waitlistHasNext();
};


#endif //COMP220BOOKSTORE_TITLE_H
