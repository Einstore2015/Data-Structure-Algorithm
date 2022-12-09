#ifndef _SORT_A_L
#define _SORT_A_L

#include "dictionary.hpp"
// #include "pairNode.hpp"

template<typename K, typename E>
class sortedArrayList : public dictionary<K, E>
{
public:
    sortedArrayList();
    ~sortedArrayList();

    bool empty() const;
    pair<K, E>* find(const K&) const;
};

template<typename K, typename E>
sortedArrayList<K, E>::sortedArrayList()
{

}


template<typename K, typename E>
bool sortedArrayList<K, E>::empty() const
{

}


template<typename K, typename E>
std::pair<K, E>* sortedArrayList<K, E>::find(const K&) const
{

}

#endif