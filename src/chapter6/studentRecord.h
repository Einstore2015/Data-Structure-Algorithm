#ifndef _STUDENT_RECORD_H
#define _STUDENT_RECORD_H

#include <string>
#include <iostream>

struct studentRecord
{
    int score;
    std::string* name;

    // operator
    operator int() const { return score; }
    bool operator!= ( const studentRecord& x ) const
        { return (score != x.score); }
};

std::ostream& operator<< ( std::ostream& out, const studentRecord& x )
{
    out << x.score << " " << *x.name << std::endl;
    return out;
}

#endif