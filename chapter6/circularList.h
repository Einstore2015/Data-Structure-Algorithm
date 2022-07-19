#ifndef _CIRCULARLIST_H
#define _CIRCULARLIST_H

#include "chainNode.h"

template <typename T>
class circularList
{
public:
    // constructor
    circularList();

    int indexOf( const T& theElement ) const;

protected:
    chainNode<T> *headerNode;
    int listSize;
};


/* 
 *  Constructor of circularList
 */
template <typename T>
circularList<T>::circularList()
{
    headerNode = new chainNode<T>();
    headerNode->next = headerNode;
    listSize = 0;
}


/* 
 *  Return the leftest index of theElement
 *  If theElement doesn't exist, return -1.
 */
template <typename T>
int circularList<T>::indexOf( const T& theElement ) const
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

#endif