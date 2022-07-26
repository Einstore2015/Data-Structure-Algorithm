#include "linkedStack.h"

void testBasic()
{
    std::cout << "*******************" << std::endl;
    std::cout << "Begin testBasic(): " << std::endl;
    linkedStack<int> s1;
    s1.push(11); s1.push(22); s1.push(33);
    std::cout << s1;
    s1.pop();
    std::cout << s1;
}

int main()
{
    testBasic();
}