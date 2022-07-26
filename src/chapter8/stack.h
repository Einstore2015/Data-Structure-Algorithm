#ifndef _STACK_H
#define _STACK_H

#include <string>
#include "..\chapter6\chainNode.h"

template <typename T>
class stack
{
public:
    virtual ~stack() {}
    virtual bool    empty() const = 0;
    virtual int     size() const = 0;
    virtual T&      top() = 0;
    virtual void    pop() = 0;
    virtual void    push( const T& theElement ) = 0;

private:

};

template <typename T>
class extendedStack : public stack<T>
{
public:
    virtual ~extendedStack() {}
    // Input a stack from bottom to top
    virtual void input( chainNode<T>* ) = 0;
    // Return the stack elements, as a string, from bottom to top
    virtual std::string toString() const = 0;
    // Split a stack into stacks s1 and s2. Stack s1 contains the bottom-half elements,
    // and stack s2 contains the remaining elemetns.
    virtual void split( extendedStack<T>* , extendedStack<T>* ) = 0;
    // Combine stacks s1 and s2 into a single stack. The elements are the 
    // result of placing stack s2 on top of s1.
    virtual void combine( extendedStack<T>*, extendedStack<T>* ) = 0;
};

#endif