#ifndef _DEQUE_STACK
#define _DEQUE_STACK

#include "arrayDeque.h"
#include "..\chapter8\stack.h"

template <typename T>
class dequeStack : public arrayDeque<T>, public stack<T>
{
public:
    bool empty() const
        { return arrayDeque<T>::isEmpty(); }
    int size() const
        { return arrayDeque<T>::size(); }
    T&  top()
        { return arrayDeque<T>::front(); }
    void pop()
        { arrayDeque<T>::pop_back(); }
    void push( const T& theElement )
        { arrayDeque<T>::push_back( theElement ); }
protected:
};


template <typename T>
std::ostream& operator<< ( std::ostream& os, dequeStack<T>& deque )
{
    deque.output(os);
    return os;
}

#endif