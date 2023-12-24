
#ifndef CARDS_H
#define CARDS_H

#include <QString>

enum Suit
{
    Hearts,
    Diamonds,
    Clubs,
    Spades,
    InvalidSuit // Add an invalid suit
};

enum Rank
{
    One,
    Two,
    Three,
    Four,
    Five,
    Six,
    Seven,
    Ten,
    Eleven,
    Twelve,
    InvalidRank // Add an invalid rank
};

class Card
{
public:
    Card();
    Card(Suit suit, Rank rank);
    QString getCardImage() const;
    QString toString() const;
    int getCardValue() const;
    bool isValid() const; // Add a method to check if the card is valid

private:
    Suit suit;
    Rank rank;
};

#endif // CARDS_H

