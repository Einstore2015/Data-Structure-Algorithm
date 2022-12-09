#include "arrayDeque.h"

int main()
{
    arrayDeque<int> d;

    for (int i=1; i <= 11; i++){
        d.push_back(i);
    }
    d.push_front(12);
    d.pop_back();
    std::cout << d;
    d.pop_front();
    std::cout << d;
}