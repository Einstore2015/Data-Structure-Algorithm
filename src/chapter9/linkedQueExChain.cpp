#include "arrayQueue.h"
#include "linkedQueExChain.h"

#include <ctime>

double countTime(void (*func)(int), int times)
{
    std::clock_t start, end;
    start = std::clock();
    func(times);
    end = std::clock();

    double runtime = (double)(end-start)/CLOCKS_PER_SEC; // seconds
    return runtime;
}

void loopLinkedQueue(int times)
{
    linkedQueExChain<int> lq;
    for (int i=0; i < times; i++){
        lq.push(1);
    }
}

void loopArrayQueue(int times)
{
    arrayQueue<int> aq;
    for (int i=0; i < times; i++){
        aq.push(1);
    }
}

void test1(void)
{
    double t1, t2;
    int times = 1000000;
    t1 = countTime(loopLinkedQueue, times);
    t2 = countTime(loopArrayQueue, times);
    std::cout << "linkedQueue: " << t1;
    std::cout << "arrayQueue: " << t2;
}

void loopPush(int times)
{
    linkedQueExChain<int> lq;

    for (int i=0; i < times; i++){
        lq.push(1);
    }
    for (int i=0; i < times; i++){
        lq.pop();
    }

}
void loopPushNode(int times)
{
    linkedQueExChain<int> lq;

    for (int i=0; i < times; i++){
        lq.pushNode(new chainNode<int>(i));
    }
    for (int i=0; i < times; i++){
        lq.popNode();
    }
}

void test2(void)
{
    linkedQueExChain<int> lq, lq2;
    std::cout << "Running test2" << std::endl;

    double t1, t2;
    int times = 1000000;
    t1 = countTime(loopPush, times);
    std::cout << "t1 finished" << std::endl;
    t2 = countTime(loopPushNode, times);
    std::cout << "t2 finished" << std::endl;
    std::cout << "push: " << t1 << std::endl;
    std::cout << "node: " << t2 << std::endl;
}

int main()
{
    test2();
}