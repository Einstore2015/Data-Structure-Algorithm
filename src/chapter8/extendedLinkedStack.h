#ifndef _EX_LINKED_STACK_H
#define _EX_LINKED_STACK_H

#include <vector>
#include "stack.h"
#include "linkedStack.h"

template <typename T>
class extendedLinkedStack : public linkedStack<T>, public extendedStack<T>
{
public:
    extendedLinkedStack( int initialCapacity = 10 ) :
        linkedStack<T>::linkedStack( initialCapacity ) {}
    ~extendedLinkedStack() {}

    // const //
    bool empty() const
        { return this->stackSize == 0; }
    int size() const
        { return this->stackSize; }

    // 
    T& top()
        { return linkedStack<T>::top(); }
    void pop()
        { linkedStack<T>::pop(); }
    void push( const T& theElement )
        { linkedStack<T>::push( theElement ); }

    virtual void input( chainNode<T>* );
    virtual std::string toString() const;
    virtual void split( extendedStack<T>* p1, extendedStack<T>* p2 );
    virtual void combine( extendedStack<T>* s1, extendedStack<T>* s2 );

private:
};


template <typename T>
void extendedLinkedStack<T>::input( chainNode<T>* top )
{
    if ( empty() ){
        this->stackTop = top;
        this->stackSize++;
    }else{
        this->pushNode( top );
        this->stackSize++;
    }

}

template <typename T>
std::string extendedLinkedStack<T>::toString() const
{
    chainNode<T>* cur = this->stackTop;
    std::vector< chainNode<T>* > ptr_vec;
    std::string s = "";
    while( cur ){
        ptr_vec.push_back( cur );
        cur = cur->next;
    }

    for ( int i=size()-1; i>=0; i--){
        std::cout << ptr_vec[i]->element << " ";
    }
    std::cout << std::endl;

    return s;
}


template <typename T>
void extendedLinkedStack<T>::
split( extendedStack<T>* p1, extendedStack<T>* p2 )
{
    if ( this->empty() ){
        return;
    }

    chainNode<T>* cur = this->stackTop;
    p2->input( cur );
    std::cout << cur->element << std::endl;

    int count_nodes = 1;
    while( count_nodes < this->stackSize / 2 ){
        cur = cur->next;
        count_nodes++;
    }
    // cur->next is p1 headNode
    p1->input( cur->next );
    cur->next = 0;      // bottom of *s1

    // clear this stack
    this->stackSize = 0; this->stackTop = 0;
}


template <typename T>
void extendedLinkedStack<T>::
combine( extendedStack<T>* s1, extendedStack<T>* s2 )
{
    /* 
     *  TODO
     */
    std::cout << "Sorry, combine() has not been implemented." << std::endl;
}

#endif