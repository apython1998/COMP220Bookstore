//
// Created by Alex Python on 10/3/17.
//

#include <iostream>
#include "ArrayLib.h"

/**
 * creates a string version of an int array for easy printing
 * @param arrayPtr
 * @param size
 * @return a string representing the given array in the exact format shown below
 *  {1, 2, 3, 4, 5}
 *  {} for size < 1
 */
std::string toString(const int* arrayPtr, int size) {
    std::string arrayStringify = "{";
    for (int i=0; i<size; i++) {
        arrayStringify += std::to_string(arrayPtr[i]);
        if (i != size-1) {
            arrayStringify += ", ";
        }
    }
    arrayStringify += "}";
    return arrayStringify;
}

/**
 * finds the largest value in the array
 * @param arrayPtr
 * @param size
 * @param numLinesRun
 * @return the index of the maximum value or -1 if size<1
 */
int findMaxIndex(const int* arrayPtr, int size, int& numLinesRun) {
    (numLinesRun) += 4; //params and if
    if (size < 1) {
        (numLinesRun)++;
        return -1;
    }
    (numLinesRun) += 3; //start for loop and int
    int maxIndex = 0;
    for (int i=0; i < size; i++) {
        (numLinesRun)++; //if
        if (arrayPtr[i] > arrayPtr[maxIndex]) {
            (numLinesRun)++;
            maxIndex = i;
        }
        (numLinesRun) += 2; //for loop increment and check
    }
    (numLinesRun)++;
    return maxIndex;
}

/**
 * Searches an int array for a certain value
 * @param arrayPtr
 * @param size
 * @param numToFind
 * @return the index of the first occurrence of numToFind if it is present, otherwise returns -1
 */
int find(const int* arrayPtr, int size, int numToFind, int& numLinesRun) {
    (numLinesRun) += 5; //params and if
    if (size == 0) {
        (numLinesRun)++;
        return -1;
    }
    (numLinesRun) += 2; //start for loop
    for (int i = 0; i < size; i++) {
        (numLinesRun)++;
        if (arrayPtr[i] == numToFind) {
            (numLinesRun)++; //return
            return i;
        }
        (numLinesRun) += 2; //for loop increment and check
    }
    (numLinesRun)++;
    return -1;
}

/**
 * Searches an int array for a certain value
 * @param arrayPtr
 * @param size
 * @param numToFind
 * @return the index of the last occurrence of numToFind if it is present, otherwise returns -1
 */
int findLast(const int* arrayPtr, int size, int numToFind, int& numLinesRun) {
    (numLinesRun) += 6; //params and next two lines
    int lastIndex = -1;
    if (size == 0) {
        (numLinesRun)++;
        return -1;
    }
    (numLinesRun) += 2; //start for loop
    for (int i = 0; i < size; i++) {
        (numLinesRun)++;
        if (arrayPtr[i] == numToFind) {
            (numLinesRun)++;
            lastIndex = i;
        }
        (numLinesRun) += 2; //for loop increment and check
    }
    (numLinesRun)++;
    return lastIndex;
}

/**
 * TAIL RECURSION
 * recursion for binary search
 * @param arrayPtr
 * @param size
 * @param numToFind
 * @param min
 * @param max
 * @param numLinesRun
 * @return
 */
int binFind(const int* const arrayPtr, const int numToFind, const int min, const int max, int& numLinesRun){
    (numLinesRun) += 7; //params and if
    if (min<=max) {
        (numLinesRun) += 2; //initialize and if
        const int middle = (min + max) / 2;
        if (arrayPtr[middle] == numToFind) {
            (numLinesRun)++; //return
            return middle;
        } else if (arrayPtr[middle] < numToFind) {
            (numLinesRun) += 2; //if and return
            return binFind(arrayPtr, numToFind, middle + 1, max, numLinesRun);
        } else {
            (numLinesRun)++; //return
            return binFind(arrayPtr, numToFind, min, middle - 1, numLinesRun);
        }
    }
    (numLinesRun)++; //return
    return -1;
}

/**
 * uses binary search on an int array for a certain value
 * @pre the array must be sorted before this function is called
 * @param numLinesRun
 * @param arrayPtr
 * @param numToFind
 * @param size
 * @return the index of the first occurrence of numToFind if it is present, otherwise returns -1
 */
int binFind(const int* const arrayPtr, const int size, const int numToFind, int& numLinesRun){
    (numLinesRun) += 5; //params and if
    if (size < 1) {
        (numLinesRun)++; //return
        return -1;
    } else {
        (numLinesRun)++; //return
        return binFind(arrayPtr, numToFind, 0, size-1, numLinesRun);
    }
}

/**
 * Generates a random number, border cases allowed
 * @param min
 * @param max
 * @return -1 if min>max, otherwise, a random number between min and max
 */
int genRandInt(int min, int max, int& numLinesRun) {
    (numLinesRun) += 4; //params and if
    if (min > max) {
        (numLinesRun)++;
        return -1;
    } else if (max == min) {
        (numLinesRun) += 2;
        return min;
    }
    (numLinesRun) += 3; // last 3 lines
    int adjustedRange = (max + 1) - min;
    int randomNum = (rand() % adjustedRange) + min;
    return randomNum;
}

/**
 * generates an array filled with random numbers, values between min and max inclusive
 * If min > max, it switches min and max values to make them valid
 * @param size
 * @param min
 * @param max
 * @return pointer to an array
 */
