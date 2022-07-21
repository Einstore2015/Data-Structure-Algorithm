#ifndef _CHAIN_H
#define _CHAIN_H

#include <exception>
#include "linearList.h"
#include "chainNode.h"

template <typename T>
class Chain : public linearList<T>
{
public:
    Chain( int initialCapacity = 10 );
    Chain( const Chain<T>& );
    ~Chain(); 

    // abstract function
    bool empty() const
        { return listSize == 0; }
    int  size() const    
        { return listSize; }
    void setSize( int theSize );
    T&   get( int theIndex ) const; 
    void set( int theIndex, const T& theElement );
    int  indexOf( const T& theElement ) const;
    int  lastIndexOf( const T& theElement ) const;
    void erase( int theIndex );
    void removeRange( int fromIndex, int toIndex );
    void insert( int theIndex, const T& theElement );
    void output( std::ostream& out ) const;
    void clear();

    // additional function
    void swap( Chain<T>& y );
    void leftShfit( int i );
    void reverse();
    void meld( Chain<T>& chain_a, Chain<T>& chain_b );
    void merge( Chain<T>* c_a, Chain<T>* c_b );
    void split( Chain<T>& c_a, Chain<T>& c_b );
    void binSort( int range );

    // operator
    T&   operator[] ( int theIndex );
    T    operator[] ( int theIndex ) const;
    bool operator== ( const Chain<T>& y ) const;
    bool operator!= ( const Chain<T>& y ) const;

protected:
    void mycheckIndex( int theIndex ) const;
    chainNode<T>* firstNode;
    int listSize;
};


/* 
 *  Constructor
 *  Default value of initialCapacity is 10.
 */
template <typename T>
Chain<T>::Chain( int initialCapacity )
{
    if ( initialCapacity < 1 ){
        throw -1;
    }
    firstNode = 0;
    listSize = 0;
}


/*
 *  Copy constructor
 */
template <typename T>
Chain<T>::Chain( const Chain<T>& theList )
{
    listSize = theList.listSize;

    if ( listSize ==0 ){
        firstNode = 0;
        return;
    }
    // non-empty
    firstNode = theList.firstNode;
    chainNode<T> *cur = theList.firstNode->next,    // pointer theList
                 *ptr = firstNode;                  // pointer this ; cur is 1- ahead of ptr
    while ( cur )
    {
        ptr->next = cur;
        ptr = ptr->next;

        cur = cur->next;
    }
}


/* 
 *  Deconstructor
 *  delete all chainNode
 */
template <typename T>
Chain<T>::~Chain()
{
    // to be delete
    std::cout << "~~~~~" << std::endl;

    while ( firstNode ){
        chainNode<T> *del_ptr = firstNode;
        firstNode = del_ptr->next;
        std::cout << del_ptr->element << " ";
        delete del_ptr;
    }
    std::cout << std::endl;
}


/* 
 *  return -> reference of element whose index is theIndex
 */
template <typename T>
T& Chain<T>::get( int theIndex ) const
{
    mycheckIndex( theIndex );

    chainNode<T>  *cur = firstNode;
    for (int i=0; i<theIndex; ++i ){
        cur = cur->next;
    }
    
    return cur->element;
}


/*
 * return the first index of theElement
 * if not exist return -1
 */
template <typename T>
int Chain<T>::indexOf( const T& theElement ) const
{
    chainNode<T> *cur = firstNode;
    int index = 0;

    while ( cur && cur->element != theElement )
    {
        cur = cur->next;
        index++;
    }

    // not exist
    if ( !cur ){
        return -1;
    }else{
        return index;
    }
}


/*
 *  Return the rightest index of theElment
 *  If not exists, return -1 
 */
template <typename T>
int Chain<T>::lastIndexOf( const T& theElement ) const
{
    chainNode<T>* ptr = firstNode;
    int index=0, out_index = -1;
    while ( ptr ){
        if ( ptr->element == theElement ){
            out_index = index;
        }
        index++;
        ptr = ptr->next;
    }

    return out_index;
}


/* 
 * delte Node[index]
 */
template <typename T>
void Chain<T>::erase( int theIndex )
{
    mycheckIndex( theIndex );

    // find the Node[index]
    chainNode<T> *del_ptr = firstNode;
    if ( theIndex == 0 ){   
        // delete firstNode
        firstNode = del_ptr->next;
    }else{
        // ptr --> Node[index-1]
        chainNode<T> *tmp = firstNode;
        for ( int i=0; i<theIndex-1; ++i ){
            // tmp = tmp->next;
            tmp = tmp->next;
        }
        del_ptr = tmp->next;
        tmp->next = del_ptr->next;
    }

    delete del_ptr;

    // change self listSize
    listSize--;
}


