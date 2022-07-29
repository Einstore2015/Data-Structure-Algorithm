#include <iostream>
#include <time.h>
#include <vector>
#include "train.h"

void generateTrain( int n_cars, arrayStack<int>* train )
{
    /* Generta initial vec */
    std::vector<int> randomVec;
    randomVec.clear();
    randomVec.reserve( n_cars );
    srand( (int)time(0) );
    // randomVec : [ 1, 2, 3, ... ,n_cars ]
    for ( size_t i=1; i <= n_cars; i++ ){
        randomVec.push_back( i );
    }

    /* Rearrange */
    int count = n_cars;
    while ( --count ){
        // tar varies [ 0, count-1 ]
        int tar = rand() % count;
        // exchange randomVec[ tar ] & randomVec[ count ]
        int tmp = randomVec[ count ];
        randomVec[ count ] = randomVec[ tar ];
        randomVec[ tar ] = tmp;
    }

    for ( int i=0; i < n_cars; i++ ){
        train->push( randomVec[i] );
    }
    std::cout << "Initial train: " << *train;
}

void printTracks( int n_tra, arrayStack<int>* tracks, arrayStack<int>* train )
{
    std::cout << "**********" << std::endl;
    std::cout << "Tarin: " << *train;
    std::cout << "Index of carriage incoming: " << train->top() << std::endl;
    for ( int i=0; i<n_tra; i++ ){
        std::cout << tracks[i];
    }
}
