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
    // problem statement
    // 1. Take the top card off of the deck and create a new deck on the table, putting the cards on top of this new deck.
    // 2. Take the next card off the top and put it on the bottom of the deck in your hand.
    // 3. Continue steps 1 and 2 until all cards are on the table.  This is a round.

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
    const Deck temp( hand );
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
    // retain a copy of original deck to determine when shuffling is complete
    const Deck original( hand );
    std::cout << "Starting deck values are: " << original << std::endl;

    // deck on table is empty to begin with
    Deck table;

    uint32_t count( 0 );
    do {
        ++count;
        shuffle( hand, table );
        std::cout << "hand after round " << count << ": " << hand << std::endl;
    } while ( hand != original );

    return count;
}


