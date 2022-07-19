#include <iostream>
#include "chain.h"

template <typename T>
void reverseChain( Chain<T>& chain )
{
    chain.reverse();
}

int main()
{
    Chain<int> c, d, e;

    c.insert( 0, 12 );
    c.insert( 1, 13 );
    c.insert( 2, 20 );
    c.insert( 3, 33 );
    c.insert( 4, 44 );
    c.set( 0, 2222  );
    c.insert( 5, 2222 );
    std::cout << c;

    d.insert( 0, 30 );
    d.insert( 1, 31 );
    d.insert( 2, 32 );
    d.insert( 3, 33 );
    std::cout << d;
    
    // c.swap( d );
    // std::cout << c;
    // d.reverse();
    // reverseChain( d );
    // d.leftShfit(2);
    // std::cout << d;

    //meld
    // e.meld( c, d );
    // std::cout << e;

    std::cout << "***************" << std::endl;
    std::cout << "Chain merge() test:" << std::endl;
    std::cout << "c: " << c;
    std::cout << "d: " << d;

    e.merge( &c, &d );
    std::cout << "c: " << c;
    std::cout << "d: " << d;
    std::cout << "e: " << e;

    std::cout << "***************" << std::endl;
    std::cout << "Chain split() test:" << std::endl;
    c.clear(); d.clear();
    std::cout << c << d << e;
    e.split( c, d );
    std::cout << c << d << e;
    // c.setSize(1);
    // c.removeRange( 3,3 );
    // std::cout << "lastIndex: " << c.lastIndexOf( 22222 ) << std::endl;

    // c[0] = 100;int x=c[5];
    // std::cout << c;
    // std::cout << "x: " << x << std::endl;
    // std::cout << "bool: " << (c != d) << std::endl;

    std::cout << "***************" << std::endl;
    std::cout << "***************" << std::endl;
    std::cout << "***************" << std::endl;

}