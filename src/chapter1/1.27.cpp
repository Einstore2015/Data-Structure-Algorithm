#include <iostream>
#include <algorithm>
#include <numeric>

template <typename T>
T MySum( T list[], int beg, int end )
{
    T theSum = 0;
    return std::accumulate( list+beg-1, list+end, theSum );
}

int main()
{
    int il[4] = { 1, 2, 3, 4 };
    float fl[5] = { 1.2, 3.0, 3.3, -2., 0. };

    std::cout << "i : " << MySum( il, 2, 3 ) << std::endl;
    std::cout << "f : " << MySum( fl, 0, 2 ) << std::endl;
}