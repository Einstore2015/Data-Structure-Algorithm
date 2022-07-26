#ifndef _ARRAYSTACK_H
#define _ARRAYSTACK_H

#include <iostream>
#include <algorithm>
#include <math.h>
#include "stack.h"
#include "stackException.h"

template <typename T>
void changeLength1D(T*& a, int oldLength, int newLength)
{
   if (newLength < 0)
      throw -1;

   T* temp = new T[newLength];                  // new array
   int number = std::min(oldLength, newLength); // number to copy
   std::copy(a, a + number, temp);
   delete [] a;                                 // deallocate old memory
   a = temp;
}

template <typename T>
class arrayStack : public stack<T>
{
public:
    arrayStack( int initialCapacity = 10 );
    ~arrayStack() { delete [] stack;}
    
    // Const function
    bool empty() const
        { return stacktop == -1; }
    int size() const
        { return stacktop + 1; }
    int capa() const
        { return arrLen; }
    T& top();

    void pop();

    // ADT
    void push( const T& theElement );
    void output( std::ostream& ) const;
    void split( arrayStack<T>&, arrayStack<T>& ) const;

    // Operator
    arrayStack<T>& operator=(const arrayStack<T>& );

private:
    T *stack;       // array of elements
    int stacktop;   // top of stack
    int arrLen;     // capacity of stack
};

/* **************************************** */
/*        Definition of functions           */
/* **************************************** */

template <typename T>
arrayStack<T>::arrayStack( int initialCapacity )
{
    if ( initialCapacity < 1 ){
        throw -1;
    }
    arrLen = initialCapacity;
    stack = new T [arrLen];
    stacktop = -1;
}


template <typename T>
T& arrayStack<T>::top()
{
    {
        if ( stacktop == -1 ){
            throw stackEmpty();
        }
        return stack[stacktop];
    }

}

template <typename T>
void arrayStack<T>::pop()
{
    if ( stacktop == -1 ){
        throw stackEmpty();
    }
    // deconstructor of T
    stack[stacktop--].~T();

    if ( size() < arrLen /4 ){
        // decrease sapce
        T *temp = new T [ arrLen / 2 ];
        std::copy(stack, stack+size(), temp );
        delete [] stack;
        stack = temp;
        arrLen = arrLen / 2;
    }
}


template <typename T>
void arrayStack<T>::push( const T& theElement )
{
    if ( stacktop == arrLen - 1 ){
        // stack is full
        changeLength1D( stack, arrLen, 2 * arrLen );
        arrLen *= 2;
    }

    stack[++stacktop] = theElement;
}


template <typename T>
void arrayStack<T>::split( arrayStack<T>& s1, arrayStack<T>& s2 ) const
{
    int len_1 = size() / 2;         // length of s1
    arrayStack<T> as1( arrLen ), as2( arrLen );
    for ( int i=0; i<len_1; i++){
        as1.push( stack[i] );
    }

    for ( int i=len_1; i<size(); i++){
        as2.push( stack[i] );
    }

    s1 = as1; s2 = as2;
}


template <typename T>
void arrayStack<T>::output( std::ostream& out ) const
{
    for( int i=0; i<=stacktop; i++){
        out << stack[i] << " ";
    }

    out << std::endl;
}

template <typename T>
arrayStack<T>& arrayStack<T>::operator=( const arrayStack<T>& s )
{
    if ( this != &s ){
        // clear original stack
        delete [] stack;
        arrLen = s.arrLen;
        stack = new T [arrLen];
        stacktop = -1;

        // for ( int i=0; i<s.size(); i++){
        //     stack[i] = s.stack[i];
        // }
        while ( stacktop < s.stacktop ){
            ++stacktop;
            stack[stacktop] = s.stack[stacktop];
        }
    }

    return *this;
}


template <typename T>
std::ostream& operator<<( std::ostream& out, arrayStack<T>& s )
{
    s.output( out );

    return out;
}



#endif