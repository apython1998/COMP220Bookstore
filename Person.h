//
// Created by benja on 11/27/2017.
//

#ifndef COMP220BOOKSTORE_PERSON_H
#define COMP220BOOKSTORE_PERSON_H


#include <string>
#include "json.hpp"

/**
 * Basic class representing a person (that would be on a waitlist).
 */
class Person {
public:
    std::string name;
    std::string phoneNumber;
    std::string email;
    std::string contactPreference;

    Person(const Person& toCopy);
    Person(nlohmann::json json);
    Person();

    Person(const std::string &name, const std::string &phoneNumber, const std::string &email,
           const std::string &contactPreference);
    nlohmann::json toJSON();
};


#endif //COMP220BOOKSTORE_PERSON_H
