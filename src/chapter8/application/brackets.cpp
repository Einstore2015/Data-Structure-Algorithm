#include <string>
#include <iostream>

#include "..\arrayStack.h"

void printMatchedParis( std::string expr )
{
    arrayStack<int> s;
    int length = (int) expr.size();

    for ( int i=0; i < length; i++ ){
        if ( expr.at(i) == '(' ){
            s.push(i);
        }else
        if( expr.at(i) == ')' ){
            try
            {// pop left bracket
                s.pop();
            }
            catch( stackEmpty )
            {
                std::cout << "No match for right bracket"
                            << " at " << i << std::endl;
            }
        }
    }

    while ( !s.empty() ){
        std::cout << "No match for left bracket at "
                    << s.top() << std::endl;
        s.pop();
    }
}

int main()
{
    printMatchedParis( "(a*(b+c)" );
}