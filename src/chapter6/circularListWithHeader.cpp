#include "circularListWithHeader.h"

int main()
{
    circularListWithHeader<int> cwh, cwh2, c;

    cwh.insert( 1 );
    cwh.insert( 3 );
    cwh.insert( 9 );
    cwh.insert( 2, 3 );
    cwh.push_back( 1111 );
    std::cout << cwh;

    cwh.reverse();
    std::cout << "Reverse(): \n" << cwh;

    cwh2.insert( 123 );
    cwh2.push_back( 1234 );
    cwh2.push_back( 44 );

    c.meld( cwh, cwh2 );
    std::cout << cwh << cwh2 << c;
}