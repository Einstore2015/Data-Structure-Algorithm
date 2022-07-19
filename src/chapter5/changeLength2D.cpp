#include <exception>
#include <algorithm>

/* 
 * tranfrom a old 2-D array[ oldRows, oldCols ]
 *       ------>    ewArray[ newRows, newCols ]
 */
template <typename T>
void changeLength2D( T **a, int oldCols, int newCols,
                            int oldRows, int newRows )
{
    // make sure new 2-D array adequate
    if ( oldRows > newCols || oldCols > newCols ){
        exit(-1);
    }

    // allocate space
    T **temp = new T*[newRows];
    for ( int i=0; i<newRows; ++i){
        temp[i] = new T[newCols];
    }

    // copy
    for ( int i=0; i<oldRows; ++i){
        std::copy( a[i], a[i]+oldCols, temp[i] );
        delete [] a[i];
    }

    delete [] a;
    a = temp;
}

int main()
{
    int **a[3];
    int i1[2]={11, 12}, i2[2]={2,6};

    // a[3,2]
    changeLength2D( a, 3, 2, 4, 4);

}