//
// Created by benja on 12/18/2017.
//

#ifndef COMP220BOOKSTORE_INVENTORYTESTER_H
#define COMP220BOOKSTORE_INVENTORYTESTER_H


#include <string>
#include "Title.h"

namespace InvTester{
    void assertFilesEqual(std::string fileA, std::string fileB);
    void testIO();
    void runInvTests();
}
#endif //COMP220BOOKSTORE_INVENTORYTESTER_H
