#include "doublyLinkedList.h"

int main()
{
    doublyLinkedList<int> dll;

    dll.push_back( 1 );
    dll.push_back( 2 );
    dll.push_back( 3 );
    std::cout << dll;
    dll.reverse();
    std::cout << "after reverse(): ";
    std::cout << dll;
    dll.header_insert( 0 );
    std::cout << "header_insert( 0 ): ";
    std::cout << dll;

}