#ifndef _ARRAY_DEQUE_H
#define _ARRAY_DEQUE_H

#include "deque.h"
#include "..\exception\myExceptions.h"

#include <sstream>
#include <iostream>

template <typename T>
class arrayDeque : public deque<T>
{
public:
    // 
    arrayDeque( int initialCap = 10 );
    ~arrayDeque();

    bool isEmpty() const;
    int  size() const;
    T&   front();
    T&   back();
    void push_front( const T& theElement );
    void push_back ( const T& theElement );
    void pop_front();
    void pop_back ();
    std::ostream& output( std::ostream& ) const;
protected:
    int theFront;
    int dequeSize;
    int arrayLength;
    T* deque;
};

template <typename T>
arrayDeque<T>::arrayDeque( int initialCap )
{
    if (initialCap < 1){
        std::ostringstream s;
        s << "Initial capacity = " << initialCap << " Must be > 0";
        throw illegalParameterValue(s.str());
    }
    arrayLength = initialCap;
    deque = new T[arrayLength];
    theFront = 0;
    dequeSize = 0;
}

template <typename T>
arrayDeque<T>::~arrayDeque()
{
    delete[] deque;
}

template <typename T>
bool arrayDeque<T>::isEmpty() const
{
    return ( dequeSize==0 ? true : false);
}

template <typename T>
int arrayDeque<T>::size() const
{
    return dequeSize;
}

template <typename T>
T& arrayDeque<T>::front()
{
    if (isEmpty()){
        throw queueEmpty();
    }
    return deque[(theFront+1) % arrayLength ];
}

template <typename T>
T& arrayDeque<T>::back()
{
    if (isEmpty()){
        throw queueEmpty();
    }
    return deque[(theFront+dequeSize) % arrayLength];
}


template <typename T>
void arrayDeque<T>::push_front( const T& theElement )
{
    if (dequeSize == arrayLength){
        // need double memory
        T* newDeque = new T[2*arrayLength];

        if ( (theFront+1) % arrayLength == 0){
            std::copy(deque, deque+arrayLength, newDeque);
        }else{
            std::copy(deque+theFront+1, deque+arrayLength, newDeque);
            std::copy(deque, deque+theFront+1, newDeque+arrayLength-theFront-1);
        }

        theFront = 2*arrayLength-1;
        dequeSize = arrayLength;
        arrayLength *=2;
        delete[] deque;
        deque = newDeque;
    }
    theFront +=(arrayLength-1);
    theFront %= arrayLength;
    deque[(theFront+1) % arrayLength] = theElement;
    dequeSize++;
}

template <typename T>
void arrayDeque<T>::push_back( const T& theElement )
{
    if (dequeSize == arrayLength){
        // need double memory
        T* newDeque = new T[2*arrayLength];

        if ( (theFront+1) % arrayLength == 0){
            std::copy(deque, deque+arrayLength, newDeque);
        }else{
            std::copy(deque+theFront+1, deque+arrayLength, newDeque);
            std::copy(deque, deque+theFront+1, newDeque+arrayLength-theFront-1);
        }

        theFront = 2*arrayLength-1;
        dequeSize = arrayLength;
        arrayLength *=2;
        delete[] deque;
        deque = newDeque;
    }
    dequeSize++;
    deque[(theFront+dequeSize) % arrayLength] = theElement;
}

template <typename T>
void arrayDeque<T>::pop_front()
{
    if (isEmpty()){
        throw queueEmpty();
    }

    theFront = (theFront+1) % arrayLength;
    deque[theFront].~T();
    dequeSize--;
}

template <typename T>
void arrayDeque<T>::pop_back()
{
    if (isEmpty()){
        throw queueEmpty();
    }

    deque[theFront+dequeSize].~T();
    dequeSize--;
}

template <typename T>
std::ostream& arrayDeque<T>::output( std::ostream &os ) const
{
    if ( isEmpty() ){
        os << "Empty deque" << std::endl;
        return os;
    }
    os << "Deque elements: ";
    for (int i=1; i <= dequeSize; i++){
        os << deque[(theFront+i) % arrayLength] << " ";
    }
    os << std::endl;
    return os;
}


template <typename T>
std::ostream& operator<< ( std::ostream& os, arrayDeque<T>& deque )
{
    deque.output(os);
    return os;
}


#endif