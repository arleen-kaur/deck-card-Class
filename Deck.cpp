#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#include "Deck.h"
#include "Card.h"

    Deck::Deck() {
        char cardSuit = ' ';
        for (unsigned int i = 0; i < 4; i++) {
            if (i == 0) {
                cardSuit = 's';
            } else if (i == 1) {
                cardSuit = 'h';
            } else if (i == 2) {
                cardSuit = 'd';
            } else if (i == 3) {
                cardSuit = 'c';
            }
            for (unsigned int j = 1; j < 14; j++) {
                theDeck.push_back(Card(cardSuit, 14-j));
            }
        }
    }

    Card Deck::dealCard() {
        Card card1 = theDeck.at(theDeck.size() - 1);
        dealtCards.push_back(card1);
        theDeck.pop_back();
        return card1;
    }

    void Deck::shuffleDeck() {
        for (unsigned int i = 0; i < dealtCards.size(); i++) {
            theDeck.push_back(dealtCards.at(i));
        }
        dealtCards.clear();
        random_shuffle(theDeck.begin(), theDeck.end());
    }

    unsigned Deck::deckSize() const {
        return theDeck.size();
    }