#include <iostream>
#include "arrayStack.h"

void test_newpop()
{
    std::cout << "****************************" << std::endl;
    std::cout << "Begin test new pop(): " << std::endl;
    arrayStack<int> s;
    s.push( 2 );  s.push( 2 ); s.push( 2 ); s.push( 2 );
    s.push( 2 );  s.push( 2 ); s.push( 2 ); s.push( 2 );
    s.push( 3 );

    std::cout << s;
    for( int i=0; i<8; i++){
        s.pop();
        std::cout << s << "s.size(): " << s.size();
        std::cout << " s.capa(): " << s.capa() <<std::endl;
    }
}

void test_split()
{
    std::cout << "****************************" << std::endl;
    std::cout << "Begin test split(): " << std::endl;
    arrayStack<int> s1, s2;

    s1.push( 1 ); s1.push( 2 ); s1.push( 3 );

    std::cout << s1;
    s1.split( s1, s2 );
    std::cout << s1 << s2;
}

int main()
{
    test_split();
    test_newpop();

}