int* genRandArray(int size, int min, int max, int& numLinesRun) {
    (numLinesRun) += 5; //4 params and initialize array
    int* randArray = new int[size];
    (numLinesRun) += 2; //start for loop
    for (int i=0; i<size; i++) {
        randArray[i] = genRandInt(min, max, numLinesRun);
        (numLinesRun) += 3; //inner for loop
    }
    (numLinesRun)++; //return
    return randArray;
}

/**
 * generates an array with values 1 through size, shuffled in random order
 * example: genShuffledArray(5) might yield {2, 1, 4, 5, 3}
 * @param size
 * @return
 */
int* genShuffledArray(int size, int& numLinesRun) {
    (numLinesRun) += 3; //params and if
    if (size == 0) {
        (numLinesRun)++; //return
        return {};
    }
    int* unshuffled = new int[size];
    (numLinesRun) += 3; //initialize unshuffled and start for loop
    for (int i=0; i<size; i++) {
        unshuffled[i] = i+1;
        (numLinesRun) += 3; //inner for loop
    }
    (numLinesRun) += 3; //next two lines and start while loop
    int* shuffled = new int[size];
    int count = 0; //using to tell if shuffled is complete
    while (count != size) {
        (numLinesRun) += 2;
        int index = genRandInt(0, size-1, numLinesRun);
        if (unshuffled[index] != -1) {
            shuffled[count] = unshuffled[index];
            unshuffled[index] = -1;
            count++;
            (numLinesRun) += 3;
        }
    }
    (numLinesRun) += 3; //last 2 and return
    delete[] unshuffled;
    unshuffled = nullptr;
    return shuffled;
}

/**
 * generates a copy of a given array
 * @param arrayToCopy
 * @param size
 * @return a pointer to the copy array, which must be deleted by the user
 */
int* copyArray(const int* arrayToCopy, const int size, int& numLinesRun) {
    (numLinesRun) += 6; //params, initialize copy, and start for loop
    int* copy = new int[size];
    for (int i = 0; i<size; i++) {
        copy[i] = arrayToCopy[i];
        (numLinesRun) += 3; //inner for loop
    }
    (numLinesRun)++;
    return copy;
}

/**
 * sorts the array using SELECTION sort algorithm
 * @param arrayToSort
 * @param size
 * @param numLinesRun
 */
void sort(int* arrayToSort, int size, int& numLinesRun) {
    (numLinesRun) += 5; //params and start for loop
    for (int i=0 ; i< size-1; i++) {
        (numLinesRun) += 3; //int and start for loop
        int minIndex = i;
        for (int j=i ; j<size ; j++) {
            (numLinesRun)++; //if
            if (arrayToSort[j] < arrayToSort[minIndex]) {
                (numLinesRun)++;
                minIndex = j;
            }
            (numLinesRun) += 2; //for loop increment and check
        }
        int temp = arrayToSort[i];
        arrayToSort[i] = arrayToSort[minIndex];
        arrayToSort[minIndex] = temp;
        (numLinesRun) += 5; //above 3 lines and for loop increment and check
    }
}

/**
 * returns an array that is a sorted, merged copy of arrays a1 and a2
 * Operates in O(n), linear time
 * @pre both a1 and a2 must be sorted
 * @post numLinesRun is updated to include lines run by this function
 * @return an array of size (size1+size2) that is an in-order (sorted) copy of all values from a1 and a2,
 * or nullptr if (size1+size2) < 1
 */
int* merge(const int*a1, int size1, const int* a2, int size2, int& numLinesRun) {
    numLinesRun += 10; //params, 2 lines, for loop start
    int* merged = new int[size1 + size2];
    int count1 = 0, count2 = 0;
    for (int i=0 ; i<size1+size2 ; i++) {
        numLinesRun++; //if
        if (count1 >= size1) {
            numLinesRun += 2;
            merged[i] = a2[count2];
            count2++;
        } else if (count2 >= size2) {
            numLinesRun += 3; //if and below two lines
            merged[i] = a1[count1];
            count1++;
        } else {
            numLinesRun++; //if
            if (a1[count1] <= a2[count2]) {
                numLinesRun += 2;
                merged[i] = a1[count1];
                count1++;
            } else {
                numLinesRun += 2;
                merged[i] = a2[count2];
                count2++;
            }
        }
        numLinesRun += 2; //for loop increment and check
    }
    return merged;
}

/**
 * recursive function call for merge sort
 * @param arrayToSort
 * @param size
 * @param min
 * @param max
 * @param numLinesRun
 * @return
 */
int* mergeSort(const int* arrayToSort, int size, int min, int max, int& numLinesRun) {
    numLinesRun += 6; //params and if
    if (min == max) {
        numLinesRun++; //return
        return copyArray(arrayToSort+min, 1, numLinesRun);
    } else {
        numLinesRun += 9;
        int mid = (min+max)/2;
        int size1 = (mid-min)+1;
        int size2 = (max-mid);
        int* firstHalf = mergeSort(arrayToSort, size1, min, mid, numLinesRun);
        int* secondHalf = mergeSort(arrayToSort, size2, mid+1, max, numLinesRun);
        int* merged = merge(firstHalf, size1, secondHalf, size2, numLinesRun);
        delete[] firstHalf;
        delete[] secondHalf;
        return merged;
    }
}

/**
 * returns a sorted copy of the array using merge sort
 * @post numLinesRun is updated to include lines run by this function
 * @return a copy of the array sorted from min to max values, or nullptr if size < 1
 */
int* mergeSort(const int* arrayToSort, int size, int& numLinesRun) {
    numLinesRun += 4; //params and if
    if (size<1) {
        numLinesRun++; //return
        return nullptr;
    } else {
        numLinesRun++; //return
        return mergeSort(arrayToSort, size, 0, size-1, numLinesRun);
    }
}
