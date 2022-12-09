#ifndef _LQEC_H
#define _LQEC_H

#include "queue.h"
#include "..\chapter6\extendedChain.h"
#include "..\exception\myExceptions.h"
#include "..\chapter6\chainNode.h"


template <typename T>
class linkedQueExChain : public queue<T>, public extendedChain<T>
{
public:
    linkedQueExChain()
    {
        extendedChain<T>();
    }

    ~linkedQueExChain()
    {
    }

    bool isEmpty() const
        { return extendedChain<T>::empty(); }
    int  size() const
        { return extendedChain<T>::size(); }
    T&   front()
        { return extendedChain<T>::get(0); }
    T&   back()
        { return extendedChain<T>::get(size()-1); }
    void pop()
    {
        if (isEmpty()){
            throw queueEmpty();
        }
        extendedChain<T>::erase(0);
    }
    void push( const T& theElement )
    {
        extendedChain<T>::insert(size(), theElement);
    }
    void pushNode(chainNode<T>* theNode){
        if (isEmpty()){
            extendedChain<T>::lastNode = theNode;
            extendedChain<T>::firstNode = theNode;
            extendedChain<T>::listSize++;
            return;
        }

        extendedChain<T>::lastNode->next = theNode;
        extendedChain<T>::lastNode = theNode;
        extendedChain<T>::listSize++;
    }
    void popNode(){
        if (isEmpty()){
            throw queueEmpty();
        }
        chainNode<T>* tmp = extendedChain<T>::firstNode;
        extendedChain<T>::firstNode = extendedChain<T>::firstNode->next;
        delete tmp;
        extendedChain<T>::listSize--;
    }
protected:
};

template <typename T>
std::ostream& operator<< ( std::ostream &os, linkedQueExChain<T> &queue )
{
    queue.output( os );
    return os;
}

#endif