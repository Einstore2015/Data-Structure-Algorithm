#ifndef _NEW_ARRAY_QUEUE_H
#define _NEW_ARRAY_QUEUE_H

#include "queue.h"
#include "..\exception\myExceptions.h"

#include <iostream>
#include <sstream>

template <typename T>
class newQueue : public queue<T>
{
public:
    newQueue( int initialCap = 10 );
    ~newQueue();

    bool isEmpty() const;
    int  size() const;
    T&   front();
    T&   back();
    void pop();
    void push( const T& theElement );
    void output( std::ostream &os ) const;
protected:
    int theFront;
    int queueSize;
    int arrayLength;
    T*  queue;
};

/* 
 *  Constructor
 */
template <typename T>
newQueue<T>::newQueue( int initialCap )
{
    if ( initialCap < 1 ){
        std::ostringstream s;
        s << "Initial capacity = " << initialCap << " Must be > 0";
        throw illegalParameterValue(s.str());
    }
    arrayLength = initialCap;
    queue = new T[arrayLength];
    theFront = 0; queueSize = 0;
}

/* 
 *  
 */
template <typename T>
newQueue<T>::~newQueue()
{
    delete[] queue;
}

/* 
 *  If queue is empty --> true
 */
template <typename T>
bool newQueue<T>::isEmpty() const
{
    return ( queueSize==0 ? true : false );
}

/* 
 *  Return the number of queue elements
 */
template <typename T>
int newQueue<T>::size() const
{
    return queueSize;
}

/* 
 *  Return the reference of queue's front
 */
template <typename T>
T& newQueue<T>::front()
{
    return queue[theFront % arrayLength];
}

/* 
 *  Return the reference of queue's tail
 */
template <typename T>
T& newQueue<T>::back()
{
    return queue[(theFront + queueSize - 1) % arrayLength];
}

/* 
 *  
 */
template <typename T>
void newQueue<T>::pop()
{
    if (isEmpty()){
        throw queueEmpty();
    }

    queue[theFront].~T();
    theFront++;
    queueSize--;
}

/* 
 *  
 */
template <typename T>
void newQueue<T>::push( const T& theElement )
{
    // increase array length if necessary
    if (queueSize == arrayLength){
        T* newQueue = new T[2*arrayLength];
        // copy
        if (theFront == 0){
            // consistent
            std::copy(queue, queue+queueSize, newQueue);
        }else{
            // 
            std::copy(queue + (theFront % arrayLength), queue+arrayLength, newQueue);
            std::copy(queue, queue + (theFront & arrayLength), newQueue+queueSize);
        }

        arrayLength *=2;
        theFront = 0;
        delete[] queue;
        queue = newQueue;
    }

    queue[ (theFront + queueSize) % arrayLength ] = theElement;
    queueSize++;
}

/* 
 *  
 */
template <typename T>
void newQueue<T>::output( std::ostream &os ) const
{
    if (isEmpty()){
        os << "Empty queue" << std::endl;
        return;
    }

    os << "Queue elements: ";
    for ( int i=0; i < queueSize; i++ ){
        os << queue[(theFront + i) % arrayLength] << " ";
    }
    os << std::endl;
    return;
}

template <typename T>
std::ostream& operator<< ( std::ostream &os, newQueue<T> queue )
{
    queue.output(os);
    return os;
}

#endif