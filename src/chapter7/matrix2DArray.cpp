#include <iostream>
#include "matrix2DArray.h"

template <typename T>
void printM( const Matrix2DArray<T>& m )
{
    for ( int i=1; i<=m.rows(); i++ ){
        for ( int j=1; j<=m.cols(); j++ ){
            std::cout << m(i,j) << " "; 
        }
        std::cout << std::endl;
    }
}

int main()
{
    Matrix2DArray<int> m1(2,2), m2(2,3), m3(3,3);

    /* Matrix initilize */
    m1(1,1) = 1; m1(1,2) = 2;
    m1(2,1) = 3; m1(2,2) = 4;

    m2(1,1) = 5; m2(1,2) = 6, m2(1,3) = 1;
    m2(2,1) = 7; m2(2,2) = 8, m2(2,3) = 1;

    printM( m1 ); printM( m2 );
    std::cout << "*******" << std::endl;
    m3 = m1 * m2;
    printM( m3 );
    std::cout << "*******" << std::endl;
    m3 -=10;
    printM( m3 );
    std::cout << "*******" << std::endl;
    printM( m3.tranpose() );
}