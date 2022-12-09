#ifndef _DEQUE_H
#define _DEQUE_H

template <typename T>
class deque
{
public:
    virtual ~deque() {}

    virtual bool isEmpty() const = 0;
    virtual int  size() const = 0;
    virtual T& front() = 0;
    virtual T& back() = 0;
    virtual void push_front( const T& theElement ) = 0;
    virtual void push_back ( const T& theElement ) = 0;
    virtual void pop_front() = 0;
    virtual void pop_back () = 0;
};

#endif