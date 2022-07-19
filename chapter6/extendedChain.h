#ifndef _EXTENDENCHAIN_H
#define _EXTENDENCHAIN_H

#include "chain.h"
#include "chainNode.h"
#include "linearList.h"

template <typename T>
class extendedChain : public extendedLinearList<T>, public Chain<T>
{
public:
    // constructor and copy constructor
    extendedChain( int initialCapacity=10 ) :
        Chain<T>( initialCapacity ) {}
    extendedChain( const extendedChain<T>& c ) :
        Chain<T>( c ), lastNode( c.lastNode ) {}
    
    // ADT
    bool empty() const 
            { return this->listSize==0; };
    int  size() const 
            { return this->listSize; };
    T&   get( int theIndex ) const
            { return Chain<T>::get(theIndex); }
    int  indexOf( const T& theElement ) const
            { return Chain<T>::indexOf( theElement ); }
    void erase( int theIndex );
    void insert( int theIndex, const T& theElement );
    void clear()
    {
        std::cout << "bgein clear():" << std::endl;
        while ( this->firstNode ){
            chainNode<T> *del_ptr = this->firstNode;
            this->firstNode = del_ptr->next;
            std::cout << del_ptr->element << " ";
            delete del_ptr;
        }
        std::cout << std::endl;
        std::cout << "end clear()" << std::endl;
        zero();
    }

    void push_back( const T& theElement );
    // void output( std::ostream& out ) const;
    void output( std::ostream &out ) const
        { Chain<T>::output( out ); }

    // additional
    void zero()
        { this->firstNode = 0; this->listSize = 0; }
    void merge( extendedChain<T>& ec_a, extendedChain<T>& ec_b );
    void split( extendedChain<T>& ec_a, extendedChain<T>& ec_b ) const;
    void circularShift( int theIndex );

protected:
    chainNode<T>* lastNode;
};

/* 
 * Erase
 */
template <typename T>
void extendedChain<T>::erase( int theIndex )
{
    // Chain<T>::mycheckIndex( theIndex );
    this->mycheckIndex( theIndex );

    chainNode<T> *del_ptr;
    // remove the first node
    if ( theIndex == 0){
        del_ptr = this->firstNode;
        this->firstNode = this->firstNode->next;
        if ( del_ptr == this->firstNode ) { lastNode = this->firstNode; }
    }else{
        // move the node[index-1]
        chainNode<T> *tmp;
        for ( int i=0; i<theIndex-1; i++ ){
            tmp = tmp->next;
        }
        del_ptr = tmp->next;
        tmp->next = del_ptr->next;
        if ( del_ptr == lastNode ) { lastNode = tmp; }
    }

    delete del_ptr;
    this->listSize--;
}

/* 
 * Insert theElement which index is theIndex
 */
template <typename T>
void extendedChain<T>::insert( int theIndex, const T& theElement )
{
    if ( theIndex < 0 || theIndex > this->listSize ){
        throw -2;
    }

    // firstnode
    if ( theIndex == 0 ){
        this->firstNode = new chainNode<T>( theElement, this->firstNode );
        if ( this->listSize == 0) { lastNode = this->firstNode; }
    }
    else
    {
        chainNode<T>* ptr = this->firstNode;   
        for ( int i=0; i<theIndex-1; ++i ){
            ptr =  ptr->next;
        }
        ptr->next = new chainNode<T>( theElement, ptr->next );
    }

    this->listSize++;
}
/* 
 * Insert theElement at the end of the chain
 */
template <typename T>
void extendedChain<T>::push_back( const T& theElement )
{
    chainNode<T>* newNode = new chainNode<T>( theElement );
    if ( ! this->firstNode ){
        // empty
        this->firstNode = newNode;
    }else
    {
        chainNode<T>* ptr = this->firstNode;
        // finally ptr->node[size()-1]
        for ( int i=0; i<size()-1; ++i ){
            ptr = ptr->next;
        }
        ptr->next = newNode;
    }
    lastNode = newNode;

    this->listSize++;
}

// template <typename T>
// void extendedChain<T>::output( std::ostream &out ) const
// {
//     std::cout << "call extendedChain output(): ";
//     if ( empty() ){
//         // empty
//         out << "This exChain is empty. ";
//     }else{
//         chainNode<T>* ptr = this->firstNode;
//         for ( int i=0; i<size(); ++i ){
//             out << ptr->element << " ";
//             ptr = ptr->next;
//         }
//     }
//     out << std::endl;
// }

/* 
 *  Merge two extendedChain ec_a & ec_b
 *  Out exChain will be sequential like ec_a and ec_b
 */
template <typename T>
void extendedChain<T>::merge( extendedChain<T>& ec_a, extendedChain<T>& ec_b )
{
    if ( !empty() ){
        clear();
    }

    chainNode<T> *ptr_a = ec_a.firstNode,
                 *ptr_b = ec_b.firstNode;
    while ( ptr_a || ptr_b ){
        if ( ! ptr_a ){
            // end of ec_a, push_back ptr_a element
            push_back( ptr_b->element );
            // move ec_b pointer
            ptr_b = ptr_b->next;
        }else if ( ! ptr_b ){
            // end of ec_b, push_back ptr_b element
            push_back( ptr_a->element );
            // move ec_a pointer
            ptr_a = ptr_a->next;
        }else{
            // push_back min value
            if ( ptr_a->element <= ptr_b->element ){
                // push_back ec_a element
                push_back( ptr_a->element );
                ptr_a = ptr_a->next;
            }else{
                // push_back ec_b element
                push_back( ptr_b->element );
                ptr_b = ptr_b->next;
            }
        }
    }
}

/* 
 *  Split this exChain into ec_a and ec_b.
 *  This chain will not change.
 */
template <typename T>
void extendedChain<T>::
split( extendedChain<T>& ec_a, extendedChain<T>& ec_b ) const
{
    int index = 0;
    chainNode<T> *ptr = this->firstNode;
    while ( ptr ){
        if ( index&1 ){
            // true --> even
            ec_a.push_back( ptr->element );
        }else{
            // odd
            ec_b.push_back( ptr->element );
        }

        // loop
        ptr = ptr->next;
        index++;
    }
}


/* 
 *  Do leftshift theIndex times on extendChain elements.
 *  Example:
 *          L=[ 0, 1, 2, 3, 4];
 *          L.circularShift( 2 );
 *          L=[ 2, 3, 4, 0, 1];
 */
template <typename T>
void extendedChain<T>::circularShift( int theIndex )
{
    // When theIndex >= listSize, it can be optimized
    int realIndex = theIndex % this->listSize;
    for ( int i=0; i<realIndex; ++i ){
        // one loop will do shift once
        lastNode->next = this->firstNode;
        this->firstNode = this->firstNode->next;
        lastNode->next->next = 0;
        lastNode = lastNode->next;
    }
}

template <typename T>
std::ostream& operator<<( std::ostream& out, const extendedChain<T>& x )
{
    x.output( out );
    return out;
}

#endif