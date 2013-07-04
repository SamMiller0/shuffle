#ifndef DECK_H
#define DECK_H

#include <stdint.h>

#include <iostream>

class Card;

/*!
 * \brief Representation of a deck of playing cards
 */
class Deck
{
public:
    /*!
     * \brief ctor
     */
    Deck();

    /*!
     * \brief copy ctor
     */
    Deck( 
            const Deck& other   //!< [in]
        );

    /*!
     * \brief assignment operator
     */
    Deck& operator=(
            const Deck& other   //!< [in]
            );
    
    /*!
     * \brief dtor.
     */
    ~Deck();

    /*!
     * \brief Get the size of the deck
     */
    uint32_t size() const { return _size; }

    /*!
     * \brief Test if the deck is empty
     */
    bool empty() const { return _size == 0; }

    /*!
     * \brief Access the top card in the deck
     */
    Card* top() const { return _cards; }

    /*!
     * \brief Test for equality with another Deck
     */
    bool operator==(const Deck& other) const;
    
    /*!
     * \brief Test for inequality with another Deck
     */
    bool operator!=(const Deck& other) const;

    /*!
     * \brief remove top card of deck
     */
    Card* pop_front();

    /*!
     * \brief add a Card to the top of the deck.
     * 
     * \pre card != NULL
     */
    void push_front(
            Card* const card
            );

    /*!
     * \brief add a Card to the bottom of the deck.
     * 
     * \pre card != NULL
     */
    void push_back(
            Card* const card
            );

private:
    uint32_t _size;
    Card* _cards;
};

std::ostream&
operator<<(
        std::ostream& os,
        const Deck& deck
        );

#endif
