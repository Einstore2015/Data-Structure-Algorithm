#include <iostream>
#include "..\arrayStack.h"

bool checkBox( int net[], int n )
{
    arrayStack<int>* s = new arrayStack<int>( n );

    for ( int i=0; i < n; i++ ){
        if ( !s->empty() ){
            if ( net[i] == net[ s->top() ]){
                s->pop();
            }else{
                s->push(i);
            }
        }else{
            s->push(i);
        }
    }

    if ( s->empty() ){
        std::cout << "Switch box is routable" << std::endl;
        return false;
    }

    std::cout << "Swithc box is not routable" << std::endl;
    return true;
}

int main()
{

    return 0;
}