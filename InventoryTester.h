//
// Created by benja on 12/18/2017.
// Inventory Tester functions
//

#ifndef COMP220BOOKSTORE_INVENTORYTESTER_H
#define COMP220BOOKSTORE_INVENTORYTESTER_H


#include <string>
#include "Title.h"

namespace InvTester{
    /**
     * Asserts that fileA's contents exactly match fileB
     */
    void assertFilesEqual(std::string fileA, std::string fileB);
    /**
     * Tests the IO components of InventoryManager
     */
    void testIO();
    /**
     * Runs the test suite for InventoryManager
     */
    void runInvTests();
}
#endif //COMP220BOOKSTORE_INVENTORYTESTER_H
