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
LinkedList::LinkedList() {
    size = 0;
    front = nullptr;
    end = nullptr;
}

/**
 * copy constructor, O(n)
 * @param LinkedListToCopy
 */
LinkedList::LinkedList(const LinkedList &LinkedListToCopy) {
    size = LinkedListToCopy.size;
    front = nullptr;
    end = nullptr;
    LinkedNode* current = LinkedListToCopy.front;
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

void cleanupLinkedList(LinkedNode* current) {
    if (current == nullptr) {
        return;
    } else {
        cleanupLinkedList((*current).getNext());
        delete current;
    }
}

//Destructor, O(n)
LinkedList::~LinkedList(){
    cleanupLinkedList(front);
    front = nullptr;
    end = nullptr;
}

/**
 * Assignment operator, O(n) because it runs through once in cleanup and again to copy
 * @param LinkedListToCopy
 * @return
 */
LinkedList& LinkedList::operator=(const LinkedList& LinkedListToCopy) {
    if (this != &LinkedListToCopy) {
        cleanupLinkedList(front);
        front = nullptr;
        end = nullptr;
        size = LinkedListToCopy.size;
        LinkedNode* current = LinkedListToCopy.front;
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
void LinkedList::insertAtEnd(int itemToAdd) {
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
void LinkedList::insertAtFront(int itemToAdd) {
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
void LinkedList::insertAt(int itemToAdd, int index) {
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
int LinkedList::getValueAt(int index) {
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
int LinkedList::removeValueAt(int index) {
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
bool LinkedList::isEmpty() {
    return (front==nullptr && end==nullptr);
}

/**
 * itemCount, O(1)
 * @return number of items
 */
int LinkedList::itemCount() {
    return size;
}

/**
 * clearList, O(1)
 */
void LinkedList::clearList() {
    cleanupLinkedList(front);
    front = nullptr;
    end = nullptr;
    size = 0;
}

/**
 * toString, O(n)
 * @return list as a string
 */
std::string LinkedList::toString() {
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
int LinkedList::findMaxIndex() {
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
int LinkedList::find(int numToFind) {
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
int LinkedList::findLast(int numToFind) {
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