//
// Created by chay on 11/28/2017.
// Sorted array implementation of TitleList
//

#ifndef COMP220BOOKSTORE_ARRAYTITLELIST_H
#define COMP220BOOKSTORE_ARRAYTITLELIST_H

#include "ArrayList.h"
#include "TitleList.h"

class ArrayTitleList:public TitleList {
private:
    //pointer to start of array
    ArrayList<Title>* arrayTitleList;

public:
    /**
     * Constructor
     * creates a pointer to an empty ArrayList
    */
    ArrayTitleList();

    /**
     * Copy Constructor
     * shallow copy
    */
    ArrayTitleList(const ArrayTitleList &listToCopy);

    /**
     * Destructor
     * frees arrayTitleList
    */
    ~ArrayTitleList() override;

    /**
     * finds the location of a Title object in arrayTitleList using binary search
     * @param titleToFind the Title to find
     * @returns Title object (nullptr if it doesn't exist)
    */
    Title* find(const std::string& titleToFind) override;

    /**
     * finds the location of a Title object in the sortedTitleList using binary search
     * @param titleToFind the Title to find
     * @returns index of Title
    */
    int findLocation(const std::string& titleToFind) override;

    /**
     * adds the Title object to the sortedArrayList in its alphabetical position
     * @param titleToAdd the Title to add
     * @post sortedArrayList is in alphabetical order
    */
    void add(Title titleToAdd) override;

    /**
     * returns the sorted array list
     * @return ArrayList object
     */
    ArrayList<Title>* getSortedList() override;
};

#endif //COMP220BOOKSTORE_ARRAYTITLELIST_H
