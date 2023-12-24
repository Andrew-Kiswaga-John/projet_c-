
#include "deck.h"
#include <algorithm>
#include <QRandomGenerator>

// Constructeur qui initialise tous les 40 cartes
Deck::Deck()
{
    // Initialize the deck with all combinations of suits and ranks
    for (int suit = Hearts; suit <= Spades; ++suit)
    {
        for (int rank = One; rank <= Twelve; ++rank)
        {
            cards.push_back(Card(static_cast<Suit>(suit), static_cast<Rank>(rank)));
        }
    }

    // Initialize the currentCardIndex
    currentCardIndex = 0;
}

// Methode pour donner les cartes aléatoires
void Deck::shuffle()
{
    // Shuffle the deck using the Fisher-Yates algorithm
    std::random_shuffle(cards.begin(), cards.end());

    // Reset the currentCardIndex after shuffling
    currentCardIndex = 0;
}

// Methode pour distribuer les cartes aléatoires
Card Deck::dealRandomCard()
{
    // Check if there are cards remaining in the deck
    if (!isEmpty())
    {
        // Generate a random index to select a card
        int randomIndex = QRandomGenerator::global()->bounded(
            static_cast<quint32>(currentCardIndex), static_cast<quint32>(cards.size()));


        // Swap the selected card with the currentCardIndex to ensure it won't be selected again
        std::swap(cards[currentCardIndex], cards[randomIndex]);

        // Return the selected card and increment the index
        return cards[currentCardIndex++];
    }
    else
    {
        // Return an invalid card if the deck is empty
        return Card(InvalidSuit, InvalidRank);
    }
}

//Methode pour donner les cartes les plus grandes mais aléatoires pour l'ajustement de niveau de difficultés
Card Deck::dealHighestRemainingCard()
{
    if (cards.empty())
    {
        // Handle the case when the deck is empty
        // You can throw an exception, return a default-constructed Card, or handle it as appropriate for your application.
        // For now, I'll return a default-constructed Card.
        return Card();
    }

    // Find the iterator pointing to the highest card in the remaining cards
    auto highestCardIt = std::max_element(cards.begin(), cards.end(),
                                          [](const Card& card1, const Card& card2)
                                          {
                                              return card1.getCardValue() < card2.getCardValue();
                                          });

    // Get the highest card from the iterator
    Card highestCard = *highestCardIt;

    // Remove the dealt card from the deck
    cards.erase(highestCardIt);

    return highestCard;
}

//Booléen pour confirmer si le Deck est vide
bool Deck::isEmpty() const
{
    // Check if all cards have been dealt
    return currentCardIndex >= cards.size();
}

//Methode pour reinitialiser le Deck de cartes
void Deck::resetDeck()
{
    // Reinitialize the deck with all combinations of suits and ranks
    cards.clear();
    for (int suit = Hearts; suit <= Spades; ++suit)
    {
        for (int rank = One; rank <= Twelve; ++rank)
        {
            cards.push_back(Card(static_cast<Suit>(suit), static_cast<Rank>(rank)));
        }
    }

    // Reset the currentCardIndex
    currentCardIndex = 0;
}
