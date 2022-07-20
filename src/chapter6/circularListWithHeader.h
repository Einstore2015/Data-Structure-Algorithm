#ifndef _CIRCULARLIST_WITH_HEADER_H
#define _CIRCULARLIST_WITH_HEADER_H

#include <iostream>
#include "chainNode.h"

template <typename T>
class circularListWithHeader
{
public:
    // constructor
    circularListWithHeader();

    // const function
    int size() const
        { return listSize; }
    int empty() const
        { return ( size()==0 ? true : false ); }
    int indexOf( const T& theElement ) const;

    void insert( const T& theElement, int theIndex=1 );
    void push_back( const T& theElement );

    void reverse();
    void meld( const circularListWithHeader<T>& chain_a,
               const circularListWithHeader<T>& chain_b);
    void merge( circularListWithHeader<T>& chain_a, 
                circularListWithHeader<T>& chain_b);

    void output( std::ostream& out ) const;

protected:
    chainNode<T> *headerNode;
    int listSize;
};


/* 
 *  Constructor of circularList
 */
template <typename T>
circularListWithHeader<T>::
circularListWithHeader()
{
    headerNode = new chainNode<T>();
    headerNode->next = headerNode;
    listSize = 0;
}


/* 
 *  Return the leftest index of theElement
 *  If theElement doesn't exist, return -1.
 * 
 *  Index begins at 1.
 */
template <typename T>
int circularListWithHeader<T>::
indexOf( const T& theElement ) const
{
    // Insert theElement to header node (empty node)
    headerNode->element = theElement;
    int index = 0;

    chainNode<T> *cur = headerNode->next;
    while ( cur->element != theElement ){
        index++;
        cur = cur->next;
    }

    if ( cur == headerNode ){
        // one circle
        return -1;
    }else{
        return index;
    }
}


/* 
 *  Insert theElement into this chain, after this
 *  procedure,  its index will be theIndex.
 *  Default value of theIndex is 0. In that condition,
 *  this function equals to head_insert.
 */
template <typename T>
void circularListWithHeader<T>::
insert( const T& theElement, int theIndex )
{
    chainNode<T> *cur = headerNode;

    // cur ---> chainNode[theIndex-1]
    for( int i=0; i<theIndex-1; ++i ){
        cur = cur->next;
    }

    cur->next = new chainNode<T>( theElement, cur->next );
    listSize++;
}


/* 
 *  Tail insert a chainNode.
 */
template <typename T>
void circularListWithHeader<T>::
push_back( const T& theElement )
{
    chainNode<T> *cur = headerNode;

    while ( cur->next != headerNode ){
        cur = cur->next;
    }
    cur->next = new chainNode<T>( theElement, headerNode );

    listSize++;
}


/* 
 *  Reverse this chain, no extra chainNode needed.
 */
template <typename T>
void circularListWithHeader<T>::reverse()
{
    if ( empty() ) { return; }

    chainNode<T> *p = headerNode,
                 *q = p->next;
    while ( q != headerNode ){
        chainNode<T> *tmp = q->next;

        q->next = p;
        p = q;
        q = tmp;
    }
    // After loop: p -> chainNode[size()], q -> headerNode
    // link headerNode to circular
    q->next = p;

}

/* 
 *  Merge elements from two chain alternately.
 *  Create new chainNode
 */
template <typename T>
void circularListWithHeader<T>::
meld( const circularListWithHeader<T>& chain_a,
        const circularListWithHeader<T>& chain_b )
{
    chainNode<T> *ptr_a = chain_a.headerNode->next,
                 *ptr_b = chain_b.headerNode->next;

    while ( ptr_a != chain_a.headerNode || ptr_b != chain_b.headerNode ){
        if ( ptr_a != chain_a.headerNode ){
            push_back( ptr_a->element );
            ptr_a = ptr_a->next;
        }

        if ( ptr_b != chain_b.headerNode ){
            push_back( ptr_b->element );
            ptr_b = ptr_b->next;
        }
    }
}

/* 
 *  Output all elements into ostream out.
 */
template <typename T>
void circularListWithHeader<T>::
output( std::ostream& out ) const
{
    if ( empty() ){
        out << "This chain is empty!" << std::endl;
    }

    chainNode<T> *cur = headerNode->next;
    while ( cur != headerNode ){
        out << cur->element << " ";
        cur = cur->next;
    }
    out << std::endl;
}

template <typename T>
std::ostream&
operator<<( std::ostream& out, circularListWithHeader<T>& cwh )
{
    cwh.output( out );
    return out;
}


#endif