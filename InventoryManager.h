//
// Created by Alex Python on 11/27/17.
//

#ifndef COMP220BOOKSTORE_INVENTORYMANAGER_H
#define COMP220BOOKSTORE_INVENTORYMANAGER_H

#include "SortedTitleList.h"
class InventoryManager{
private:
    SortedTitleList titleList;
public:
    /**
     * returns true if title exists
     */
    bool checkIfTitleExists(std::string title);
    /**
     * Prints a succinct inventory list sorted alphabetically.
     */
    void listInventory();
    /**
     * Prints detailed information about a book title
     */
    void inquireTitle(std::string title);

    /**
     * Prints succinct information about a book title
     */
    void inquireTitleOneLine(std::string title);
    /**
     * Adds a person to the waitlist
     * @param title The book title to add the person to the waitlist for
     * @param contactPref The contact method preferred (generally "call", "text", or "email")
     */
    void addToWaitlist(std::string title, std::string personName, std::string email,
                       std::string phoneNumber, std::string contactPref);
    /**
     * Sells a book. Will add the title to the inventory if it is not already.
     * @param title the title of the book to sell
     * @return False if the book is out of stock
     */
    bool sell(std::string title);
    /**
     * Adds a title to the inventory.
     */
    void addTitle(std::string title, int have, int want);
    /**
     * Changes the want value of a title
     */
    bool modifyWantValue(std::string title,int newWant);
    /**
     * Puts a bulk order into a file
     * @throws an exception of some sort if the file cannot be created
     */
    void createBulkOrder(std::string filename);
    /**
     * Loads a delivery from a file.
     * @throws an exception of some sort if the file cannot be found/invalid format/cannot be read
     */
    void loadDelivery(std::string filename);
    /**
     * Writes a return invoice to a file
     * @throws an exception of some sort if the file cannot be created
     */
    void createReturnInvoice(std::string filename);
};

#endif //COMP220BOOKSTORE_INVENTORYMANAGER_H
