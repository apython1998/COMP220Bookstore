//
// Created by benja on 11/27/2017.
//

#ifndef COMP220BOOKSTORE_PERSON_H
#define COMP220BOOKSTORE_PERSON_H


#include <string>
/**
 * Basic class representing a person (that would be on a waitlist).
 */
class Person {
    std::string name;
    std::string phoneNumber;
    std::string email;
    std::string contactPreference;
public:
    Person(const Person& toCopy);
    Person();
};


#endif //COMP220BOOKSTORE_PERSON_H
