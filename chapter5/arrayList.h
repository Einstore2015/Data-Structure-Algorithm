#ifndef ARRAY_H
#define ARRAY_H

template <typename T>
class linearList{
public:
    virtual ~linearList() {};
    virtual bool empty() const = 0;
    virtual int size() cosnt = 0;
    virtual T& get( int theIndex ) const = 0;
    virtual int indexOf( const T& theElement ) const = 0;
};

#endif