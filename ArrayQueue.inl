//
// Created by Toby Dragon on 10/27/17.
//

#include "ArrayQueue.h"

//Creates an empty queue
template <class T>
ArrayQueue<T>::ArrayQueue(){
    capacity = 50;
    currItemCount = 0;
    qArray = new T[capacity];
}

//adds an item to the end of the queue
template <class T>
void ArrayQueue<T>::enqueue(T item){
    if (currItemCount >= capacity){
        throw std::out_of_range("Too many items in queue");
    }
    else {
        qArray[currItemCount] = item;
        currItemCount++;
    }
}

//takes an item off the front of the queue and returns it
//throws out_of_range exception if the queue is empty
template <class T>
T ArrayQueue<T>::dequeue(){
    T toReturn = qArray[0];
    for(int i=0; i<currItemCount-1; i++){
        qArray[i] = qArray[i+1];
    }
    currItemCount--;
    return toReturn;
}

//returns true if the queue has no items, false otherwise
template <class T>
bool ArrayQueue<T>::isEmpty(){
    return currItemCount==0;
}
