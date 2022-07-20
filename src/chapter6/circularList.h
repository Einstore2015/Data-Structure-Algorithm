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
    chainNode<T> *firstNode;
    int listSize;
};


/* 
 *  Constructor of circularList
 */
template <typename T>
circularList<T>::circularList()
{
    firstNode = 0;
    listSize  = 0;
}


/* 
 *  Return the leftest index of theElement
 *  If theElement doesn't exist, return -1.
 */
template <typename T>
int circularList<T>::indexOf( const T& theElement ) const
{

}

#endif