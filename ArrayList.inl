//
// Created by Alex Python on 10/10/17.
//

#include <iostream>
#include "ArrayList.h"

/**
 * Constructor for ArrayList
 * @param initialCapacity
 */
template <class T>
ArrayList<T>::ArrayList(int initialCapacity) {
    array = new T[initialCapacity];
    currItemCount = 0;
    currCapacity = initialCapacity;
}

/**
 * Copy constructor for ArrayList
 * @param arrayListToCopy
 */
template <class T>
ArrayList<T>::ArrayList(const ArrayList<T> &arrayListToCopy) {
    array = new T[arrayListToCopy.currCapacity];
    currItemCount = arrayListToCopy.currItemCount;
    currCapacity = arrayListToCopy.currCapacity;
    for (int i=0; i < currItemCount; i++) {
        array[i] = arrayListToCopy.array[i] ;
    }
}

//Overloaded Assignment Operator
template <class T>
ArrayList<T>& ArrayList<T>::operator=(const ArrayList<T> &arrayListToCopy) {
    if (this != &arrayListToCopy) {
        delete[] array;
        array = nullptr;
        array = new T[arrayListToCopy.currCapacity];
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
template <class T>
ArrayList<T>::~ArrayList() {
    delete[] array;
    array = nullptr;
}

/**
 * generates a copy of a given array
 * @param arrayToCopy
 * @param size
 * @return a pointer to the copy array, which must be deleted by the user
 */
template <class T>
T* copyArray(const T* arrayToCopy, const int size) {
    int* copy = new int[size];
    for (int i = 0; i<size; i++) {
        copy[i] = arrayToCopy[i];
    }
    return copy;
}


/**
     * replaces the old array with an array twice the size
     * private method only called within ArrayList when necessary
     * @post: array points to a new array of twice the size with values copied from the old one,
     *        the old array is deleted.
*/
template <class T>
void ArrayList<T>::doubleCapacity() {
    T* original = copyArray(array, currItemCount);
    delete[] array;
    array = new T[currCapacity * 2];
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
template <class T>
void ArrayList<T>::insertAtEnd(T itemToAdd) {
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
template <class T>
void ArrayList<T>::insertAtFront(T itemToAdd) {
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
template <class T>
void ArrayList<T>::insertAt(T itemToAdd, int index) {
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
        currItemCount++;
        return;
    }
}

/**
 * gets a value from the list
 * @param index the location from which to get the value
 * @returns a copy of the item at index
 * @throws out_of_range exception if index is invalid
 */
template <class T>
T ArrayList<T>::getValueAt(int index) {
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
template <class T>
T ArrayList<T>::removeValueAt(int index) {
    if (index<0 || index>= currItemCount) {
        throw std::out_of_range("Index Out of Bounds");
    } else {
        T beingRemoved = array[index];
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
template <class T>
bool ArrayList<T>::isEmpty() {
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
template <class T>
int ArrayList<T>::itemCount() {
    return currItemCount;
}

/**
 * removes all valid items from the list
 * @post the list is completely clear of valid items
 */
template <class T>
void ArrayList<T>::clearList() {
    currItemCount = 0;
}

/**
 * creates a string version of an array for easy printing
 * @param arrayPtr
 * @param size
 * @return a string representing the given array in the exact format shown below
 */
template <class T>
std::string ArrayList<T>::toString() {
    //TODO
    std::string arrayStringify = "{";
    for (int i=0; i<currItemCount; i++) {
        arrayStringify += std::to_string(array[i]);
        if (i != currItemCount-1) {
            arrayStringify += ", ";
        }
    }
    arrayStringify += "}";
    return arrayStringify;
}

/**
 * Searches an array for a certain value
 * @return the index of the first occurrence of numToFind if it is present, otherwise returns -1
 */
template <class T>
int ArrayList<T>::find(T toFind) {
    if (currItemCount == 0) {
        return -1;
    }
    for (int i = 0; i < currItemCount; i++) {
        if (array[i] == toFind) {
            return i;
        }
    }
    return -1;
}

/**
 * Searches an array for a certain value
 * @return the index of the last occurrence of numToFind if it is present, otherwise returns -1
 */
template <class T>
int ArrayList<T>::findLast(T toFind) {
    int lastIndex = -1;
    if (currItemCount == 0) {
        return -1;
    }
    for (int i = 0; i < currItemCount; i++) {
        if (array[i] == toFind) {
            lastIndex = i;
        }
    }
    return lastIndex;
}

