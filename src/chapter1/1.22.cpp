#include <iostream>
#include <math.h>

int arkerMann( int i, int j)
{
    std::cout << "i: " << i << " " << "j: " << j << std::endl;
    if ( i==1 ){
        return pow(2,j);
    }
    else if ( j==1 ){
        return arkerMann(i-1, 2);
    }else{
        return arkerMann(i-1,arkerMann(i,j-1));
    }
}

int main()
{
    std::cout << arkerMann(4,2);
}