#ifndef _DEQUE_QUEUE
#define _DEQUE_QUEUE

#include "queue.h"
#include "arrayDeque.h"

template <typename T>
class dequeQueue : public queue<T>, public arrayDeque<T>
{
public:
    bool isEmpty() const
        { return arrayDeque<T>::isEmpty(); }
    int size() const
        { return arrayDeque<T>::size(); }
    T& front()
        { return arrayDeque<T>::front(); }
    T& back()
        { return arrayDeque<T>::back(); }
    void pop()
        { arrayDeque<T>::pop_front(); }
    void push( const T& theElement )
        { arrayDeque<T>::push_back( theElement ); }
protected:
};

#endif