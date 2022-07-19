#include <iostream>
#include "extendedChain.h"


int main()
{
    extendedChain<int> e1, e2, e3;

    std::cout << "***************" << std::endl;
    std::cout << "extendedChain merge() test:" << std::endl;
    e1.push_back(1);
    e1.push_back(4);
    e1.push_back(10);
    e2.push_back(2);
    e2.push_back(3);
    e2.push_back(20);
    std::cout << e1;
    std::cout << e2;

    e3.merge( e1, e2 );
    std::cout << e3;

    std::cout << "***************" << std::endl;
    std::cout << "exChain split()" << std::endl;
    e1.clear(); e2.clear();
    std::cout << e1 << e2 << e3;

    e3.split( e1, e2 );
    std::cout << e1 << e2 << e3;

    std::cout << "***************" << std::endl;
    std::cout << "exChain circularShift()" << std::endl;
    std::cout << e1;   
    e1.circularShift(4);
    std::cout << e1;   

}