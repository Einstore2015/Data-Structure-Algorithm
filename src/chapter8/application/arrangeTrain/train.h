#ifndef _TRAIN_H
#define _TRAIN_H

#include "..\..\arrayStack.h"

/* Generate a train stacks with non-repeat element */
void generateTrain( int n_cars, arrayStack<int>* train );

/* Output a stack from the bottom to the top */
void printTracks( int n_tra, arrayStack<int>* tracks, arrayStack<int>* train );

#endif