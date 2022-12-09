#include <utility>
#include "pairNode.hpp"

int main()
{
    typedef std::pair<int, double> mp;
    typedef pairNode<int, double> pn;
    mp my_p(1, 2.2);
    pn a(my_p);
}