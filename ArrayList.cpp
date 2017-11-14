//
// Created by Alex Python on 10/10/17.
//

#include <iostream>
#include "ArrayLib.h"
#include "ArrayList.h"

/**
 * Constructor for ArrayList
 * @param initialCapacity
 */
ArrayList::ArrayList(int initialCapacity) {
    array = new int[initialCapacity];
    currItemCount = 0;
    currCapacity = initialCapacity;
}

/**
 * Copy constructor for ArrayList
 * @param arrayListToCopy
 */
ArrayList::ArrayList(const ArrayList &arrayListToCopy) {
    array = new int[arrayListToCopy.currCapacity];
    currItemCount = arrayListToCopy.currItemCount;
    currCapacity = arrayListToCopy.currCapacity;
    for (int i=0; i < currItemCount; i++) {
        array[i] = arrayListToCopy.array[i] ;
    }
}

//Overloaded Assignment Operator
ArrayList& ArrayList::operator=(const ArrayList &arrayListToCopy) {
    if (this != &arrayListToCopy) {
        delete[] array;
        array = nullptr;
        array = new int[arrayListToCopy.currCapacity];
        currItemCount = arrayListToCopy.currItemCount;
        currCapacity = arrayListToCopy.currCapacity;
        for (int i = 0; i < currItemCount; i++) {
            array[i] = arrayListToCopy.array[i];
        }
    }
    return (*this);
}

/**
 * Destructor for ArrayList
 */
ArrayList::~ArrayList() {
    delete[] array;
    array = nullptr;
}

/**
     * replaces the old array with an array twice the size
     * private method only called within ArrayList when necessary
     * @post: array points to a new array of twice the size with values copied from the old one,
     *        the old array is deleted.
*/
void ArrayList::doubleCapacity() {
    int nulltimer = 0;
    int* original = ::copyArray(array, currItemCount, nulltimer);
    delete[] array;
    array = new int[currCapacity * 2];
    for (int i=0; i<currItemCount; i++) {
        array[i] = original[i];
    }
    currCapacity = currCapacity*2;
    delete[] original;
}

/**
 * appends the new item to the end of the list
 * @param itemToAdd the item to add to the end of the array
 * @post the list has an additional value in it, at the end
 */
void ArrayList::insertAtEnd(int itemToAdd) {
    if (currItemCount == currCapacity) {
        doubleCapacity();
    }
    array[currItemCount] = itemToAdd;
    currItemCount++;
}

/**
 * appends the new item to the beginning of the list
 * @param itemToAdd the item to add to the beginning of the list
 * @post the list has an additional value in it, at the beginning
 *    all other items are shifted down by one index
 */
void ArrayList::insertAtFront(int itemToAdd) {
    if (currItemCount == currCapacity) {
        doubleCapacity();
    }
    for (int i=(currItemCount); i>=0; i--) {
        if (i == 0) {
            array[i] = itemToAdd;
        } else {
            array[i] = array[i - 1];
        }
    }
    currItemCount++;
}

/**
 * inserts the item into the list so that it can be found with get(index)
 * @param itemToAdd the item to add
 * @param index the location in which to insert this item
 * @post the list has an additional value in it at the specified index,
 *        all further values have been shifted down by one index
 * @throws out_of_range exception if index is invalid (< 0 or >currItemCount)
 */
void ArrayList::insertAt(int itemToAdd, int index) {
    if (index < 0 || index > currItemCount) {
        throw std::out_of_range("Index Out of Bounds");
    } else if (index == currItemCount) {
        insertAtEnd(itemToAdd);
        return;
    } else if (index == 0) {
        insertAtFront(itemToAdd);
        return;
    } else {
        for (int i = currItemCount; i>= index; i--) {
            if (i == index) {
                array[i] = itemToAdd;
            } else {
                array[i] = array[i-1];
            }
        }
    }
    currItemCount++;
}

/**
 * gets a value from the list
 * @param index the location from which to get the value
 * @returns a copy of the item at index
 * @throws out_of_range exception if index is invalid
 */
int ArrayList::getValueAt(int index) {
    if (index<0 || index>= currItemCount) {
        throw std::out_of_range("Index Out of Bounds");
    } else {
        return array[index];
    }
}

/**
 * removes the item at index from the list, and returns a copy of that item
 * @param index the location from which to get the value
 * @post the item at index is removed from the list, everything else is shifted down one
 * @returns a copy of the item at index
 * @throws out_of_range exception if index is invalid
 */
int ArrayList::removeValueAt(int index) {
    if (index<0 || index>= currItemCount) {
        throw std::out_of_range("Index Out of Bounds");
    } else {
        int beingRemoved = array[index];
        for (int i=0; i<currItemCount; i++) {
            if (i>index) {
                array[i-1] = array[i];
            }
        }
        currItemCount--;
        return beingRemoved;
    }
}

/**
 * checks if there are any valid items in the list
 * @returns true if there are no valid items in the list, false otherwise
 */
bool ArrayList::isEmpty() {
    if (currItemCount>0) {
        return false;
    } else {
        return true;
    }
}

/**
 * returns a count of valid items currently in the list
 * @returns the number of valid items in the list
 */
int ArrayList::itemCount() {
    return currItemCount;
}

/**
 * removes all valid items from the list
 * @post the list is completely clear of valid items
 */
void ArrayList::clearList() {
    currItemCount = 0;
}

/**
 * gives a string representation of the current list
 * @returns a string representing the given list in the exact format shown below
 * {1, 2, 3, 4, 5}
 */
std::string ArrayList::toString() {
    return ::toString(array, currItemCount);
}

/**
 * finds the largest value in the array
 * @post numLinesRun is updated to include lines run by this function
 * @return the first index of the maximum value, or -1 if size < 1
 */
int ArrayList::findMaxIndex() {
    int nulltimer = 0;
    return ::findMaxIndex(array, currItemCount, nulltimer);
}

/**
 * Searches an int array for a certain value
 * @post numLinesRun is updated to include lines run by this function
 * @return the index of the first occurrence of numToFind if it is present, otherwise returns -1
 */
int ArrayList::find(int numToFind) {
    int nulltimer = 0;
    return ::find(array, currItemCount, numToFind, nulltimer);
}

/**
 * Searches an int array for a certain value
 * @post numLinesRun is updated to include lines run by this function
 * @return the index of the last occurrence of numToFind if it is present, otherwise returns -1
 */
int ArrayList::findLast(int numToFind) {
    int nulltimer = 0;
    return ::findLast(array, currItemCount, numToFind, nulltimer);
}

