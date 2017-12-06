//
// Created by chay on 12/1/2017.
//

#include <string>
#include "ArrayTitleList.h"

/**
     * Constructor
     * creates a pointer to an empty ArrayList
    */
ArrayTitleList::ArrayTitleList() {
    arrayTitleList = new ArrayList<Title>();
}

/**
 * Copy Constructor
 * shallow copies listToCopy to the ArrayList pointer sortedTitleList
*/
ArrayTitleList::ArrayTitleList(const ArrayList<Title>* listToCopy) {

}

/**
 * Destructor
 * frees ArrayList pointer sortedTitleList
*/
ArrayTitleList::~ArrayTitleList() {
    delete arrayTitleList;
}

void ArrayTitleList::add(Title titleToAdd) {
    int addAtIndex = findLocation(titleToAdd.name);


    if (addAtIndex != -1) {
        //std::cout << "Added " << titleToAdd.name << " At Index: " << addAtIndex << std::endl;
        arrayTitleList->insertAt(titleToAdd, addAtIndex);
    }
}

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

Title* binarySearch(ArrayList<Title>* arrayTitleList, const int size, const std::string titleToFind) {
    return binarySearch(arrayTitleList, 0, size-1, titleToFind);
}

Title* ArrayTitleList::find(const std::string& titleToFind) {
    if (arrayTitleList->isEmpty()) {
        return nullptr;
    }
    else {
        Title* title = binarySearch(arrayTitleList, arrayTitleList->itemCount(), titleToFind);
        return title;
    }
}

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

int binarySearchInt(ArrayList<Title>* arrayTitleList, const int size, const std::string titleToFind) {
    return binarySearchInt(arrayTitleList, 0, size-1, titleToFind);
}

int ArrayTitleList::findLocation(const std::string& titleToFind) {
    if (arrayTitleList->isEmpty()) {
        return 0;
    }
    else {
        return binarySearchInt(arrayTitleList, arrayTitleList->itemCount(), titleToFind);
    }
}

ArrayList<Title>* ArrayTitleList::getSortedList() {
    return arrayTitleList;
}








//It made me do this for comparing Title objects together.
bool operator == (const Title t1, const Title t2) {
    //checks if t1 is greater and returns true, otherwise returns false when it is less than or equal
    return t2.name < t1.name;
}