/* 
 *  
 */
template <typename T>
void Chain<T>::insert( int theIndex, const T& theElement )
{
    // illegal theIndex
    if ( theIndex < 0 || theIndex > listSize ){
        throw -1;
    }

    // insert a new Node
    if ( theIndex == 0 ){
        // first
        firstNode = new chainNode<T>( theElement, firstNode );
    }else{
        chainNode<T> *ptr = firstNode;
        // ptr ---> Node[theIndex-1]
        for ( int i=0; i<theIndex-1; ++i ){
            ptr = ptr->next;
        }
        ptr->next = new chainNode<T>( theElement, ptr->next );
    }

    // change self listSize
    listSize++;
}


/* 
 *  Set this->listSize to theSize
 *  if original size < theSize, don't insert new elements
 *  if size > theSize, delete extra elements
 */
template <typename T>
void Chain<T>::setSize( int theSize )
{
    // examine
    if ( theSize < 0){
        throw "theSize is less than 0";
    }

    if ( listSize < theSize ){
        listSize = theSize;
    }else{
        // reach node[theSize-1]
        chainNode<T>* ptr = firstNode;
        for ( int i=0; i<theSize-1; ++i ){
            ptr = ptr->next;
        }
        ptr->next = 0;

        // delte extra elements
        ptr = ptr->next;
        while ( ptr ){
            chainNode<T>* del_ptr = ptr;
            ptr = ptr->next;
            delete del_ptr;
        }
    }
}


/* 
 *  Replace the element which index is theIndex
 *  with theElement
 */
template <typename T>
void Chain<T>::set( int theIndex, const T& theElement )
{
    mycheckIndex( theIndex );

    // reach node[theIndex]
    chainNode<T>* ptr = firstNode;
    for ( int i=0; i<theIndex; ++i ){
        ptr = ptr->next;
    }
    ptr->element = theElement;
}


/* 
 *  Delete elements with index within [fromIndex, toIndex]
 */
template <typename T>
void Chain<T>::removeRange( int fromIndex, int toIndex )
{
    // examine validity of index
    mycheckIndex( fromIndex );
    mycheckIndex( toIndex );
    if ( toIndex < fromIndex ){
        throw -3;
    }

    chainNode<T> *ptr = firstNode; 
    if ( fromIndex == 0 ){
        // if fromIndex == 0 , change the firstNode
        // move ptr to node[toIndex+1]
        for ( int i=0; i<toIndex+1; ++i ){
            // delete extra nodes
            chainNode<T>* del_ptr = ptr;
            ptr = ptr->next;
            delete del_ptr;
        }

        // attach
        firstNode = ptr;
    }else{
        chainNode<T> *tail, *head;
        // after this loop ptr will reach node[fromIndex-1]
        for (int i=0; i<fromIndex-1; ++i ){
            ptr = ptr->next;
        }
        tail = ptr;

        ptr = ptr->next;    // ptr -> node[fromIndex]
        // move ptr to node[toIndex+1]
        // toIndex - fromIndex + 1 times
        for (int i=0; i<toIndex-fromIndex+1; ++i ){
            chainNode<T>* del_ptr = ptr;
            ptr = ptr->next;
            delete del_ptr;
        }
        head = ptr;

        // attach
        tail->next = head;
    }

}


/* 
 *  Clear.
 *  All nodes of this chain will be deleted.
 *  Set firstNode and listSize to 0.
 */
template <typename T>
void Chain<T>::clear()
{
    if ( firstNode ){
        chainNode<T> *ptr = firstNode;
        while ( ptr ){
            chainNode<T> *del_ptr = ptr;
            ptr = ptr->next;
            delete []del_ptr;
        }

        firstNode = 0; listSize = 0;
    }else{
        return;
    }
}

template <typename T>
void Chain<T>::output( std::ostream& out ) const
{
    std::cout << " output(): ";
    if ( firstNode ){
        for ( chainNode<T> *cur = firstNode;
                            cur;
                            cur = cur->next )
        {
            out << cur->element << " ";
        }
    }else{
        // empty
        std::cout << "Chain is empty." << std::endl;
    }
    out << std::endl;
}

template <typename T>
void Chain<T>::mycheckIndex( int theIndex ) const
{
    if ( theIndex < 0 || theIndex > listSize-1 ){
        throw -1;
    }

    return;
}


