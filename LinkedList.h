//
// Created by Alex Python on 10/31/17.
//

#ifndef LAB08_LINKEDLIST_H
#define LAB08_LINKEDLIST_H

#include <stdexcept>
#include "LinkedNode.h"
#include "List.h"

template <class T>
class LinkedList : public List<T> {
private:
    int size;
    LinkedNode<T>* front;
    LinkedNode<T>* end;

public:
    //O(1)
    LinkedList();
    //O(n)
    LinkedList(const LinkedList& LinkedListToCopy);
    //O(n)
    ~LinkedList();
    //O(n) because it runs through once in cleanup, and once in copying over
    LinkedList& operator=(const LinkedList& LinkedListToCopy);

    /**
     * O(1)
     * appends the new item to the end of the list
     * @param itemToAdd the item to add to the end of the array
     * @post the list has an additional value in it, at the end
     */
    void insertAtEnd(T itemToAdd);

    /**
     * O(1)
     * appends the new item to the beginning of the list
     * @param itemToAdd the item to add to the beginning of the list
     * @post the list has an additional value in it, at the beginning
     *    all other items are shifted down by one index
     */
    void insertAtFront(T itemToAdd);

    /**
     * O(n)
     * inserts the item into the list so that it can be found with get(index)
     * @param itemToAdd the item to add
     * @param index the location in which to insert this item
     * @post the list has an additional value in it at the specified index,
     *        all further values have been shifted down by one index
     * @throws out_of_range exception if index is invalid (< 0 or >currItemCount)
     */
    void insertAt(T itemToAdd, int index);

    /**
     * O(n)
     * gets a value from the list
     * @param index the location from which to get the value
     * @returns a copy of the item at index
     * @throws out_of_range exception if index is invalid
     */
    T getValueAt(int index);

    /**
     * O(n)
     * removes the item at index from the list, and returns a copy of that item
     * @param index the location from which to get the value
     * @post the item at index is removed from the list, everything else is shifted down one
     * @returns a copy of the item at index
     * @throws out_of_range exception if index is invalid
     */
    T removeValueAt(int index);

    /**
     * O(1)
     * checks if there are any valid items in the list
     * @returns true if there are no valid items in the list, false otherwise
     */
    bool isEmpty();

    /**
     * O(1)
     * returns a count of valid items currently in the list
     * @returns the number of valid items in the list
     */
    int itemCount();

    /**
     * O(1)
     * removes all valid items from the list
     * @post the list is completely clear of valid items
     */
    void clearList();

    /**
     * O(n)
     * gives a string representation of the current list
     * @returns a string representing the given list in the exact format shown below
     * {1, 2, 3, 4, 5}
     */
    std::string toString();

//    /**
//     * O(n)
//     * finds the largest value in the array
//     * @return the first index of the maximum value, or -1 if size < 1
//     */
//    int findMaxIndex();

    /**
     * O(n)
     * Searches an int array for a certain value
     * @return the index of the first occurrence of numToFind if it is present, otherwise returns -1
     */
    int find(T numToFind);

    /**
     * O(n)
     * Searches an int array for a certain value
     * @return the index of the last occurrence of numToFind if it is present, otherwise returns -1
     */
    int findLast(T numToFind);
};

#include "LinkedList.inl"

#endif //LAB08_LINKEDLIST_H
