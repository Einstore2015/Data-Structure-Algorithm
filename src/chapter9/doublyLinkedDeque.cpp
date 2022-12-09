#include "doublyLinkedDeque.h"

int main()
{
    doublyLinkedDeque<int> dq;

    for (int i=1; i < 7; i++){
        dq.push_back(i);
    }
    std::cout << dq.back();
}