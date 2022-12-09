#include "dequeStack.h"

int main()
{
    dequeStack<int> ds;

    for (int i=1; i<=11; i++){
        ds.push(i);
        std::cout << "top: " << ds.top() << std::endl;
    }
    std::cout << ds;
    ds.pop(); ds.pop();
    std::cout << ds;
}