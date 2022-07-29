#include <iostream>
#include "..\arrayStack.h"

/* 
 *  Remove the top n disks on tower X to tower Y
 *  use tower z as transfer station
 *  x -> initial tower
 *  y -> target tower
 *  z -> transfer station
 */
void towerRecursion( int n, int x, int y, int z )
{
/*     std::cout << '"' << "Moving " << n << " disks from "
                << "Tower " << x << " to Tower "
                << y << " ." << '"' << std::endl; */
    if ( n > 1 ){
        towerRecursion( n-1, x, z, y );
        towerRecursion( 1, x, y, z );
        towerRecursion( n-1, z, y, x );
    }else if (n == 1 ){
        std::cout << "Only one disk needs to be moved "
                    << "from Tower " << x << " to Tower "
                    << y << std::endl;
    }else{
        return;
    }
}

/* Forward declaration */
void moveTower( int n, int x, int y, int z, arrayStack<int> tower[] );
void printTowers( arrayStack<int> tower[] );

/* 
 * 
 *  Solve HanoiTower problem using Stack
 *  n  --> number of disks
 *  x  --> initial tower,       default = 1
 *  y  --> target tower,        default = 3
 *  z  --> transfer station,    default = 2
 */
void towerStack( int n, int x = 1, int y = 3, int z = 2 )
{
    // Create tower stacks
    arrayStack<int> tower[4];
    // Initialize stacks
    for ( int i = n; i > 0; i-- ){
        tower[x].push(i);
    }
    printTowers( tower );
    moveTower( n, x, y, z, tower );


}

/* 
 *  
 *  n  --> number of disks
 *  x  --> initial tower
 *  y  --> target tower
 *  z  --> transfer station
 */
void moveTower( int n, int x, int y, int z, arrayStack<int> tower[] )
{
    if ( n > 1 ){
        moveTower( n-1, x, z, y, tower );
        moveTower(   1, x, y, z, tower );
        moveTower( n-1, z, y, x, tower );
    }else if ( n == 1 ){
        // move one disk
        int tmp = tower[x].top();
        tower[x].pop();
        tower[y].push( tmp );
        // print towers
        printTowers( tower );
    }else{
        return;
    }
}

inline void printTowers( arrayStack<int> tower[] )
{
    std::cout << "***************" << std::endl;
    std::cout << "Tower 1: " << tower[1];
    std::cout << "Tower 2: " << tower[2];
    std::cout << "Tower 3: " << tower[3];
}

int main()
{
    towerRecursion( 3, 1, 2, 3 );
    towerStack( 4, 1, 2, 3 );
}