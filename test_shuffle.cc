#include "Card.h"
#include "Deck.h"
#include "shuffle.h"

#include <cassert>

int
main()
{
    {
        // deck of four cards will take 2 rounds
        Deck deck;
        for ( uint32_t i = 0; i < 4; ++i ) {
            Card* card( new Card(static_cast<Card::value_type>(i)) );
            deck.push_back( card );
        }

        assert( countRounds(deck) == 2 );
    }
   
    {
        // deck of six cards will take 6 rounds
        Deck deck;
        for ( uint32_t i = 0; i < 6; ++i ) {
            Card* card( new Card(static_cast<Card::value_type>(i)) );
            deck.push_back( card );
        }

        assert( countRounds(deck) == 6 );
    }
}
