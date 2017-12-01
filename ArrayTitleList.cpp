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

/**
 * adds the Title object to the sortedTitleList in its alphabetical position
 * @param titleToAdd the Title to add
 * @throws illegal_argument exception if Title already exists in sortedTitleList
 * @post sortedTitleList is in alphabetical order
*/
void ArrayTitleList::add(Title titleToAdd) {
    //std::cout << "Finding Title: " << titleToAdd.name << std::endl;
    int addAtIndex = find(titleToAdd.name);

    //std::cout << "Added Title At Index: " << addAtIndex << std::endl;
    arrayTitleList->insertAt(titleToAdd, addAtIndex);
}

int binFind(ArrayList<Title>* arrayTitleList, const std::string titleToFind, const int start, const int size, const int PTA) {
    int middle = (start + size) / 2;
    std::string titleAtMiddle = arrayTitleList->getValueAt(middle).name;
    if (start <= size) {
        if (titleToFind == titleAtMiddle){
            return middle;
        }
        else if (titleToFind < titleAtMiddle) {
            return binFind(arrayTitleList, titleToFind, start, middle-1, -1);
        }
        else {
            return binFind(arrayTitleList, titleToFind, middle+1, start, 1);
        }
    }
    //PTA keeps track of the position that titleToFind belongs in regard to the last title it was compared to
    return middle+PTA;
}

int binFind(ArrayList<Title>* arrayTitleList, const int size, const std::string titleToFind) {
    return binFind(arrayTitleList, titleToFind, 0, size, 0);
}

/**
 * finds the location of a Title object in the sortedTitleList using binary search
 * @param titleToFind the Title to find
 * @returns index of Title (-1 if it doesn't exist)
*/
int ArrayTitleList::find(std::string titleToFind) {
    if (arrayTitleList->isEmpty()) {
        return 0;
    }
    else {
        int index = binFind(arrayTitleList, arrayTitleList->itemCount(), titleToFind);

        //This fixes an issue when the binfind says we should add at -1 which really just means the first index
        if (index == -1) {
            return 0;
        }
        return index;
    }
}

ArrayList<Title>* ArrayTitleList::getSortedList() {
    return arrayTitleList;
}

//It made me do this for comparing Title objects together.
bool operator == (const Title t1, const Title t2) {
    //checks if t1 is greater and returns true, otherwise returns false when it is less than or equal
    if( t2.name < t1.name){
        return true;
    }
    else {
        return false;
    }
}