#ifndef _MATRIX_H
#define _MATRIX_H

#include <string>
#include <iostream>
#include <algorithm>
#include <exception>
#include "matrixException.h"

template <typename T>
class Matrix
{
public:
    // Constructor and deconstructor
    Matrix( int theRows = 0, int theColumns = 0 );
    Matrix( const Matrix<T>& );
    ~Matrix() { delete []element; }

    // Const function
    int rows() const
        { return theRows; }
    int cols() const
        { return theColumns; }
    
    // Non-const
    Matrix<T> tranpose();
    
    // Operator
    Matrix<T>& operator= ( const Matrix<T>& );
    T& operator() ( int i, int j ) const;
    Matrix<T> operator+ ( const Matrix<T>& ) const;
    Matrix<T> operator* ( const Matrix<T>& ) const;
    void operator-= ( const T& );      // Matrix element mius
private:
    int theRows,            // number of Matrix's rows 
        theColumns;         // number of Matrix's columns
    T  *element;

};

/* **************************************** */
/*        Definition of functions           */
/* **************************************** */

template <typename T>
Matrix<T>::Matrix( int theRows, int theColumns )
{
    if ( theRows < 0 || theColumns < 0 )
        throw "Invalid";

    if ( theRows == 0 ^ theColumns == 0 ){
        // if either one of them equals to 0, the other one must
        // equals to 0 too.
        throw "Invalid";
    }

    this->theRows = theRows;
    this->theColumns = theColumns;
    element = new T [ theRows * theColumns ];
}


/* 
 *  Copy constructor
 */
template <typename T>
Matrix<T>::Matrix( const Matrix<T>& m )
{
    theRows = m.theRows;
    theColumns = m.theColumns;
    element = new T [ theRows * theColumns ];

    std::copy( m.element,
               m.element + theRows*theColumns,
               this->element                   );
}


template <typename T>
Matrix<T> Matrix<T>::tranpose()
{
    Matrix<T> res( theColumns, theRows );
    for ( int i=0; i<theRows; i++ ){
        for ( int j=0; j<theColumns; j++ ){
            res.element[ j*theRows + i ] = 
                element[ i*theColumns + j ];
        }
    }

    return res;
}

/* **************************************** */
/*                Operator                  */
/* **************************************** */

template <typename T>
Matrix<T>& Matrix<T>::operator= ( const Matrix<T>& m )
{
    if ( this != &m ){
        delete [] element;
        theRows = m.theRows;
        theColumns = m.theColumns;
        element = new T [ theRows*theColumns ];
        // copy
        std::copy( m.element,
                   m.element + theRows*theColumns,
                   this->element                  );
    }

    return *this;
}

/* 
 *  Matrix ()
 */
template <typename T>
T& Matrix<T>::operator() ( int i, int j ) const
{
    if ( ( i<1 || i>theRows) ||
         ( j<1 || j>theColumns ) ){
        throw matrixIndexOutOfbounds();
    }
    return element[ (i-1) * theColumns + j - 1 ];
}

/* 
 *  Matrix plus operator
 */
template <typename T>
Matrix<T> Matrix<T>::operator+ ( const Matrix<T>& m ) const
{
    if ( theRows != m.theRows 
            || theColumns != m.theColumns ){
        throw matrixSizeMismatch();
    }

    Matrix<T> result( theRows, theColumns );
    for ( int i=0; i<theRows*theColumns; ++i ){
        result.element[i] = element[i] + m.element[i];
    }

    return result;
}


/* 
 *  Matrix dot product
 */
template <typename T>
Matrix<T> Matrix<T>::operator* ( const Matrix<T>& m ) const
{
    if ( theColumns != m.theRows ){
        throw matrixSizeMismatch();
    }

    Matrix<T> res( theRows, m.theColumns );
    int elem_index=0;
    for ( int row_i=0; row_i<theRows; row_i++ ){
        // calculate the (row_i) row of res
        for ( int col_i=0; col_i<m.theColumns; col_i++ ){
            T sum = T(0);
            for ( int k=0; k<theColumns; k++ ){
                sum += element[ row_i * theColumns + k ] 
                        * m.element[ col_i + k * m.theRows ];
            }
            res.element[ elem_index++ ] = sum;
        }
    }
/* 
    Matrix<T> res( theRows, m.theColumns );
    for ( int i=1; i<=theRows; ++i ){
        for ( int j=1; j<=m.theColumns; ++j ){
            T sum = T(0);
            for ( int k=1; k<=theColumns; ++k ){
                sum += (*this)(i,k) * m(k,j);
            }

            res(i,j) = sum;
        }
    }
 */
    return res;
}

/* 
 *  Matrix elements minus
 */
template <typename T>
void Matrix<T>::operator-= ( const T& c )
{
    for ( int i=0; i < theRows*theColumns ; ++i ){
        element[i] -=c;
    }
}

#endif