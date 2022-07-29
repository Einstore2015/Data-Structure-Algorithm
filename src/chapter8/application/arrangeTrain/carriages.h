#ifndef _CARRIAGES_H
#define _CARRIAGES_H

#include "..\..\arrayStack.h"

/* 
 *  n_cars      --> number of carriages
 *  n_tracks    --> number of tracks
 *  train       --> stack of train
 */
void arrangeCars( int n_cars, int n_tracks,
                    arrayStack<int>& train, bool on_log = false );

#endif