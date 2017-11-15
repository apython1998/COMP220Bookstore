//
// Created by benja on 11/15/2017.
//
#include "json.hpp"
#ifndef COMP220BOOKSTORE_JSONABLE_H
#define COMP220BOOKSTORE_JSONABLE_H

class JSONable{
public:
    virtual nlohmann::json toJSON()=0;
    virtual JSONable(nlohmann::json json)=0;
};
#endif //COMP220BOOKSTORE_JSONABLE_H