/* 
 *  Swap this chain and swapChain
 */
template <typename T>
void Chain<T>::swap( Chain<T>& swapChain )
{
    chainNode<T> *tmp = this->firstNode;
    this->firstNode = swapChain.firstNode;
    swapChain.firstNode = tmp;
}


/* 
 *  
 */
template <typename T>
void Chain<T>::reverse()
{
    if ( size() == 0 || size() == 1 ){
        return;
    }

    chainNode<T>* nodeList[size()];
    chainNode<T>* ptr = firstNode;
    int index = 0;

    while ( ptr->next ){
        nodeList[index] = ptr;
        index++;
        ptr = ptr->next;
    }   // index = size()-1

    firstNode = ptr;
    for ( --index; index>=0; index-- ){
        ptr->next = nodeList[index];
        ptr = ptr->next;
    }
    // end of chain
    ptr->next = 0;
}


/* 
 * Elements do leftshift i times
 */
template <typename T>
void Chain<T>::leftShfit( int i )
{
    if ( i > listSize || i < 0 ){
        throw -3;
    }else if( i == listSize ){
        listSize == 0; firstNode = 0;
        return;
    }else if( i == 0 ){
        return;
    }

    chainNode<T> *ptr = firstNode;
    for ( int ix=0; ix<i; ++ix ){
        chainNode<T> *del_ptr = ptr;
        ptr = ptr->next;
        delete del_ptr;
    }

    // reset firstNode, listSize
    firstNode = ptr; listSize = listSize - i;
}


/* 
 *  Merge input chain_a and chain_b
 */
template <typename T>
void Chain<T>::meld( Chain<T>& chain_a, Chain<T>& chain_b )
{
    // if this chain is not empty, do clear()
    if ( ! empty() ){
        clear();
    }
    /* 
    if ( chain_a.empty() && chain_b.empty() ){
        firstNode = 0; listSize = 0;
    }else if ( chain_a.empty() ){
        firstNode = chain_b.firstNode; listSize = chain_b.size();
    }else if ( chain_b.empty() ){
        firstNode = chain_a.firstNode; listSize = chain_a.size();
    }else{
        chainNode<T> *ptr = firstNode,
                     *ptr_a = chain_a.firstNode,
                     *ptr_b = chain_b.firstNode;
        while ( ptr_a || ptr_b ){
            // chain_a
            if ( ptr_a ){
                if ( !firstNode ){
                    ptr = firstNode = ptr_a;
                }else{
                    ptr->next = ptr_a;
                    ptr = ptr->next;
                }
                ptr_a = ptr_a->next;
            }
            // chain_b
            if ( ptr_b ){
                ptr->next = ptr_b;
                ptr = ptr->next;
                ptr_b = ptr_b->next;
            }
        }

        ptr->next = 0; listSize = chain_a.size() + chain_b.size();
        chain_a.firstNode = 0; chain_b.firstNode = 0;

        //clear chain_a & chain_b
        chain_a.clear(); chain_b.clear();
    }
     */

    chainNode<T> *ptr   = firstNode,
                 *ptr_a = chain_a.firstNode,
                 *ptr_b = chain_b.firstNode;
    while ( ptr_a || ptr_b ){
        // chain_a
        if ( ptr_a ){
            if ( !firstNode ){
                ptr = firstNode = ptr_a;
            }else{
                ptr->next = ptr_a;
                ptr = ptr->next;
            }
            ptr_a = ptr_a->next;
        }
        // chain_b
        if ( ptr_b ){
            if ( !firstNode ){
                ptr = firstNode = ptr_b;
            }else{
                ptr->next = ptr_b;
                ptr = ptr->next;
            }
            ptr_b = ptr_b->next;
        }
    }
    ptr->next = 0;
    listSize = chain_a.size() + chain_b.size();
    chain_a.firstNode = chain_b.firstNode = 0;
    chain_a.listSize = chain_b.listSize = 0;
}


/* 
 *  Merge two input chain sequentially
 *  c_a & c_b will be empty after this function procedure
 */
