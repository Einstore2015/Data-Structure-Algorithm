#include <iostream>

#include "carriages.h"
#include "train.h"

void goutCar( int& target, int n_tracks, arrayStack<int>* tracks )
{
    bool flag = true;
    while ( flag ){
        flag = false;
        // refresh target value
        target = tracks[0].size() + 1;
        for ( int i=1; i <= n_tracks; i++ ){
            if ( ! tracks[i].empty() && tracks[i].top() == target ){
                tracks[0].push( target );
                tracks[i].pop();
                flag = true;
                break;
            }
        }
    }
}

bool pushCarriage( int numTracks, int indexCar, int noEmpty, int maxTop,
                arrayStack<int>* tracks )
{
    if ( indexCar > maxTop ){
        // need a new track
        if ( noEmpty >= numTracks - 1 ){
            // !!NEED MORE TRACKS
            return false;
        }else{
            // push into a new track
            tracks[noEmpty + 1].push( indexCar );
            return true;
        }
    }else{
        // top push
        for ( int i=1; i<=noEmpty; ){
            if ( tracks[i].top() < indexCar ){
                i++;
            }else{
                tracks[i].push( indexCar );
                return true;
            }
        }
    }

    return false;
}

void arrangeCars( int n_cars, int n_tracks, arrayStack<int>& train, 
                bool on_log )
{
    // Generate n_tracks+1 stacks for tracks
    // tracks[0] is the departure railway
    arrayStack<int>* tracks = new arrayStack<int> [ n_tracks + 1 ];

    for ( int i=1; i<=n_cars; i++ ){
        // Out put message
        if ( on_log )
            printTracks( n_tracks, tracks, &train );

        int target,             // target index of next departure carriage
            index_car;          // top of incoming train

        // index of next departure carriage
        target = tracks[0].size() + 1; index_car = train.top();
        if ( train.top() == target ){
            // first carriage go straightly
            tracks[ 0 ].push( target ); train.pop();
            continue;;          // go back to "for" loop
        }
        train.pop();

        // Drive correct carriage out and 
        // refresh the target value
        goutCar( target, n_tracks, tracks );

        int no_empty_tracks = 0,    // number of not empty tracks
            max_tracks_top  = 0;    // max value of tracks[] top()
        for ( int j=1; j<n_tracks && ! tracks[j].empty(); j++ ){
            no_empty_tracks++;
            max_tracks_top = std::max( max_tracks_top, tracks[j].top() );
        }
        // Push track
        bool flag = pushCarriage( n_tracks, index_car, no_empty_tracks,
                            max_tracks_top, tracks );
        if ( flag == false ){
            std::cout << "Got " << n_cars << " carriages, ";
            std::cout << n_tracks << " tracks." << std::endl;
            std::cout << "More tracks needed! " << std::endl;
            exit(-1);
        }
    }
    // Final       
    auto target = tracks[0].size() + 1;
    goutCar( target, n_tracks, tracks );
    std::cout << "Final: " << tracks[0];
}