#include <iostream>
using namespace std;

#include "Card.h"

    Card::Card() {
        suit = 'c';
        rank = 2;
    }

    Card::Card(char cardSuit, int cardRank) {
        if (cardSuit != 'c' && cardSuit != 'd' && cardSuit != 'h' && cardSuit != 's' &&
        cardSuit != 'C' && cardSuit != 'D' && cardSuit != 'H' && cardSuit != 'S') {
            suit = 'c';
        } else {
            suit = tolower(cardSuit);
        }
        if (cardRank < 1 || cardRank > 13) {
            rank = 2;
        } else {
            rank = cardRank;
        }
    }

    char Card::getSuit() const {
        return suit;
    }

    int Card::getRank() const {
        return rank;
    }
    ostream & operator<<(ostream & out, const Card & cards) {
        string suit = " ";
        if (cards.suit == 'c') {
            suit = "Clubs";
        } else if (cards.suit == 'd') {
            suit = "Diamonds";
        } else if (cards.suit == 'h') {
            suit = "Hearts";
        } else if (cards.suit == 's') {
            suit = "Spades";
        }
        string rank = to_string(cards.rank);
        if (cards.rank == 1) {
            rank = "Ace";
        } else if (cards.rank == 11) {
            rank = "Jack";
        } else if (cards.rank == 12) {
            rank = "Queen";
        } else if (cards.rank == 13) {
            rank = "King";
        }
        out << rank << " of " << suit;
        return out;
    }