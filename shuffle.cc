#include "shuffle.h"

#include "Card.h"
#include "Deck.h"

#include <cassert> // assert

void
shuffle(
        Deck& hand,
        Deck& table
     )
{
    while ( !hand.empty() ) {
        // take top card off deck in hand and put it on table
        Card* top = hand.pop_front();
        table.push_front( top );

        if ( hand.empty() ) break;

        // take next card off deck in hand and put it on the bottom
        top = hand.pop_front();
        hand.push_back( top );
    }

    // swap hand with deck on table
    Deck temp( hand );
    hand = table;
    table = temp;

    assert( table.empty() );
    assert( !hand.empty() );
}

uint32_t
countRounds(
        Deck& hand
        )
{
    const Deck original( hand );
    std::cout << "Starting deck values are: " << original << std::endl;

    uint32_t count( 0 );
    Deck table;
    do {
        ++count;
        shuffle( hand, table );
        std::cout << "hand after round " << count << ": " << hand << std::endl;
    } while ( hand != original );

    return count;
}


