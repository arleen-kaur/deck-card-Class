#include <iostream>
#include <cstdlib>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>

using namespace std;

#include "Deck.h"
#include "Card.h"

bool hasPair(const vector<Card> &hand);
 
ostream & operator<<(ostream &, const vector<Card> &);

int main() {
    srand(2222);
    ofstream outFS;
    string wantFile;
    string fileName;
    int numCards;
    int numDeals;
    int numPairs;
    Deck currDeck;
    vector <Card> hand;
    
    cout << "Do you want to output all hands to a file? (Yes/No)";
    cin >> wantFile;
    cout << endl;
    if (wantFile == "Yes") {
        cout << "Enter name of output file: ";
        cin >> fileName;
        outFS.open(fileName);
        if (!outFS.is_open()) {
            return 1;
        }
    }
    cout << endl << "Enter number of cards per hand: ";
    cin >> numCards;
    cout << endl << "Enter number of deals (simulations): ";
    cin >> numDeals;
    numPairs = 0;
    for (int i = 0; i < numDeals; i++) {
        currDeck.shuffleDeck();
        hand.clear();
        for (int j = 0; j < numCards; j++) {
            hand.push_back(currDeck.dealCard());
        }
        if (hasPair(hand)) {
            numPairs++;
            if (wantFile == "Yes") {
                outFS << "Found Pair!! "; 
            }
        } else {
            if (wantFile == "Yes") {
                outFS << "             ";
            }
        }
        if (wantFile == "Yes") {
                outFS << hand << endl;
        }
    }
    outFS.close();
    int chance = (static_cast<double>(numPairs) / numDeals) * 100;
    cout << endl << "Chances of receiving a pair in a hand of " << numCards <<
     " cards is:" << endl << chance << "%" << endl;
    return 0;
}


bool hasPair(const vector<Card> &hand) {
    bool pair = false;
    for (unsigned int i = 0; i < hand.size() - 1; i++) {
        for (unsigned int j = i + 1; j < hand.size(); j++) {
            if (hand.at(i).getRank() == hand.at(j).getRank()) {
                pair = true;
            }
        }
    }
    return pair;
}
ostream & operator<<(ostream & out, const vector<Card> &rhs) {
    for (unsigned int i =0; i < rhs.size() - 1; i++) {
        out << rhs.at(i) << ", ";
    }
    out << rhs.at(rhs.size() - 1);
    return out;
}