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
    if (otherCard.rank < rank) {
        return 1;
    } else {
        return -1;
    }
};
