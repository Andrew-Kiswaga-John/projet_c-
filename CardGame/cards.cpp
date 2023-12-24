/*#include "cards.h"

Cards::Cards()
{

}*/


#include "cards.h"

Card::Card() : suit(InvalidSuit), rank(InvalidRank) {}


Card::Card(Suit suit, Rank rank) : suit(suit), rank(rank) {}

// Methode pour synchroniser les cartes avec leurs images
QString Card::getCardImage() const
{
    QString suitStr;
    QString rankStr;

    // Convert Suit enum to string representation
    switch (suit)
    {
    case Hearts:
        suitStr = "Hearts";
        break;
    case Diamonds:
        suitStr = "Diamonds";
        break;
    case Clubs:
        suitStr = "Clubs";
        break;
    case Spades:
        suitStr = "Spades";
        break;
    }

    // Convert Rank enum to string representation
    switch (rank)
    {
    case One:
        rankStr = "00";
        break;
    case Two:
        rankStr = "01";
        break;
    case Three:
        rankStr = "02";
        break;
    case Four:
        rankStr = "03";
        break;
    case Five:
        rankStr = "04";
        break;
    case Six:
        rankStr = "05";
        break;
    case Seven:
        rankStr = "06";
        break;
    case Ten:
        rankStr = "07";
        break;
    case Eleven:
        rankStr = "08";
        break;
    case Twelve:
        rankStr = "09";
        break;
    }

    // Return the path to the image file for the specific card
    return QString(":/image/cards/") + rankStr + "_" + suitStr + ".gif";
}

// Methodes pour synchroniser les cartes, leurs images, et leurs valuers
QString Card::toString() const
{
    QString suitStr;
    QString rankStr;

    switch (suit)
    {
    case Hearts:
        suitStr = "Hearts";
        break;
    case Diamonds:
        suitStr = "Diamonds";
        break;
    case Clubs:
        suitStr = "Clubs";
        break;
    case Spades:
        suitStr = "Spades";
        break;
    }

    switch (rank)
    {
    case One:
        rankStr = "One";
        break;
    case Two:
        rankStr = "2";
        break;
    case Three:
        rankStr = "3";
        break;
    case Four:
        rankStr = "4";
        break;
    case Five:
        rankStr = "5";
        break;
    case Six:
        rankStr = "6";
        break;
    case Seven:
        rankStr = "7";
        break;
    case Ten:
        rankStr = "8";
        break;
    case Eleven:
        rankStr = "9";
        break;
    case Twelve:
        rankStr = "10";
        break;
    }

    return rankStr + " of " + suitStr;
}

//Methode pour confirmer si la carte est valide
bool Card::isValid() const
{
    // Check if the card is valid based on the suit and rank
    return suit != InvalidSuit && rank != InvalidRank;
}

//Methode pour prendre les valeurs des cartes
int Card::getCardValue() const
{
    // Assign values based on ranks and suits
    switch (rank)
    {
    case One:
        return 1 + static_cast<int>(suit); // Add the suit value
    case Two:
        return 2 + static_cast<int>(suit);
    case Three:
        return 3 + static_cast<int>(suit);
    case Four:
        return 4 + static_cast<int>(suit);
    case Five:
        return 5 + static_cast<int>(suit);
    case Six:
        return 6 + static_cast<int>(suit);
    case Seven:
        return 7 + static_cast<int>(suit);
    case Ten:
        return 10 + static_cast<int>(suit);
    case Eleven:
        return 11 + static_cast<int>(suit);
    case Twelve:
        return 12 + static_cast<int>(suit);
    default:
        return 0; // Invalid rank
    }
}

