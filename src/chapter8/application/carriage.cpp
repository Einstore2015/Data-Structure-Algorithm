#include <iostream>
#include <math.h>
#include <time.h>
#include <vector>
#include "../arrayStack.h"

void printTracks( int n_tra, arrayStack<int>* tracks, arrayStack<int>* train )
{
    std::cout << "**********" << std::endl;
    std::cout << "Tarin: " << *train;
    for ( int i=0; i<n_tra; i++ ){
        std::cout << tracks[i];
    }
}

bool pushCar( int n_tra, int index_car, int , int, arrayStack<int>* );

/* 
 *  n_car --> length of train
 *  n_tra --> number of tracks
 *  train --> a stack contains index of train
 */
void railroad( const int n_car, const int n_tra, arrayStack<int>* train )
{
    // Create stacks for each track
    // tracks[0] is the track out
    arrayStack<int> *tracks = new arrayStack<int> [n_tra + 1];

    // Parking all carriages
    for ( int i=1; i<=n_car; i++ ){
        printTracks( n_tra, tracks, train );
        // i is the index of carriage to release
        int target = tracks[0].size() + 1;
        int index_car = train->top(); train->pop();
        if ( index_car == target ){
            // go straightly
            tracks[0].push( index_car );
        }else{
            // If top of tracks is the next carriage, drive it out
            for ( int j=1; j<=n_tra; j++ ){
                if ( !tracks[j].empty() ){
                    int tmp = tracks[j].top();
                    if ( tmp == target ){
                        tracks[j].pop();
                        tracks[0].push(tmp);
                    }
                }
            }

            // get min index of tracks top
            int max_top = 0, noempty_tracks = 0;
            for ( int j=1; j<=n_tra && !tracks[j].empty(); j++ ){
                noempty_tracks++;
                max_top = std::max( max_top, tracks[j].top() );
            }

            // True => push successfully
            bool flag = pushCar( n_tra, index_car, max_top, noempty_tracks, tracks );
            // When the function reach here, more tracks needed
            if ( !flag ){
                std::cout << "More " << std::endl;
                exit( -1 );
            }
        }
    }

    // Final process
    while ( tracks[0].size() < n_car ){
        int target = tracks->top() + 1;
        for ( int i=1; i<=n_tra; i++ ){
            if ( !tracks[i].empty() && tracks[i].top() == target ){
                tracks[0].push( target );
                tracks[i].pop();
                break;
            }
        }
    }
    printTracks( n_tra, tracks, train );
    std::cout << "Final: " << tracks[0];
}

/* 
 * Index decreases backward
 * Push the carriage
 */
bool pushCar( int n_tra, int index_car, int max_top, int noEmpty, arrayStack<int>* tracks )
{
    if ( ! noEmpty ){
        tracks[1].push( index_car );
        return true;
    }

    if ( max_top < index_car ){
        // index_car needs a new track
        if ( noEmpty < n_tra ){
            tracks[ noEmpty + 1 ].push( index_car );
            return true;
        }else{
            // tracks are all full
            return false;
        }
    }else{
        // top push
        for ( int i=1; i<=noEmpty; ){
            if ( tracks[i].top() < index_car ){
                i++;
            }else{
                // 
                tracks[i].push( index_car );
                return true;
            }
        }
    }

    return false;
}

/* 
 *  Generate a train stack which length is n_car
 *  with non-repeat indexes
 */
void genTrain( int n_car, arrayStack<int> *train ){
    std::vector<int> randomVec;
    randomVec.clear();
    randomVec.reserve( n_car );
    srand( (int)time(0) );
    for ( size_t i=0; i < n_car; i++ ){
        randomVec.push_back( i+1 );
    }

    int count = n_car;
    while ( --count ){
        int tar = rand() % count;
        int tmp = randomVec[count];
        randomVec[count] = randomVec[tar];
        randomVec[tar] = tmp;
    }

    for ( int i=0; i < n_car; i++ ){
        train->push( randomVec[i] );
    }
    std::cout << "Train: " << *train;
}

int main()
{
    arrayStack<int> train;
    genTrain( 50, &train );

    railroad( 50, 50, &train );
}