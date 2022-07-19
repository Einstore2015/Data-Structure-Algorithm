#ifndef _LINEARLIST_H
#define _LINEARLIST_H
#include <iostream>

template <typename T>
class linearList
{
public:
    virtual ~linearList() {}
    virtual bool empty() const = 0;
    virtual int size() const = 0;
                // return the element[index]
    virtual T& get( int theIndex ) const = 0;
                // return the first index of given element
    virtual int indexOf( const T& theElement ) const = 0;
                // delete element[index]
    virtual void erase( int theIndex ) = 0;
                // insert given element to [index]
    virtual void insert( int theIndex, const T& theElement ) = 0;
                // output stream
    virtual void output( std::ostream & out ) const = 0;
};

template <typename T>
class extendedLinearList : linearList<T>
{
public:
    virtual ~extendedLinearList() {}
    virtual void clear() = 0;
    virtual void push_back( const T& theElement ) = 0;
};

#endif