template <typename T>
void Chain<T>::merge( Chain<T>* c_a, Chain<T>* c_b )
{
    chainNode<T> *header = new chainNode<T>(),
                 *ptr    = header,
                 *p_a    = c_a->firstNode,
                 *p_b    = c_b->firstNode;
    int newSize = c_a->size() + c_b->size();

    while ( p_a && p_b ){
        if ( p_a->element <= p_b->element ){
            // link c_a node
            ptr->next = p_a;
            ptr = ptr->next;
            p_a = p_a->next;
        }else{
            // link c_b node
            ptr->next = p_b;
            ptr = ptr->next;
            p_b = p_b->next;
        }
    }

    if ( !p_a ){
        // end of c_a, link c_b
        ptr->next = p_b;
    }else{
        // end of c_b, link c_a
        ptr->next = p_a;
    }

    // delte
    firstNode = header->next;
    delete header;

    listSize = newSize;
    c_a->firstNode = 0; c_b->firstNode = 0;
    c_a->listSize  = 0; c_b->listSize  = 0;
}


/* 
 *  Split this chain into c_a & c_b
 *  c_a & c_b will use the space of this chain;
 *  Zero this chain after this function.
 */
template <typename T>
void Chain<T>::split( Chain<T>& c_a, Chain<T>& c_b )
{
    int index = 0;
    chainNode<T>    *ptr = firstNode,
                    *p_a = c_a.firstNode,
                    *p_b = c_b.firstNode;
    while ( ptr ){
        if ( index&1 ){
            // true -> even
            if ( !p_a ){
                p_a = c_a.firstNode = ptr;
                ptr = ptr->next;
                c_a.listSize++;
            }else{
                p_a->next = ptr;
                ptr = ptr->next;
                p_a = p_a->next;
                c_a.listSize++;
            }
        }else{
            // false -> odd
            if ( !p_b ){
                p_b = c_b.firstNode = ptr;
                ptr = ptr->next;
                c_b.listSize++;
            }else{
                p_b->next = ptr;
                ptr = ptr->next;
                p_b = p_b->next;
                c_b.listSize++;
            }
        }
        // loop
        index++;
    }

    firstNode = 0; listSize = 0;
}


template <typename T>
void Chain<T>::binSort( int range )
{
    chainNode<T> **bottom, **top;
    bottom = new chainNode<T>* [range+1];
    top    = new chainNode<T>* [range+1];

    // initialize buckets
    for ( int b=0; b<=range; b++ ){
        bottom[b] = 0;
    }

    for ( ; firstNode != 0; firstNode = firstNode->next ){
        // bucket index
        int theBin = firstNode->element;
        if ( theBin > range ){
            std::cout << "Wrong range scale !";
            std::cout << "Bigger range needed." << std::endl;
            exit(-1);
        }
        // set
        if ( bottom[theBin] == 0 ){
            //  empty bucket
            bottom[theBin] = top[theBin] = firstNode;
        }else{
            // 
            top[theBin]->next = firstNode;   
            top[theBin] = firstNode;
        }
    }

    // link all buckets
    chainNode<T> *tmp;
    for ( int b=0; b<=range; b++ ){
        // befor this loop, firstNode = 0
        if ( bottom[b] ){
            // firstNode point to the first non-empty bucket
            // if bucket[b] is not empty:
            if ( firstNode == 0 ){
                // first non-empty bucket
                firstNode = bottom[b];
                tmp = top[b];
            }else{
                tmp->next = bottom[b];
                tmp = top[b];
            }
        }       
    }
    // end of chain
    if ( tmp ){
        tmp->next = 0;
    }
}

/*
 * ##############################################################
 *                          OPERATORS 
 * ##############################################################
 */

/* 
 *  Left value
 */
template <typename T>
T& Chain<T>::operator[] ( int theIndex )
{
    chainNode<T>* ptr = firstNode;
    // ptr -> node[theIndex]
    for ( int i=0; i<theIndex; ++i ){

        ptr = ptr->next;
    }
    return ptr->element;
}


/* 
 *  Right value
 */
template <typename T>
T Chain<T>::operator[] ( int theIndex ) const
{
    chainNode<T>* ptr = firstNode;
    // node[theIndex]
    for ( int i=0; i<theIndex; ++i ){
        ptr = ptr->next;
    }
    return ptr->element;
}


/* 
 *  
 */
template <typename T>
bool Chain<T>::operator== ( const Chain<T>& compChain ) const
{
    if ( this->listSize != compChain.listSize ){
        return false;
    }

    chainNode<T> *x=this->firstNode, *y=compChain.firstNode;
    while ( x ){
        if ( x->element != y->element ){
            return false;
        }
        x = x->next; y = y->next;
    }

    return true;
}


/* 
 *  
 */
template <typename T>
bool Chain<T>::operator!= ( const Chain<T>& compChain ) const
{
    return !this->operator==( compChain );
}

template <typename T>
std::ostream& operator<<( std::ostream& out, const linearList<T>& x )
{
    x.output( out );
    return out;
}


#endif