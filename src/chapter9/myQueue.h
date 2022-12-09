#ifndef _MY_QUEUE_H
#define _MY_QUEUE_H

#include "queue.h"
#include "..\exception\myExceptions.h"

#include <iostream>
#include <sstream>

template <typename T>
class myQueue : public queue<T>
{
public:
    // Constructor and deconstructor
    myQueue( int initialCap = 10 );
    ~myQueue();

    bool isEmpty() const;
    int  size() const;
    int  length() const;
    T&   front();
    T&   back();
    void pop();
    void push( const T& theElement );
    void output( std::ostream &os ) const;
protected:
    int theFront;
    int theBack;
    int arrayLength;
    bool lastOp;    // true -> pop() not full | false -> push() not empty
    T*  queue;
};


/* 
 *  
 */
template <typename T>
myQueue<T>::myQueue( int initialCap )
{
    if ( initialCap < 1 ){
        std::ostringstream s;
        s << "Initial capacity = " << initialCap << " Must be > 0";
        throw illegalParameterValue(s.str());
    }
    arrayLength = initialCap;
    queue = new T[arrayLength];
    theFront = theBack = 0;
    lastOp = true;
}

/* 
 *  
 */
template <typename T>
myQueue<T>::~myQueue()
{
    delete[] queue;
}

/* 
 *  
 */
template <typename T>
bool myQueue<T>::isEmpty() const
{
    if ( theFront == theBack && lastOp ){
        return true;
    }else{
        return false;
    }
}

/* 
 *  
 */
template <typename T>
int myQueue<T>::size() const
{
    if ( theBack == theFront && !lastOp ) { return arrayLength; }
    else{
        return (theBack - theFront + arrayLength) % arrayLength;
    }
}

/* 
 *  
 */
template <typename T>
int myQueue<T>::length() const
{
    return arrayLength;
}

/* 
 *  
 */
template <typename T>
T& myQueue<T>::front()
{
    return queue[(theFront+1) % arrayLength];
}

/* 
 *  
 */
template <typename T>
T& myQueue<T>::back()
{
    return queue[theBack % arrayLength];
}

/* 
 *  
 */
template <typename T>
void myQueue<T>::pop()
{
    if (isEmpty()){
        throw queueEmpty();
    }

    theFront = (theFront+1) % arrayLength;
    queue[theFront].~T();
    lastOp = true;
}

/* 
 *  
 */
template <typename T>
void myQueue<T>::push( const T& theElement )
{
    if ( theFront == theBack && !lastOp ){
        // queue is full
        T* newQueue = new T[arrayLength * 2];

        if ( theBack>theFront){
            // consistent
            std::copy(queue+theFront+1, queue+theBack+1, newQueue);
        }else{
            std::copy(queue+theFront+1, queue+arrayLength, newQueue);
            std::copy(queue, queue+theBack+1, newQueue+arrayLength-theFront-1);
        }

        // set theFront and theBack
        // according to old arrayLength
        theFront = 2*arrayLength-1;
        theBack = arrayLength-1;
        arrayLength *=2;
        delete[] queue;
        queue = newQueue;
    }

    // push new element
    theBack = (theBack+1) % arrayLength; 
    queue[theBack] = theElement;
    lastOp = false;
}

/* 
 *  
 */
template <typename T>
void myQueue<T>::output( std::ostream &os ) const
{
    if (isEmpty()){
        os << "Empty queue" << std::endl;
        return;
    }

    os << "Queue elements: ";
    for ( int i=1; i <= size(); i++ ){
        os << queue[(theFront + i) % arrayLength] << " ";
    }
    os << std::endl;
    return;
}

template <typename T>
std::ostream& operator<< ( std::ostream &os, myQueue<T> queue )
{
    queue.output(os);
    return os;
}

#endif