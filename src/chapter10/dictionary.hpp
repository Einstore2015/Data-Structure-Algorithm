#ifndef _DICT_H
#define _DICT_H

template <typename K, typename E>
class dictionary
{
public:
    virtual ~dictionary() {}
    // return True if dict is empty
    virtual bool empty() const = 0;
    // return the number of key-value pairs
    virtual int size() const = 0;
    // return the pointer of target pair
    virtual pair<const K, E>* find(const K&) const = 0;
    // delete the target pair
    virtual void erase(const K&) = 0;
    // insert a pair
    virtual void insert(const pair<const K, E>&) = 0;
};

#endif