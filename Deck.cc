#include "Deck.h"

#include "Card.h"

#include <cassert>
#include <iostream>

Deck::Deck() :
    _size( 0 ),
    _cards( NULL )
{

}

Deck::Deck(
        const Deck& other
        ) :
    _size( 0 ),
    _cards( NULL )
{
    Card* theirs( other._cards );
    while ( theirs ) {
        Card* card( new Card(static_cast<Card::value_type>(theirs->_value)) );
        this->push_back( card );
        theirs = theirs->_next;
    }

    assert( *this == other );
}

Deck&
Deck::operator=(
        const Deck& other
        )
{
    // remove our cards 
    Card* c( _cards );
    while ( !this->empty() ) {
        Card* c = this->pop_front();
        delete c;
    }

    // copy their cards
    c = other._cards;
    while ( c ) {
        Card* card( new Card(static_cast<Card::value_type>(c->_value)) );
        this->push_back( card );
        c = c->_next;
    }

    return *this;
}

Deck::~Deck()
{
    Card* c( _cards );
    while ( c ) {
        Card* temp = c;
        c = c->_next;
        delete temp;
    }
}

bool
Deck::operator==(
        const Deck& other
        ) const
{
    // two decks are equal if they match in size and every card's value
    if ( other._size != _size ) return false;

    Card* mine = _cards;
    Card* theirs = other._cards;
    while ( mine && theirs ) {
        if ( mine->_value != theirs->_value ) return false;
        mine = mine->_next;
        theirs = theirs->_next;
    }

    return !mine && !theirs;
}

bool
Deck::operator!=(
        const Deck& other
        ) const
{
    return !( *this == other );
}

Card*
Deck::pop_front() 
{
    if ( !_size ) return NULL;

    Card* c = _cards;
    _cards = c->_next;
    c->_next = NULL;
    --_size;
    
    return c;
}

void
Deck::push_front(
        Card* const card
        )
{
    assert( card );
    ++_size;
    card->_next = _cards;
    _cards = card;
}

void
Deck::push_back(
        Card* const card
        )
{
    assert( card );
    ++_size;
    if ( !_cards ) {
        _cards = card;
        card->_next = NULL;
        return;
    }

    Card* c( _cards );
    while ( c->_next ) {
        c = c->_next;
    }
    c->_next = card;
    card->_next = NULL;
}

std::ostream&
operator<<(
        std::ostream& os,
        const Deck& deck
        )
{
    Card* c( deck.top() );
    if ( !c ) return os;

    os << *c;
    c = c->_next;

    while ( c ) {
        os << " " << *c;
        c = c->_next;
    }

    return os;
}

