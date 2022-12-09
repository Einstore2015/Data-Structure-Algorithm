#ifndef _ARRAY_QUEUE_H
#define _ARRAY_QUEUE_H

#include "queue.h"
#include "..\exception\myExceptions.h"

#include <iostream>
#include <sstream>

template <class T>
class arrayQueue : public queue<T>
{
public:
    // Constructor and Deconstructor
    arrayQueue( int initialCap = 10 );
    bool isEmpty() const;
    int size() const;

    T& front();
    T  front() const;
    T& back();
    void pop();
    void push( const T& theElement );
    void clear();
    void splitInto( arrayQueue<T>& q1, arrayQueue<T>& q2 ) const;

    void output( std::ostream& os ) const;
    void operator<<( arrayQueue<T>& inQueue );
protected:
    int theFront;
    int theBack;
    int arrayLength;
    T* queue;
};

/* 
 *  Constructor
 */
template <typename T>
arrayQueue<T>::arrayQueue( int initialCap )
{
    if ( initialCap < 1 ){
        std::ostringstream s;
        s << "Initial capacity = " << initialCap << " Must be > 0";
        throw illegalParameterValue(s.str());
    }
    arrayLength = initialCap;
    queue = new T[arrayLength];
    theFront = 0; theBack = 0;
}

template <typename T>
bool arrayQueue<T>::isEmpty() const
{
    return ( theFront == theBack );
}

template <typename T>
void arrayQueue<T>::clear()
{
    if (!isEmpty()){
        delete[] queue;
        queue = new T[arrayLength];
        theFront = theBack = 0;
    }
}

template <typename T>
int arrayQueue<T>::size() const
{
    return (theBack - theFront + arrayLength) % arrayLength;
}

template <typename T>
T& arrayQueue<T>::front()
{
    if (theFront == theBack){
        throw queueEmpty();
    }
    return queue[(theFront+1) % arrayLength];
}

template <typename T>
T arrayQueue<T>::front() const
{
    if (theFront == theBack){
        throw queueEmpty();
    }
    return queue[(theFront+1) % arrayLength];
}

template <typename T>
T& arrayQueue<T>::back()
{
    if (theFront == theBack){
        throw queueEmpty();
    }
    return queue[theBack];
}

template <typename T>
void arrayQueue<T>::pop()
{
    if (theFront == theBack){
        throw queueEmpty();
    }
    theFront = (theFront+1) % arrayLength;
    queue[theFront].~T();
}

template <typename T>
void arrayQueue<T>::push( const T& theElement )
{
    // increase array length if necessary
    if ( (theBack+1) % arrayLength == theFront ){
        T* newQueue = new T[2 * arrayLength];

        // copy
        int start = (theFront + 1) % arrayLength;
        if ( start < 2){
            std::copy(queue+start, queue+start+arrayLength-1, newQueue);
        }else{
            // wraps
            std::copy(queue+start, queue+arrayLength, newQueue);
            std::copy(queue, queue+theBack+1, newQueue+arrayLength-start);
        }

        // switch to newQueue
        theFront = 2 * arrayLength - 1;
        theBack = arrayLength - 2;
        arrayLength *= 2;
        delete[] queue;
        queue = newQueue;
    }

    // push new element
    theBack = (theBack + 1) % arrayLength;
    queue[theBack] = theElement;
}

/* 
 *  Split the queue into two NEW queues
 */
template <typename T>
void arrayQueue<T>::splitInto( arrayQueue<T>& q1, arrayQueue<T>& q2 ) const
{
    if (isEmpty()){
        throw queueEmpty();
    }

    q1.clear(); q2.clear();
    bool flag = true;
    for ( int i=theFront+1; (i % arrayLength) != (theBack+1) % arrayLength; i++ ){
        if (flag){
            // queue 1
            q1.push(queue[i % arrayLength]);
        }else{
            q2.push(queue[i % arrayLength]);
        }
        flag = !flag;
    }
}


template <typename T>
void arrayQueue<T>::operator<<( arrayQueue<T>& inQueue )
{
    delete[] queue;

    theFront = inQueue.theFront;
    theBack  = inQueue.theBack;
    arrayLength = inQueue.arrayLength;
    queue = new T[arrayLength];

    // copy
    int start = (theFront + 1) % arrayLength;
    if ( start < 2){
        std::copy(inQueue.queue+start,
                  inQueue.queue+start+arrayLength-1,
                  queue);
    }else{
        // wraps
        std::copy(inQueue.queue+start,
                  inQueue.queue+arrayLength,
                  queue);
        std::copy(inQueue.queue,
                  inQueue.queue+theBack+1,
                  queue+arrayLength-start);
    }
    theFront = arrayLength-1;
    theBack  = arrayLength-1 + inQueue.size();
}

template <typename T>
void arrayQueue<T>::output( std::ostream& os ) const
{
    if (theFront == theBack){
        os << "Queue is empty." << std::endl;
        return;
    }

    os << "Queue elements: ";
    for ( int i=theFront+1; (i % arrayLength) != (theBack+1) % arrayLength; i++ ){
        os << queue[i % arrayLength] << " ";
    }
    os << std::endl;
}

template <typename T>
std::ostream& operator<<( std::ostream& os, arrayQueue<T>& queue ){
    queue.output( os );
    return os;
}

#endif