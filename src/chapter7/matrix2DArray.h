#ifndef _MATRIX_2DARRAY_H
#define _MATRIX_2DARRAY_H

#include "matrixException.h"

template <typename T>
class Matrix2DArray
{
public:
    // Construcotr and Deconstructor
    Matrix2DArray( int theRows = 0, int theColumns = 0 );
    Matrix2DArray( const Matrix2DArray<T>& );
    ~Matrix2DArray();

    // Const function
    int rows() const
        { return theRows; }
    int cols() const
        { return theColumns; }
    
    // Non-const function
    Matrix2DArray<T> tranpose();

    // Operator
    Matrix2DArray<T>& operator= ( const Matrix2DArray<T>& );
    T& operator() ( int, int ) const;
    Matrix2DArray<T> operator+ ( const Matrix2DArray<T>& ) const;
    Matrix2DArray<T> operator* ( const Matrix2DArray<T>& ) const;
    void operator-= ( const T& ) const;
private:
    T **element;            // elements of matrix
    int theRows,            // number of Matrix's rows 
        theColumns;         // number of Matrix's columns
};

/* **************************************** */
/*        Definition of functions           */
/* **************************************** */

template <typename T>
Matrix2DArray<T>::Matrix2DArray( int theRows, int theColumns )
{
    if ( theRows < 0 || theColumns < 0 ){
        throw "Invalid";
    }

    if ( theRows == 0 ^ theColumns == 0 ){
        // if either one of them equals to 0, the other one must
        // equals to 0 too.
        throw "Invalid";
    }

    // allocate
    this->theRows = theRows;
    this->theColumns = theColumns;
    try
    {
        element = new T* [ theRows ];
        for ( int i=0; i<theRows; ++i ){
            element[i] = new T [ theColumns ];
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}


/* 
 *  Deconstructor
 *  Release the 2-D array
 */
template <typename T>
Matrix2DArray<T>::~Matrix2DArray()
{
    for ( int i=0; i<theRows; i++ ){
        delete [] element[i];
    }
    delete [] element;
}


template <typename T>
Matrix2DArray<T> Matrix2DArray<T>::tranpose()
{
    Matrix2DArray<T> res( theColumns, theRows );
    for ( int i=0; i<theRows; i++ ){
        for ( int j=0; j<theColumns; j++ ){
            res.element[j][i] = element[i][j];
        }
    }

    return res;
}

/* **************************************** */
/*                Operator                  */
/* **************************************** */

template <typename T>
Matrix2DArray<T>&
Matrix2DArray<T>::operator= ( const Matrix2DArray<T>& m)
{
    if ( this != &m ){
        // release
        for ( int i=0; i<theRows; i++ ){
            delete [] element[i];
        }
        delete [] element;

        // allocate
        theRows = m.theRows; theColumns = m.theColumns;
        element = new T* [ theRows ];
        for ( int i=0; i<theRows; i++ ){
            element[i] = new T [ theColumns ];
        }

        for ( int i=0; i<theRows; i++ ){
            for ( int j=0; j<theColumns; j++ ){
                element[i][j] = m.element[i][j];
            }
        }
    }

    return *this;
}


template <typename T>
T& Matrix2DArray<T>::operator() ( int row, int col ) const
{
    if ( ( row<1 || row>theRows ) 
            || ( col<1 || col>theColumns ) )
    {
        throw matrixIndexOutOfbounds();
    }

    return element[row-1][col-1];
}


template <typename T>
Matrix2DArray<T> Matrix2DArray<T>::
operator* ( const Matrix2DArray<T>& m ) const
{
    if ( theColumns != m.theRows ){
        throw matrixSizeMismatch();
    }

    Matrix2DArray<T> res( theRows, m.theColumns );
    for ( int i=0; i<theRows; i++ ){
        for ( int j=0; j<m.theColumns; j++ ){
            T sum = T(0);
            for ( int k=0; k<theColumns; k++ ){
                sum += element[i][k] * m.element[k][j];
            }
            res.element[i][j] = sum;
        }
    }

    return res;
}


template <typename T>
void Matrix2DArray<T>::
operator-= ( const T& c ) const
{
    for ( int i=0; i<theRows; i++ ){
        for ( int j=0; j<theColumns; j++ ){
            element[i][j] -=c;
        }
    }
}

#endif