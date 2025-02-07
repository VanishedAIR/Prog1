// Name: Vansh Patel
// Class (CECS 325-02)
// Project Name (Program 1 - One Card War )
// Due Date (2/13/2025)
//
// I certify that this program is my own original work. I did not copy any part of this program from
// any other source. I further certify that I typed each and every line of code in this program.

#include <iostream>
#include "deck.h"
#include "card.h"
#include <string>
using namespace std;

int main() {
    Deck deck;
    string player1;
    cout << "Enter the name of the first player: ";
    cin >> player1;
    string player2;
    cout << "Enter the name of the second player: ";
    cin >> player2;
    cout << "Original Deck \n";
    deck.displayDeck();
    cout << "\n";
    deck.shuffle();
    cout << "Shuffled Deck \n";
    deck.displayDeck();
    cout << "\n";
    int player1Score = 0;
    int player2Score = 0;
    int playerTie = 0;
    for (int i = 0; i < 26; i++) {
        cout << "Game " << i + 1 << "\n";
        cout << "--------------------------------\n";
        Card player1Card = deck.deal();
        Card player2Card = deck.deal();
        cout << player1 << "=>";
        player1Card.displayCard();
        cout << "\n";
        cout << player2 << "=>";
        player2Card.displayCard();
        cout << "\n";
        int result = player1Card.compareCard(player2Card);
        if (result == 1) {
            cout << player1 << "=> Winner\n";
            player1Score++;
        } else if (result == -1) {
            cout << player2 << "=> Winner\n";
            player2Score++;
        } else {
            cout << "Tie game";
            playerTie++;
        }
        cout << "\n";
    }
    cout << "------Final Stats-------\n";
    cout << "\t" << player1 << " vs." << player2 << "\n";
    cout <<"Wins: \t" << player1Score << "\t\t" << player2Score << "\n";
    cout << "Losses: " << 26 - player1Score - playerTie << "\t\t" << 26 - player2Score - playerTie << "\n";
    cout << "Ties: \t" << playerTie << "\t\t" << playerTie << "\n";
    return 0;
}