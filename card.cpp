#include <iostream>
#include <string>
#include "card.h"
using namespace std;


Card::Card(char s, char r) {
    // constructor creating a card with a suit and rank
    suit = r;
    rank = s;
};

Card::Card() {
    // default constructor needed for array
    suit = 'X';
    rank = 'X';
};

void Card::displayCard() {
    // display the card, ex: AC, 10S, KD, warning: ten of spades is 10S, not TS
    if (rank == 'T') {
        cout << "10" << suit;
        return;
    } else {
        cout << rank << suit;
    }
};

int Card::compareCard(Card otherCard) {
    // A-K, K = highest, A = Lowest, return 1 for win, 0 for tie, -1 for lose, ex: 2 > A, K > Q. J > 8
    if (otherCard.rank == rank) {
        return 0;
    }
    
    // if this card is an A
    if (rank == 'A') {
        return -1;  // A loses to everything except another A
    }
    
    //if other card is an A
    if (otherCard.rank == 'A') {
        return 1; // any card beats an A
    }

    //since comparision is done by ascii values its weird for face cards
    if (rank == 'K') {
        return 1;    // k>everything except another K
    }
    if (otherCard.rank == 'K') {
        return -1;   // everything loses to K
    }
    if (rank == 'Q') {
        return 1;    // Q beats everything except K
    }
    if (otherCard.rank == 'Q') {
        return -1;   // Everything except K loses to Q
    }
    if (rank == 'J') {
        return 1;    // J beats everything except K and Q
    }
    if (otherCard.rank == 'J') {
        return -1;   // Everything except K and Q loses to J
    }

    //special case for T = '10'
    if (rank == 'T' && (otherCard.rank >= '2' && otherCard.rank <= '9')) {
        return 1;    // T beats 2-9
    }
    if (otherCard.rank == 'T' && (rank >= '2' && rank <= '9')) {
        return -1;   // 2-9 lose to T
    }
    
    //other stuff
    if (otherCard.rank < rank) {
        return 1;
    } 
    else {
        return -1;
    }
};
