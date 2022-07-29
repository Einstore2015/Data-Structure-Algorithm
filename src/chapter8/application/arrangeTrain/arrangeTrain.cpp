#include "..\..\arrayStack.h"
#include "train.h"
#include "carriages.h"

int main()
{
    arrayStack<int> train;
    int numOfCars, numOfTracks;
    numOfCars   = 100;
    numOfTracks = 30;
        
    // train.push( 8 );
    // train.push( 7 );
    // train.push( 5 );
    // train.push( 10 );
    // train.push( 1 );
    // train.push( 6 );
    // train.push( 4 );
    // train.push( 3 );
    // train.push( 2 );
    // train.push( 9 );

    generateTrain( numOfCars, &train );
    arrangeCars( numOfCars, numOfTracks, train, false );
}