//
// Created by chay on 11/28/2017.
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
     * shallow copies listToCopy to the ArrayList pointer sortedTitleList
    */
    ArrayTitleList(const ArrayList<Title>* listToCopy);

    /**
     * Destructor
     * frees ArrayList pointer sortedTitleList
    */
    ~ArrayTitleList();

    /**
     * finds the location of a Title object in the sortedTitleList using binary search
     * @param titleToFind the Title to find
     * @returns index of Title (-1 if it doesn't exist)
    */
    Title find(std::string titleToFind);

    /**
     * adds the Title object to the sortedTitleList in its alphabetical position
     * @param titleToAdd the Title to add
     * @throws illegal_argument exception if Title already exists in sortedTitleList
     * @post sortedTitleList is in alphabetical order
    */
    void add(Title titleToAdd);

    ArrayList<Title>* getSortedList();

};

#endif //COMP220BOOKSTORE_ARRAYTITLELIST_H
