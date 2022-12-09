#include "myQueue.h"

int main()
{
    myQueue<int> m1;
    for ( int i=1; i < 12; i++ ){
        m1.push(i);
    }
    std::cout << m1;
    std::cout << m1.length() << " " << m1.size();
}