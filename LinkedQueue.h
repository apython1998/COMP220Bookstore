//
// Created by Toby Dragon on 10/22/17.
// Modified on 11/14/17.
//

#ifndef STACKSANDQUEUES_LINKED_QUEUE_H
#define STACKSANDQUEUES_LINKED_QUEUE_H

#include <string>
#include <stdexcept>
#include "LinkedNode.h"
#include "Queue.h"


/**
 * Represents a FIFO data structure (First In First Out). Picture a line
 * to wait for something (first person in is the first person out)
 */
template <class T>
class LinkedQueue : public Queue<T> {
private:
    LinkedNode<T>* front;
    LinkedNode<T>* end;
public:
    class LinkedQueueIterator: public Queue<T>::QueueIterator{
    public:
        // Explicit choice to not include a destructor
        // since the iterator does not own the linkedlist
        LinkedNode<T>* pos;
        bool hasNext(){
            return pos!=nullptr;
        }
        T getNext(){
            T t = pos->getItem();
            pos=pos->getNext();
            return t;
        }
        LinkedQueueIterator(LinkedNode<T>* pos){
            this->pos=pos;
        }
    };

    //Creates an empty queue
    LinkedQueue();

    //Copy Constructor
    LinkedQueue(const LinkedQueue<T>& queueToCopy);

    //Destructor
    ~LinkedQueue();

    LinkedQueue& operator=(const LinkedQueue<T>& LinkedQueueToCopy);
    
    //adds an item to the end of the queue
    void enqueue(T item);

    //takes an item off the front of the queue and returns it
    //throws out_of_range exception if the queue is empty
    T dequeue();

    //returns true if the queue has no items, false otherwise
    bool isEmpty();

    typename Queue<T>::QueueIterator* getIterator() override;
};

#include "LinkedQueue.inl"

#endif //STACKSANDQUEUES_LINKED_QUEUE_H
