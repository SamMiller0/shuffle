#include "Deck.h"
#include "Card.h"

#include <cassert>

int
main()
{
    {
        // test equality operator true
        Deck one;
        one.push_back( new Card(10) );
        Deck two;
        two.push_back( new Card(10) );
        assert( one == two );
    }
    
    {
        // test equality operator false
        Deck one;
        one.push_back( new Card(10) );
        one.push_back( new Card(20) );
        Deck two;
        two.push_back( new Card(10) );
        assert( one != two );
    }

    {
        // test empty and size
        Deck one;
        assert( one.empty() );
        assert( one.size() == 0 );
        one.push_back( new Card(10) );
        assert( !one.empty() );
        assert( one.size() == 1 );
    }

    {
        // test copy ctor
        Deck one;
        one.push_back( new Card(10) );
        const Deck two( one );
        assert( one == two );
    }
}

