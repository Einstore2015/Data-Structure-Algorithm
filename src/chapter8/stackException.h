#ifndef _STACK_EXCE_H
#define _STACK_EXCE_H

#include <iostream>
#include <string>

/* ********************************************* */
/*                EXCEPTION                      */
/* ********************************************* */

class stackException
{
public:
    virtual ~stackException() {}
    virtual void outputMessage() const = 0;
};

class stackEmpty : public stackException
{
public:
    stackEmpty() :
        message( "Stack is empty." ) {}
    stackEmpty( char* theMessage )
        { message = theMessage; }
    void outputMessage() const
    {
        std::cout << message << std::endl;
    }
private:
    std::string message;
};

#endif