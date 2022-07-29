#include <iostream>
#include "derivedLinkedStack.h"

void test_basic()
{
    derivedLinkedStack<int> s1;

    s1.push( 111 ); s1.push( 222 ); s1.push( 333 );
    std::cout << s1.empty() << std::endl;
    std::cout << s1.size() << std::endl;
    s1.pop();
    std::cout << s1;
}

int main()
{
    test_basic();
}