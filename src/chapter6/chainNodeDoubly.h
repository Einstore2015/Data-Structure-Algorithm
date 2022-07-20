#ifndef _CHAIN_NODE_DOUBLY_H
#define _CHAIN_NODE_DOUBLY_H

template <typename T>
struct chainNodeDB
{
    // data
    T element;
    // doublt pointer
    chainNodeDB* next;
    chainNodeDB* previous;

    // Constructor
    chainNodeDB() {}
    chainNodeDB( const T& element ) :
        next( 0 ), previous( 0 )
        { this->element = element; }
    chainNodeDB( const T& element, chainNodeDB<T>* next,
                    chainNodeDB<T>* previous )  :
        next( next ), previous( previous )
        { this->element = element; }
};

#endif