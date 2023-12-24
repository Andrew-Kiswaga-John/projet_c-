/*#ifndef DECK_H
#define DECK_H


class Deck
{
public:
    Deck();
};

#endif // DECK_H*/

#ifndef DECK_H
#define DECK_H

#include "cards.h"
#include <vector>

class Deck
{
public:
    Deck();
    void shuffle();
    Card dealRandomCard();
    Card dealHighestRemainingCard();
    bool isEmpty() const;
    void resetDeck();

private:
    std::vector<Card> cards;
    int currentCardIndex;
};

#endif // DECK_H
