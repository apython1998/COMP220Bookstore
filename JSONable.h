//
// Created by benja on 11/15/2017.
//
#include "json.hpp"
#ifndef COMP220BOOKSTORE_JSONABLE_H
#define COMP220BOOKSTORE_JSONABLE_H

class JSONable{
public:
    JSONable(){};
    virtual nlohmann::json toJSON()=0;
    JSONable(nlohmann::json json);
};
#endif //COMP220BOOKSTORE_JSONABLE_H
