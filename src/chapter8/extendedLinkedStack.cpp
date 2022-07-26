#include "extendedLinkedStack.h"

int main()
{
    extendedLinkedStack<int> s1, s2, s3;

    s1.push( 1 ); s1.push( 2 ); s1.push( 3 ); s1.push( 4 );

    std::cout << s1;
    s1.split( &s2, &s3);
    std::cout << "s2: " << s2 << "s3: " << s3;

}