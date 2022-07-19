#include "moveLeftAndRightOnChain.h"

int main()
{
    moveChain<int> m;

    m.insert( 0, 0 );
    m.insert( 1, 1 );
    m.insert( 2, 2 );
    m.insert( 3, 3 );
    m.insert( 4, 4 );
    std::cout << m.size() << std::endl;
    std::cout << m;

    m.moveRight();
    std::cout << "p: " << m.currentElement() << " ";
    std::cout << "l: " << m.previousElement() << " ";
    std::cout << std::endl;

    m.moveRight();
    std::cout << "p: " << m.currentElement() << " ";
    std::cout << "l: " << m.previousElement() << " ";
    std::cout << std::endl;

    m.moveRight();
    std::cout << "p: " << m.currentElement() << " ";
    std::cout << "l: " << m.previousElement() << " ";
    std::cout << std::endl;

    m.moveLeft();
    std::cout << "p: " << m.currentElement() << " ";
    std::cout << "l: " << m.previousElement() << " ";
    std::cout << std::endl;

    m.moveLeft();
    std::cout << "p: " << m.currentElement() << " ";
    std::cout << "l: " << m.previousElement() << " ";
    std::cout << std::endl;
}