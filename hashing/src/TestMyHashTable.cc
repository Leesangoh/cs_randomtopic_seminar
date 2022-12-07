#include <iostream>
#include "SeparateChaining.h"
using namespace std;

    // Simple main
int main( )
{
    HashTable<int> H;

    const int NUMS = 4000;
    const int GAP  =   37;
    int i;

    cout << "Checking Integer ... (no more output means success)" << endl;

    for( i = GAP; i != 0; i = ( i + GAP ) % NUMS )
    {
	    //cout << " input [" << i << "] in HashTable" << endl;
	    H.insert( i );
    }

    for( i = 1; i < NUMS; i += 2 )
    {
	    //cout << " remove [" << i << "] in HashTable" << endl;
	    H.remove( i );
    }

    for( i = 2; i < NUMS; i += 2 )
        if( !H.contains( i ) )
            cout << "Contains fails " << i << endl;

    for( i = 1; i < NUMS; i += 2 )
    {
        if( H.contains( i ) )
            cout << "OOPS!!! " <<  i << endl;
    }

    cout << "complete" << endl;

    return 0;
}
