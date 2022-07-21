#include <chain.h>
#include <studentRecord.h>

void binSort( Chain<studentRecord>& theChain, int range )
{
    Chain<studentRecord> *bin;
    bin = new Chain<studentRecord> [range+1];

    // distribute into boxes
    int numberOfElements = theChain.size();
    for ( int i = 0; i < numberOfElements; i++ ){
        studentRecord x = theChain.get(0);
        theChain.erase(0);
        bin[x.score].insert(0, x);
    }

    // collect elements
    for ( int j=range; j>=0; j-- ){
        while ( !bin[j].empty() ){
            studentRecord x = bin[j].get(0);
            bin[j].erase(0);
            theChain.insert(0,x);
        }
    }

    delete []bin;
}

int main()
{

}