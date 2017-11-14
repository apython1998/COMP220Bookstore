//
// Created by Toby Dragon on 10/24/16.
//

#ifndef LINKEDNODE_H
#define LINKEDNODE_H

class LinkedNode {

private:
    int item;
    LinkedNode* next;

public:
    LinkedNode(int item);
    LinkedNode(const LinkedNode& nodeToCopy); //only copies item, next is set to nullptr
    int getItem();
    LinkedNode* getNext();
    void setItem(int newItem);
    void setNext(LinkedNode* newNext);
};


#endif //LINKEDNODE_H
