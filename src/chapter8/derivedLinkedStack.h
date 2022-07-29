#ifndef _DERIVED_L_STACK_H
#define _DERIVED_L_STACK_H

#include "..\chapter6\chain.h"

template <typename T>
class derivedLinkedStack : public Chain<T>
{
public:
    derivedLinkedStack( int initialCapacity = 10 ) :
        Chain<T>::Chain( initialCapacity ) {}
    ~derivedLinkedStack() {}

    T& top();
    void pop();
    void push( const T& );
    
protected:
    // stackTop  = firstNode
    // stackSize = listSize
};

/* **************************************** */
/*        Definition of functions           */
/* **************************************** */

/* Return top node of stack */
template <typename T>
T& derivedLinkedStack<T>::top()
{
    return Chain<T>::get( 0 );
}


/* Pop out the top node */
template <typename T>
void derivedLinkedStack<T>::pop()
{
    Chain<T>::erase( 0 );
}


/* 
 *  Push theElement as the top node of stack 
 */
template <typename T>
void derivedLinkedStack<T>::push( const T& theElement )
{
    Chain<T>::insert( 0, theElement );
}


#endif