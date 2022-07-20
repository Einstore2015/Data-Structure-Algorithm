#ifndef _DOUBLY_LINKED_LIST_H
#define _DOUBLY_LINKED_LIST_H

#include "chainNodeDoubly.h"
#include <iostream>

template <typename T>
class doublyLinkedList
{
public:
    // Constructor
    doublyLinkedList()
        { firstNode = lastNode = 0;
          listSize = 0; }
        
    // const function
    int size()  const
        { return listSize; }
    bool isEmpty()  const
        { return ( size()==0 ? true : false ); }

    // non-const function
    void push_back( const T& theElement );
    void header_insert( const T& theElement );
    void reverse();

    // Output
    void output( std::ostream& out ) const;

protected:
    chainNodeDB<T>* firstNode;
    chainNodeDB<T>* lastNode;
    int             listSize;
};


/* 
 *
 *  Tail insert theElement
 */
template <typename T>
void doublyLinkedList<T>::
push_back( const T& theElement )
{
    if ( isEmpty() ){
        chainNodeDB<T>* ptr = new chainNodeDB<T>( theElement );
        firstNode = lastNode = ptr;
    }else{
        chainNodeDB<T>* ptr = new chainNodeDB<T>( theElement, 0, lastNode );
        lastNode->next = ptr;
        // move lastNode
        lastNode = lastNode->next;
    }

    listSize++;
}


/* 
 *
 *  Header insert theElement
 */
template <typename T>
void doublyLinkedList<T>::
header_insert( const T& theElement )
{
    if ( isEmpty() ){
        chainNodeDB<T> *ptr = new chainNodeDB<T>( theElement );
        firstNode = lastNode = ptr;
    }else{
        chainNodeDB<T> *ptr = new chainNodeDB<T>( theElement,
                                        firstNode, 0 );
        firstNode->previous = ptr;
        firstNode = ptr;
    }

    listSize++;
}


/* 
 *
 *  Reverse this chain
 */
template <typename T>
void doublyLinkedList<T>::reverse()
{
    chainNodeDB<T> *cur = firstNode;

    while ( cur != lastNode ){
        // usea a tmp pointer-> original 'previous'
        chainNodeDB<T> *tmp = cur->previous;
        cur->previous = cur->next;
        cur->next = tmp;

        // "next" is previous pointer now!
        cur = cur->previous;
    }
    // deal with lastNode
    lastNode->next = lastNode->previous;
    lastNode->previous = 0;

    // exchange firstNode and lastNode
    cur = lastNode;
    lastNode = firstNode; firstNode = cur;
}

/* 
 *
 *  Output chain into a ostream
 */
template <typename T>
void doublyLinkedList<T>::
output( std::ostream& out ) const
{
    chainNodeDB<T> *cur = firstNode;

    while ( cur != lastNode ){
        out << cur->element << " ";
        cur = cur->next;
    }
    // lastNode
    out << lastNode->element << " ";

    out << std::endl;
}
// Overidden operator<<
template <typename T>
std::ostream& operator<< ( std::ostream& out, const doublyLinkedList<T>& chain )
{
    chain.output( out );
    return out;
}

#endif