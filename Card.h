#ifndef CARD_H
#define CARD_H

#include <iostream>

#include <stdint.h>

/*!
 * \brief Data structure representing a Card in a deck
 *
 * \note this is a singly linked list
 */
class Card
{
public:
    /*!
     * \brief value type of this Card.
     */
    typedef uint8_t value_type;

public:
    /*!
     * \brief ctor.
     */
    Card(
            value_type value
        );

    const value_type _value;    //!< value of the card
    Card* _next;                //!< next card in the Deck
};

std::ostream&
operator<<(
        std::ostream& os,
        const Card& c
        );

#endif
