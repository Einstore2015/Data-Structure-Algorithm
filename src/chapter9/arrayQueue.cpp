#include "arrayQueue.h"

int main()
{
    arrayQueue<int> queue, queue2, queue3;
    std::cout << queue;
    queue.push(1); queue.push(2); queue.push(3); queue.push(4);
    queue.push(5); queue.push(6); queue.push(7); queue.push(8);
    queue.push(9); queue.push(10); queue.push(11); queue.push(12);
    std::cout << queue;
    std::cout << queue.front() << std::endl;
    queue2 << queue;
    std::cout << queue2;
    queue.splitInto( queue2, queue3 );
    std::cout << queue2 << queue3;

}