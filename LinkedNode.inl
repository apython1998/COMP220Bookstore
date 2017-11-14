//
// Created by Toby Dragon on 10/17/17.
//
#include "LinkedNode.h"

template <class T>
LinkedNode::LinkedNode(T item){
    this->item = item;
    next = nullptr;
}

template <class T>
LinkedNode::LinkedNode(const LinkedNode& nodeToCopy){
    item = nodeToCopy.item;
    next = nullptr;
}

template <class T>
T LinkedNode::getItem(){
    return item;
}

template <class T>
LinkedNode* LinkedNode::getNext(){
    return next;
}

template <class T>
void LinkedNode::setItem(T newItem){
    item = newItem;
}

template <class T>
void LinkedNode::setNext(LinkedNode* newNext){
    next = newNext;
}
