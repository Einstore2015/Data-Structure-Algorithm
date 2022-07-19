#ifndef _MOVE_ON_CHAIN_H
#define _MOVE_ON_CHAIN_H

#include "chain.h"

template <typename T>
class moveChain : public Chain<T>
{
public:
    // constructor
    moveChain( int initialCapacity=10 ) :
        Chain<T>( initialCapacity ) 
        { p = this->firstNode; l = 0; }

    // function
    void moveRight();
    void moveLeft();

    T currentElement() const
        { return p->element; }
    T previousElement() const
        { return l->element; }

protected:
    Chain<T>     left_chain, right_chain;
    chainNode<T> *p, *l;
};


template <typename T>
void moveChain<T>::moveRight()
{
    if ( p == 0 ){
        p = this->firstNode;
    }
    if ( p->next == 0 ){
        std::cout << "This chain has reached the end!" << std::endl;
        exit(-1);
    }

    if ( l == 0 ){
        chainNode<T> *tmp = p;
        p = p->next;
        l = tmp;
        l->next = 0;
    }else{
        chainNode<T> *tmp = p;
        p = p->next;
        tmp->next = l;
        l = tmp;
    }
}


template <typename T>
void moveChain<T>::moveLeft()
{
    if ( p == 0 ){
        p = this->firstNode;
    }
    if ( p->next == 0 ){
        std::cout << "This chain has reached the end!" << std::endl;
        exit(-1);
    }

    if ( l == this->firstNode ){
        std::cout << "This chain has reached the begin!" << std::endl;
        exit(-1);
    }else{
        chainNode<T> *tmp = l;
        l = l->next;
        tmp->next = p;
        p = tmp;
    }
}

#endif