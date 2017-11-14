//
// Created by Alex Python on 10/31/17.
//

#include <string>
#include "LinkedNode.h"
#include "LinkedList.h"

/**
 * constructor
 * O(1)
 */
IntLinkedList::IntLinkedList() {
    size = 0;
    front = nullptr;
    end = nullptr;
}

/**
 * copy constructor, O(n)
 * @param intLinkedListToCopy
 */
IntLinkedList::IntLinkedList(const IntLinkedList &intLinkedListToCopy) {
    size = intLinkedListToCopy.size;
    front = nullptr;
    end = nullptr;
    LinkedNode* current = intLinkedListToCopy.front;
    while (current != nullptr) {
        LinkedNode* newNode = new LinkedNode(*current);
        if (front == nullptr){
            front = newNode;
            end = newNode;
        } else {
            end->setNext(newNode);
            end = newNode;
        }
        current = (*current).getNext();
    }
}

void cleanupIntLinkedList(LinkedNode* current) {
    if (current == nullptr) {
        return;
    } else {
        cleanupIntLinkedList((*current).getNext());
        delete current;
    }
}

//Destructor, O(n)
IntLinkedList::~IntLinkedList(){
    cleanupIntLinkedList(front);
    front = nullptr;
    end = nullptr;
}

/**
 * Assignment operator, O(n) because it runs through once in cleanup and again to copy
 * @param intLinkedListToCopy
 * @return
 */
IntLinkedList& IntLinkedList::operator=(const IntLinkedList& intLinkedListToCopy) {
    if (this != &intLinkedListToCopy) {
        cleanupIntLinkedList(front);
        front = nullptr;
        end = nullptr;
        size = intLinkedListToCopy.size;
        LinkedNode* current = intLinkedListToCopy.front;
        while (current != nullptr) {
            LinkedNode* newNode = new LinkedNode(*current);
            if (front == nullptr){
                front = newNode;
                end = newNode;
            } else {
                end->setNext(newNode);
                end = newNode;
            }
            current = (*current).getNext();
        }
    }
    return *this;
}

/**
 * insertAtEnd, O(1)
 * @param itemToAdd
 */
void IntLinkedList::insertAtEnd(int itemToAdd) {
    LinkedNode* newNode = new LinkedNode(itemToAdd);
    if (size == 0) {
        front = newNode;
        end = newNode;
    } else {
        end->setNext(newNode);
        end = newNode;
    }
    size++;
}

/**
 * insertAtFront, O(1)
 * @param itemToAdd
 */
void IntLinkedList::insertAtFront(int itemToAdd) {
    LinkedNode* newNode = new LinkedNode(itemToAdd);
    newNode->setNext(front);
    front = newNode;
    if (end == nullptr) {
        end = newNode;
    }
    size++;
}

/**
 * insertAt, worst case is O(n), so O(n)
 * @param itemToAdd
 * @param index
 */
void IntLinkedList::insertAt(int itemToAdd, int index) {
    if (index <0 || index > size){
        throw std::out_of_range("INDEX OUT OF BOUNDS");
    } else {
        if (index == 0) {
            insertAtFront(itemToAdd);
        } else if (index == size) {
            insertAtEnd(itemToAdd);
        } else {
            LinkedNode* newNode = new LinkedNode(itemToAdd);
            int count = 0;
            LinkedNode* last = nullptr;
            LinkedNode* current = front;
            while (count != index) {
                count++;

                last = current;
                current = current->getNext();
            }
            newNode->setNext(current);
            last->setNext(newNode);
            size++;
        }
    }
}

/**
 * getValueAt, O(n)
 * @param index
 * @return value at index
 */
int IntLinkedList::getValueAt(int index) {
    if (index <0 || index > (size-1)){
        throw std::out_of_range("INDEX OUT OF BOUNDS");
    } else {
        int count = 0;
        LinkedNode* current = front;
        while (count != index) {
            count++;
            current = current -> getNext();
        }
        return current->getItem();
    }
}

/**
 * removeValueAt, O(n)
 * @param index
 * @return item that you are removing
 */
int IntLinkedList::removeValueAt(int index) {
    if (index <0 || index > (size-1)){
        throw std::out_of_range("INDEX OUT OF BOUNDS");
    } else {
        if (index == 0) {
            LinkedNode* toRemove = front;
            int toReturn = toRemove->getItem();
            front = toRemove->getNext();
            delete toRemove;
            size--;
            if (size == 0) {
                end = nullptr;
            }
            return toReturn;
        } else {
            int count = 0;
            LinkedNode *last = nullptr;
            LinkedNode *toRemove = front;
            while (count != index) {
                count++;
                last = toRemove;
                toRemove = toRemove->getNext();
            }
            int toReturn = toRemove->getItem();
            last->setNext(toRemove->getNext());
            delete toRemove;
            if (index == size-1) {
                end = last;
            }
            size--;
            return toReturn;
        }
    }
}

/**
 * isEmpty, O(1)
 * @return true if its empty, otherwise false
 */
bool IntLinkedList::isEmpty() {
    return (front==nullptr && end==nullptr);
}

/**
 * itemCount, O(1)
 * @return number of items
 */
int IntLinkedList::itemCount() {
    return size;
}

/**
 * clearList, O(1)
 */
void IntLinkedList::clearList() {
    cleanupIntLinkedList(front);
    front = nullptr;
    end = nullptr;
    size = 0;
}

/**
 * toString, O(n)
 * @return list as a string
 */
std::string IntLinkedList::toString() {
    std::string listString = "{";
    LinkedNode* current = front;
    for (int i=0; i<size; i++) {
        if (i != size-1) {
            listString += std::to_string(current->getItem()) + ", ";
        } else {
            listString += std::to_string(current->getItem());
        }
        current = current->getNext();
    }
    listString += "}";
    return listString;
}

/**
 * findMaxIndex, O(n)
 * @return first index of max or -1
 */
int IntLinkedList::findMaxIndex() {
    if (size<1) {
        return -1;
    }
    else {
        int maxIndex = 0;
        int currentIndex = 0;
        LinkedNode* current = front;
        int maxItem = current->getItem();
        while (currentIndex < size) {
            if (current->getItem() > maxItem) {
                maxIndex = currentIndex;
                maxItem = current->getItem();
            }
            currentIndex++;
            current = current->getNext();
        }
        return maxIndex;
    }
}

/**
 * find, O(n)
 * @param numToFind
 * @return first index of numToFind, or -1 if num is not in list
 */
int IntLinkedList::find(int numToFind) {
    int currentIndex = 0;
    LinkedNode* current = front;
    while (currentIndex < size) {
        if (current->getItem() == numToFind) {
            return currentIndex;
        } else {
            currentIndex++;
            current = current->getNext();
        }
    }
    return -1;
}

/**
 * findLast, O(n)
 * @param numToFind
 * @return last index of numToFind, or -1 if num is not in list
 */
int IntLinkedList::findLast(int numToFind) {
    int indexOfNum = -1;
    int currentIndex = 0;
    LinkedNode* current = front;
    while (currentIndex < size) {
        if (current->getItem() == numToFind) {
            indexOfNum = currentIndex;
        }
        currentIndex++;
        current = current->getNext();
    }
    return indexOfNum;
}