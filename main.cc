#include "Card.h"
#include "Deck.h"
#include "shuffle.h"

#include <iostream>

#include <cstdlib> // strtol

int
main(int argc, char* argv[])
{
    uint32_t count;
    if ( argc < 2 ) {
        std::cout << "How many cards should be in the deck?" << std::endl;
        if ( !(std::cin >> count) ) {
            std::cerr << "Could not read card count from stdin!" << std::endl;
            exit( EXIT_FAILURE );
        }
    } else if ( argc > 2 ) {
        std::cerr << "usage: " << std::endl;
        std::cerr << argv[0] << "card_count" << std::endl;
        exit( EXIT_FAILURE );
    } else {
        char* endptr;
        count = static_cast<uint32_t>(strtol( argv[1], &endptr, 10 ));
        if ( *endptr != '\0' ) {
            std::cerr << "Garbage number of cards value: " << endptr << std::endl;
            exit( EXIT_FAILURE );
        }
    }

    if ( count > std::numeric_limits<Card::value_type>::max() ) {
        std::cerr << "Too many cards, please create less than " << 
            static_cast<unsigned>(std::numeric_limits<Card::value_type>::max()) <<
            " cards" << std::endl;
        exit( EXIT_FAILURE );
    }

    Deck deck;
    for ( uint32_t i = 1; i <= count; ++i ) {
        Card* card( new Card(static_cast<Card::value_type>(i)) );
        deck.push_back( card );
    }

    const uint32_t numRounds = countRounds( deck );
    std::cout << "number of rounds is: " << numRounds << std::endl;
}
