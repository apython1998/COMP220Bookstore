//
// Created by chay on 11/27/2017.
//

#ifndef COMP220BOOKSTORE_TITLELIST_H
#define COMP220BOOKSTORE_TITLELIST_H

#include "Title.h"
#include "ArrayList.h"

class TitleList {
public:
    /**
     * Destructor
    */
    virtual ~TitleList(){};

    /**
     * finds the location of a Title object in the sortedTitleList using binary search
     * @param titleToFind the Title to find
     * @returns index of Title (-1 if it doesn't exist)
    */
    virtual int find(std::string titleToFind)=0;

    /**
     * adds the Title object to the sortedTitleList in its alphabetical position
     * @param titleToAdd the Title to add
     * @throws illegal_argument exception if Title already exists in sortedTitleList
     * @post sortedTitleList is in alphabetical order
    */
    virtual void add(Title titleToAdd)=0;

    virtual ArrayList<Title>* getSortedList()=0;
};

#endif //COMP220BOOKSTORE_TITLELIST_H
