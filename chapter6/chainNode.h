#ifndef _CHAINNODE_H
#define _CHAINNODE_H

template <typename T>
struct chainNode
{
    T element;
    chainNode<T> *next;

    //constructor
    chainNode() {}
    chainNode( const T& element )
        { this->element = element, next = 0; }
    chainNode( const T& element, chainNode<T>* next )
        { this->element = element;
          this->next = next; }
};

#endif