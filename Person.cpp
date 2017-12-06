//
// Created by benja on 11/27/2017.
//

#include "Person.h"

Person::Person(const Person& toCopy) {
    name=toCopy.name;
    email=toCopy.email;
    phoneNumber=toCopy.phoneNumber;
    contactPreference=toCopy.contactPreference;
}

Person::Person() {
    name="";
    email="";
    phoneNumber="";
    contactPreference="";
}

Person::Person(const std::string &name, const std::string &phoneNumber, const std::string &email,
               const std::string &contactPreference) : name(name), phoneNumber(phoneNumber), email(email),
                                                       contactPreference(contactPreference) {}
