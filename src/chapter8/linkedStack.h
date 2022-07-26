#ifndef _LINK_STACK_H
#define _LINK_STACK_H

#include <iostream>
#include "stack.h"
#include "..\chapter6\chainNode.h"
#include "stackException.h"

template <typename T>
class linkedStack : public stack<T>
{
public:
    linkedStack( int initialCapacity = 10 )
        { stackTop = 0; stackSize = 0; }
    ~linkedStack();

    // const
    bool empty() const
        { return stackSize == 0; }
    int size() const
        { return stackSize; }
    
    // non-const
    T& top();
    void pop();
    chainNode<T>* popNode();
    void push( const T& );
    void pushNode( chainNode<T>* theNode );

    // operator
    void output( std::ostream& ) const;

protected:
    chainNode<T>* stackTop;     // stacktop pointer
    int stackSize;              // number of elements in stack
};

/* **************************************** */
/*        Definition of functions           */
/* **************************************** */

/* 
 *  
 *  Deconstrucotr
 */
template <typename T>
linkedStack<T>::~linkedStack()
{
    while ( stackTop ){
        chainNode<T> *del_ptr = stackTop;
        stackTop = stackTop->next;
        delete del_ptr;
    }
}


template <typename T>
T& linkedStack<T>::top()
{
    if ( empty() ){
        throw stackEmpty();
    }

    return stackTop->element;
}

/* 
 *  
 *  Stack pop top
 */
template <typename T>
void linkedStack<T>::pop()
{
    if ( stackSize == 0 ){
        throw -1;
    }

    chainNode<T> *del_ptr = stackTop;
    stackTop = stackTop->next;
    delete del_ptr;

    stackSize--;
}


/* 
 *  
 *  Push theElement into the stack
 */
template <typename T>
void linkedStack<T>::push( const T& theElement )
{
    if ( stackSize == 0 ){
        // stack is empty
        chainNode<T> *tmp = new chainNode<T>( theElement );
        stackTop = tmp;
    }else
    {
        chainNode<T> *tmp = new chainNode<T>( theElement, stackTop );
        stackTop = tmp;
    }

    stackSize++;
}


/* 
 *  
 *  
 */
template <typename T>
void linkedStack<T>::pushNode( chainNode<T>* theNode )
{
    if ( stackSize == 0 ){
        stackTop = theNode;
    }else{
        theNode->next = stackTop;
        stackTop = theNode;
    }

    stackSize++;
}

template <typename T>
chainNode<T>* linkedStack<T>::popNode()
{
    if ( stackSize == 0 ){
        throw -1;
    }

    chainNode<T>* tmp = stackTop;
    stackTop = stackTop->next;
    stackSize--;

    return tmp;
}

template <typename T>
void linkedStack<T>::output( std::ostream& out ) const
{
    chainNode<T> *cur = stackTop;
    while( cur ){
        out << cur->element << " ";
        cur = cur->next;
    }
    out << std::endl;
}


/* **************************************** */
/*                Extern                    */
/* **************************************** */

template <typename T>
std::ostream& operator<<( std::ostream& out, linkedStack<T>& s )
{
    s.output( out );
    return out;
}

#endif