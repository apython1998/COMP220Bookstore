//
// Created by chay on 11/27/2017.
//

#ifndef COMP220BOOKSTORE_ARRAYSORTEDTITLELIST_H
#define COMP220BOOKSTORE_ARRAYSORTEDTITLELIST_H

class ArraySortedTitleList {
private:
    //pointer to start of array
    ArrayList* sortedTitleList;

public:
    /**
     * Constructor
     * creates a pointer to an empty ArrayList
    */
    SortedTitleList();

    /**
     * Copy Constructor
     * shallow copies listToCopy to the ArrayList pointer sortedTitleList
    */
    SortedTitleList(const ArrayList* listToCopy);

    /**
     * Destructor
     * frees ArrayList pointer sortedTitleList
    */
    ~SortedTitleList();

    /**
     * finds the location of a Title object in the sortedTitleList using binary search
     * @param titleToFind the Title to find
     * @returns index of Title (-1 if it doesn't exist)
    */
    int find(Title titleToFind);

    /**
     * adds the Title object to the sortedTitleList in its alphabetical position
     * @param titleToAdd the Title to add
     * @throws illegal_argument exception if Title already exists in sortedTitleList
     * @post sortedTitleList is in alphabetical order
    */
    void add(Title titleToAdd);
};

#endif //COMP220BOOKSTORE_ARRAYSORTEDTITLELIST_H
