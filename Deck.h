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
            const Deck& other
        );

    /*!
     * \brief assignment operator
     */
    Deck& operator=(
            const Deck& other
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
     * \brief
     */
    bool empty() const { return _size == 0; }

    /*!
     * \brief
     */
    Card* top() const { return _cards; }

    /*!
     * \brief
     */
    bool operator==(const Deck& other) const;
    
    /*!
     * \brief
     */
    bool operator!=(const Deck& other) const;

    /*!
     * \brief remove top card of deck
     */
    Card* pop_front();

    /*!
     * \brief add a Card to the top of the deck.
     */
    void push_front(
            Card* card
            );

    /*!
     * \brief add a Card to the bottom of the deck.
     */
    void push_back(
            Card* card
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
