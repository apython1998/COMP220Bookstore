//
// Created by chay on 12/1/2017.
//

#include <string>
#include "ArrayTitleList.h"

/**
     * Constructor
     * creates a pointer to an empty ArrayList<Title>
    */
ArrayTitleList::ArrayTitleList() {
    arrayTitleList = new ArrayList<Title>();
}

/**
 * Copy Constructor
 * shallow copies listToCopy to the ArrayList<Title> pointer arrayTitleList
*/
ArrayTitleList::ArrayTitleList(const ArrayTitleList &listToCopy) {
    arrayTitleList = listToCopy.arrayTitleList;
}

/**
 * Destructor
 * frees ArrayList<Title> pointer arrayTitleList
*/
ArrayTitleList::~ArrayTitleList() {
    delete arrayTitleList;
}

/**
 * Adds a title object to arrayTitleList if it does not already exist
*/
void ArrayTitleList::add(Title titleToAdd) {
    int addAtIndex = findLocation(titleToAdd.name);


    if (addAtIndex != -1) {
        //std::cout << "Added " << titleToAdd.name << " At Index: " << addAtIndex << std::endl;
        arrayTitleList->insertAt(titleToAdd, addAtIndex);
    }
}

/**
 * Binary search stub function for Title objects
*/
Title* binarySearch(ArrayList<Title>* arrayTitleList, const int l, const int r, const std::string titleToFind) {
    if (r >= l) {
        int mid = l + (r - l)/2;
        std::string titleAtMid = arrayTitleList->getValueAt(mid).name;

        // If the element is present at the middle itself
        if (titleAtMid == titleToFind)  return arrayTitleList->getPointerAt(mid);

        // If element is smaller than mid, then it can only be present
        // in left subarray
        if (titleAtMid > titleToFind) return binarySearch(arrayTitleList, l, mid-1, titleToFind);

        // Else the element can only be present in right subarray
        return binarySearch(arrayTitleList, mid+1, r, titleToFind);
    }

    // We reach here when element is not present in array
    return nullptr;
}

/**
 * Binary search stub function for Title objects
*/
Title* binarySearch(ArrayList<Title>* arrayTitleList, const int size, const std::string titleToFind) {
    return binarySearch(arrayTitleList, 0, size-1, titleToFind);
}

/**
 * Finds Title object in arrayTitleList, returns nullptr if empty, otherwise returns pointer to Title
*/
Title* ArrayTitleList::find(const std::string& titleToFind) {
    if (arrayTitleList->isEmpty()) {
        return nullptr;
    }
    else {
        Title* title = binarySearch(arrayTitleList, arrayTitleList->itemCount(), titleToFind);
        return title;
    }
}

/**
 * Binary search stub function for indexes
*/
int binarySearchInt(ArrayList<Title>* arrayTitleList, const int l, const int r, const std::string titleToFind) {
    if (r >= l) {
        int mid = l + (r - l)/2;
        std::string titleAtMid = arrayTitleList->getValueAt(mid).name;

        // If the element is present at the middle itself
        if (titleAtMid == titleToFind)  return -1;

        // If element is smaller than mid, then it can only be present
        // in left subarray
        if (titleAtMid > titleToFind) return binarySearchInt(arrayTitleList, l, mid-1, titleToFind);

        // Else the element can only be present in right subarray
        return binarySearchInt(arrayTitleList, mid+1, r, titleToFind);
    }

    // We reach here when element is not present in array
    return l;
}

/**
 * Binary search stub function for indexes
*/
int binarySearchInt(ArrayList<Title>* arrayTitleList, const int size, const std::string titleToFind) {
    return binarySearchInt(arrayTitleList, 0, size-1, titleToFind);
}

/**
 * Find function for index location, used to add objects to ArrayList<Title>
*/
int ArrayTitleList::findLocation(const std::string& titleToFind) {
    if (arrayTitleList->isEmpty()) {
        return 0;
    }
    else {
        return binarySearchInt(arrayTitleList, arrayTitleList->itemCount(), titleToFind);
    }
}

/**
 * Returns the sorted ArrayList<Title>
*/
ArrayList<Title>* ArrayTitleList::getSortedList() {
    return arrayTitleList;
}

//It made me do this for comparing Title objects together.
//Wouldn't compile otherise.
bool operator == (const Title t1, const Title t2) {
    //checks if t1 is greater and returns true, otherwise returns false when it is less than or equal
    return t2.name < t1.name;
}