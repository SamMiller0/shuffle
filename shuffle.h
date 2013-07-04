#ifndef SHUFFLE_H
#define SHUFFLE_H

#include <stdint.h>

class Deck;

void
shuffle(
        Deck& hand,
        Deck& table
     );

uint32_t
countRounds(
        Deck& hand
        );

#endif

