#include <iostream>
#include "deck.h"


Deck::Deck() {
    // constructor creating deck of 52 cards, must use an array to store cards in a deck
    char suits[] = {'C', 'S', 'D', 'H'}; // initialize suits array with C, D, H, S
    char ranks[] = {'A', '2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K'}; // initialize ranks arr
    int idx = 0;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 13; j++) {
            cards[idx] = Card(ranks[j], suits[i]);
            idx++;
        }
    }
}
Card Deck::deal () {
    // deal a card from the deck
    Card card = cards[currentCardIdx];
    currentCardIdx++;
    return card;
};

void Deck::displayDeck() {
    // display all cards in the deck
    for (int i = 0; i < 52; i++) {
        if (i % 13 == 0 && i != 0) {
            std::cout << "\n";
        }
        cards[i].displayCard();
        std::cout << ",";
    }
}

void Deck::shuffle() {
    // shuffle the deck, without using built-in functions like random_shuffle, use a random generator
    for (int i = 0; i < 52; i++) {
        int randomIdx = rand() % 52; // get a random index between 0 and 51
        Card temp = cards[i]; // store the card at index i in a temp variable
        cards[i] = cards[randomIdx]; // swap the card at index i with the card at the random index
        cards[randomIdx] = temp; // swap the card at the random index with the card stored in the temp variable
    }
}
