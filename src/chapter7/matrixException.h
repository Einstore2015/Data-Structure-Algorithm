#ifndef _MATRIX_EXC_H
#define _MATRIX_EXC_H

#include <string>
#include <iostream>

/* ********************************************* */
/*                EXCEPTION                      */
/* ********************************************* */

class matrixException
{
public:
    matrixException() {};
    void outputMessage() {}; 
private:
    std::string message;
};

class matrixIndexOutOfbounds : public matrixException
{
public:
    matrixIndexOutOfbounds() :
        message( "Illegal index" ) {}
    matrixIndexOutOfbounds( char* theMessage )
        { message = theMessage; }
    void outputMessage() { std::cout << message << std::endl; }
private:
    std::string message;
};

class matrixSizeMismatch : public matrixException
{
public:
    matrixSizeMismatch() :
        message( "Matrix's size doen't match " ) {}
    matrixSizeMismatch( char* theMessage )
        { message = theMessage; }
    void outputMessage() { std::cout << message << std::endl; }
private:
    std::string message;
};

#endif