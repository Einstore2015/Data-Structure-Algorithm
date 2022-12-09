#include "narrayQueue.h"

#include <iostream>

class test
{
public:
    test() {}
    test( int input ) { value = input; }
    ~test()
    {
        std::cout << "Test's deconstructor" << value << std::endl;
    }
protected:
    int value;
};

int main()
{
    newQueue<int> n1;

    for ( int i=1; i<12; i++ ){
        n1.push(i);
    }
    std::cout << n1.front() << std::endl;
    std::cout << n1.back()  << std::endl;
    std::cout << n1;

    newQueue<test> nt;
    // test a = test(1), b = test(2), c = test(3);
    test a(1), b(2), c(3);
    nt.push(a); nt.push(b); nt.push(c);
    nt.pop(); nt.pop(); nt.pop();
    std::cout << "******" << std::endl;
}