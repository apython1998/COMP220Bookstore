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
#include "json.hpp"
#include "InventoryTester.h"
//namespace InvTester{}
class Title {
    friend bool assertEquals(Title a, Title b);
private:
    Queue<Person>* waitlist;
public:
    std::string name;
    int have;
    int want;

    Title();

    ~Title();

    Title(const Title& toCopy);
    Title& operator=(const Title &toCopy);
    Title(const std::string &name, int have, int want);

    Title(nlohmann::json json);
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

    /**
     * Prints the waitlist nicely
     */
    void printWaitlist();

    /**
     * Gets the size of the waitlist. O(n)!
     */
    int waitlistCount();
    /**
     * Pretty print helper function
     */
    static void printWaitlistHeader();
    /**
     * Pretty prints a person for a table
     */
    static void printPersonForWaitlist(Person person);

    /**
     * Returns representative json object
     */
    nlohmann::json toJSON();
};


#endif //COMP220BOOKSTORE_TITLE_H
