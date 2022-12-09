#ifndef _QUEUQ_H
#define _QUEUQ_H

template <typename T>
class queue
{
public:
    virtual ~queue() {}
    virtual bool isEmpty() const = 0; // if queue is empty, return TRUE
    virtual int size() const = 0; // return lenght of queue
    virtual T& front() = 0; // return the implement of first element
    virtual T& back() = 0; // return the implement of last element
    virtual void pop() = 0;
    virtual void push( const T& theElement ) = 0;
};

#endif