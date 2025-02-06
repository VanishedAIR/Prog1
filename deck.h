#ifndef DECK_H
#define DECK_H

#include <iostream>
#include "card.h"

class Deck {
    private:
        Card cards[52];
        int currentCardIdx = 0;
    public:
        Deck();

        Card deal ();

        void displayDeck();

        void shuffle();
};

#endif