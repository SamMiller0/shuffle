#ifndef SHUFFLE_H
#define SHUFFLE_H
/*!
 * \file shuffle.h
 */

#include <stdint.h>

class Deck;

/*!
 * \brief shuffle a deck of cards.
 */
void
shuffle(
        Deck& hand,     //!< [in]
        Deck& table     //!< [in]
     );

/*!
 * \brief Count the number of shuffling rounds to return the deck to its starting form.
 */
uint32_t
countRounds(
        Deck& hand  //!< [in]
        );

#endif

