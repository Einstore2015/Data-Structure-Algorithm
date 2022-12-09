#ifndef _DOUBLE_LINKED_DEQUE_H
#define _DOUBLE_LINKED_DEQUE_H

#include "deque.h"
#include "..\exception\myExceptions.h"

#include <iostream>

template <typename T>
struct chainNode
{
    // data
    T element;
    // doublt pointer
    chainNode* next;
    chainNode* previous;

    // Constructor
    chainNode() {}
    chainNode( const T& element )
    : next( 0 ), previous( 0 )
        { this->element = element; }
    chainNode(const T& element,
              chainNode<T>* next,
              chainNode<T>* previous )  
    : next( next ), previous( previous )
        { this->element = element; }
};

template <typename T>
class doublyLinkedDeque : public deque<T>
{
public:
    // constructor & deconstructor
    doublyLinkedDeque();
    ~doublyLinkedDeque();

    bool isEmpty() const;
    int size() const;
    T& front();
    T front() const;
    T& back();
    T back() const;
    void push_front(const T& theElement);
    void push_back(const T& theElement);
    void pop_front();
    void pop_back();

    void output(std::ostream& os) const;
protected:
    chainNode<T>* theFront;
    chainNode<T>* theBack;
    int dequeSize;
};

/* 
 *  Definition
 */
template <typename T>
doublyLinkedDeque<T>::doublyLinkedDeque()
{
    dequeSize = 0;
    theFront = theBack = nullptr;
}

template <typename T>
doublyLinkedDeque<T>::~doublyLinkedDeque()
{
    chainNode<T>* ptr = theFront;
    while (ptr != nullptr){
        chainNode<T>* tmp = ptr;
        ptr = ptr->next;
        delete tmp;
    }
}

template <typename T>
bool doublyLinkedDeque<T>::isEmpty() const
{
    return dequeSize == 0;
}

template <typename T>
int doublyLinkedDeque<T>::size() const
{
    return dequeSize;
}

template <typename T>
T& doublyLinkedDeque<T>::front()
{
    if (isEmpty())
        throw queueEmpty();

    return theFront->element;
}
template <typename T>
T doublyLinkedDeque<T>::front() const
{
    if (isEmpty())
        throw queueEmpty();

    return theFront->element;
}

template <typename T>
T& doublyLinkedDeque<T>::back()
{
    if (isEmpty())
        throw queueEmpty();
    
    return theBack->element;
}
template <typename T>
T doublyLinkedDeque<T>::back() const
{
    if (isEmpty())
        throw queueEmpty();
    
    return theBack->element;
}

template <typename T>
void doublyLinkedDeque<T>::push_back(const T& theElement)
{
    chainNode<T>* newNode = new chainNode<T>(theElement);
    if (isEmpty()){
        theFront = theBack = newNode;
    }else{
        theBack->next = newNode;
        newNode->previous = theBack;
        theBack = newNode;
    }
    dequeSize++;
}

template <typename T>
void doublyLinkedDeque<T>::pop_front()
{
    if (isEmpty())
        throw queueEmpty();
    
    if (theFront->next == nullptr){
        chainNode<T>* to_del = theFront;
        theFront = theBack = nullptr;
        delete to_del;
    }else{
        chainNode<T>* to_del = theFront;
        theFront = theFront->next;
        delete to_del;
    }
    dequeSize--;
}

template <typename T>
void doublyLinkedDeque<T>::push_front(const T& theElement)
{
    chainNode<T>* newNode = new chainNode<T>(theElement);
    if (isEmpty()){
        theFront = theBack = newNode;
    }else{
        newNode->next = theFront;
        theFront->previous = newNode;
        theFront = newNode;
    }
    dequeSize++;
}

template <typename T>
void doublyLinkedDeque<T>::pop_back()
{
    if (isEmpty())
        throw queueEmpty();
    
    if (theBack->previous = nullptr){
        chainNode<T>* to_del = theBack;
        theBack = theFront = nullptr;
        delete to_del;
    }else{
        chainNode<T>* to_del = theBack;
        theBack = theBack->previous;
        delete to_del;
    }
    dequeSize--;
}

template <typename T>
void doublyLinkedDeque<T>::output(std::ostream& os) const
{
    if (isEmpty()){
        os << "Deque is empty. " << std::endl;
        return;
    }else{
        chainNode<T>* ptr = theFront;
        while(ptr){
            os << ptr->element << " ";
            ptr = ptr->next;
        }
        os << std::endl;
        return;
    }
}

template <typename T>
std::ostream& operator<<(std::ostream& os, doublyLinkedDeque<T>& dq)
{
    dq.output(os);
    return os;
}

#endif