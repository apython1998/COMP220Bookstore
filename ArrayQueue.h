//
// Created by Toby Dragon on 10/27/17.
//

#ifndef INC_220_24_STACKSANDQUEUES_ARRAYQUEUE_H
#define INC_220_24_STACKSANDQUEUES_ARRAYQUEUE_H

#include <string>
#include "Queue.h"

template <class T>
class ArrayQueue : public Queue<T> {
private:
    T* qArray;
    int capacity;
    int currItemCount;

public:
    //Creates an empty queue
    ArrayQueue();

    //adds an item to the end of the queue
    void enqueue(T item);

    //takes an item off the front of the queue and returns it
    //throws out_of_range exception if the queue is empty
    T dequeue();

    //returns true if the queue has no items, false otherwise
    bool isEmpty();


};

#include "ArrayQueue.inl"


#endif //INC_220_24_STACKSANDQUEUES_ARRAYQUEUE_H
