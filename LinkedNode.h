//
// Created by Toby Dragon on 10/24/16.
// Modified on 11/14/17.
//

#ifndef LINKEDNODE_H
#define LINKEDNODE_H

template <class T>
class LinkedNode {

private:
    T item;
    LinkedNode* next;

public:
    LinkedNode(T item); //constructor
    LinkedNode(const LinkedNode& nodeToCopy); //only copies item, next is set to nullptr
    T getItem(); //returns item in the node
    LinkedNode* getNext(); //returns the pointer to next
    void setItem(T newItem); //sets the item to a new item
    void setNext(LinkedNode* newNext); //sets next to a pointer given
};

#include "LinkedNode.inl"
#endif //LINKEDNODE_H
