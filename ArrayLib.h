//
// Created by Toby Dragon on 8/26/17.
//

#ifndef COMP220LAB_ARRAYLIB_H
#define COMP220LAB_ARRAYLIB_H

#include <string>

/**
 * creates a string version of an int array for easy printing
 * @return a string representing the given array in the exact format shown below
 *  {1, 2, 3, 4, 5}
 *  {} for size < 1
 */
std::string toString(const int* arrayPtr, int size);

/**
 * finds the largest value in the array
 * @post numLinesRun is updated to include lines run by this function
 * @return the first index of the maximum value, or -1 if size < 1
 */
int findMaxIndex(const int* arrayPtr, int size, int& numLinesRun);

/**
 * Searches an int array for a certain value
 * @post numLinesRun is updated to include lines run by this function
 * @return the index of the first occurrence of numToFind if it is present, otherwise returns -1
 */
int find(const int* arrayPtr, int size, int numToFind, int& numLinesRun);

/**
 * Searches an int array for a certain value
 * @post numLinesRun is updated to include lines run by this function
 * @return the index of the last occurrence of numToFind if it is present, otherwise returns -1
 */
int findLast(const int* arrayPtr, int size, int numToFind, int& numLinesRun);

/**
 * uses binary search on an int array for a certain value
 * @pre the array must be sorted before this function is called
 * @post numLinesRun is updated to include lines run by this function
 * @return the index of the first occurrence of numToFind if it is present, otherwise returns -1
 */
int binFind(const int* arrayPtr, int size, int numToFind, int& numLinesRun);

/**
 * generates a random integer
 * @pre the function srand() must be called once before this function is used the first time
 * @post numLinesRun is updated to include lines run by this function
 * @return an integer between min and max inclusive (including both min and max),
 *         unless min is greater than max, then prints error and returns -1
 */
int genRandInt(int min, int max, int& numLinesRun);


/**
 * generates an array filled with random numbers, values between min and max inclusive
 * If min > max, it switches min and max values to make them valid
 * @pre the function srand() must be called once before this function is used the first time
 * @post numLinesRun is updated to include lines run by this function
 * @return a pointer to the array, which must be deleted by the user
 */
int* genRandArray(int size, int min, int max, int& numLinesRun);

/**
 * generates an array with values 1 through size, shuffled in random order
 * example: genShuffledArray(5) might yield {2, 1, 4, 5, 3}
 * @pre srand must be called once before this function is used the first time
 * @post numLinesRun is updated to include lines run by this function
 * @return a pointer to the array, which must be deleted by the user,
 *          returns nullptr if size < 1
 */
int* genShuffledArray(int size, int& numLinesRun);

/**
 * generates a copy of a given array
 * @return a pointer to the copy array, which must be deleted by the user
 */
int* copyArray(const int* arrayToCopy, int size, int& numLinesRun);

/**
 * sorts the array
 * @post numLinesRun is updated to include lines run by this function
 * @post the array is sorted from min to max values
 */
void sort(int* arrayToSort, int size, int& numLinesRun);


/**
 * returns an array that is a sorted, merged copy of arrays a1 and a2
 * Operates in O(n), linear time
 * @pre both a1 and a2 must be sorted
 * @post numLinesRun is updated to include lines run by this function
 * @return an array of size (size1+size2) that is an in-order (sorted) copy of all values from a1 and a2,
 * or nullptr if (size1+size2) < 1
 */
int* merge(const int*a1, int size1, const int* a2, int size2, int& numLinesRun);

/**
 * returns a sorted copy of the array using merge sort
 * @post numLinesRun is updated to include lines run by this function
 * @return a copy of the array sorted from min to max values, or nullptr if size < 1
 */
int* mergeSort(const int* arrayToSort, int size, int& numLinesRun);


#endif //COMP220LAB_ARRAYLIB_H
