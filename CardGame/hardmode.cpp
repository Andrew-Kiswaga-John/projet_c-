#include "hardmode.h"
#include "difficulty.h"
#include <QLabel>
#include <QWidget>
#include <QVBoxLayout>
#include <QFrame>
#include<QWidget>
#include <QHBoxLayout>
#include <QPushButton>
#include <QTimer>
#include <QMessageBox>
#include <QRegularExpression>
#include <QRegularExpressionMatch>
#include <QApplication>

Hardmode::Hardmode(QWidget *parent)
    : QWidget (parent)
{
    // Creating the gamepage interface

    QVBoxLayout *game_container = new QVBoxLayout(this);


    // Première partie d'interface qui a le bouton pour retourner à la page precedente et qui indique le niveau de difficulté choisi

    QWidget *settPageContainer = new QWidget(this);
    QHBoxLayout *settings_tab = new QHBoxLayout(settPageContainer);
    QPushButton *back_button = new QPushButton("Back");
    QLabel *description = new QLabel("HARD MODE");

    description->setStyleSheet("QLabel {"
                               "    font-weight: bold;"
                               "    font-size: 30px;"
                               "    color: white;"
                               "}");

    back_button->setFixedSize(50,50);

    back_button->setStyleSheet("QPushButton {"
                               "    background-color: white;"
                               "    color: black;"
                               "    border-radius: 15px;"
                               "    border: none;"
                               "}"
                               "QPushButton:hover {"
                               "    background-color: gray;"
                               "    color: white;"
                               "}"
                               "QPushButton:pressed {"
                               "    background-color: white;"
                               "    color: black;"
                               "}");

    settings_tab->addWidget(back_button, 0, Qt::AlignLeft);
    settings_tab->addWidget(description, 0, Qt::AlignLeft);

    game_container->addWidget(settPageContainer);


  // Deuxième partie d'interface qui est la partie de Joueur Ordinateur

    QWidget *compPlayerContainer = new QWidget(this);
    QHBoxLayout *Comp_player = new QHBoxLayout(compPlayerContainer);
    card_1 = new QPushButton;
    card_2 = new QPushButton;
    card_3 = new QPushButton;
    card_4 = new QPushButton;
    comp_score = new QLabel(" CPU SCORE: 0 ");

    comp_score->setStyleSheet("QLabel {"
                              "    font-weight: bold;"
                              "    font-size: 30px;"
                              "    color: white;"
                              "}");

    card_1->setFixedSize(90, 135);
    card_2->setFixedSize(90, 135);
    card_3->setFixedSize(90, 135);
    card_4->setFixedSize(90, 135);

    card_1->setStyleSheet("background-image: url(:/image/blank.gif);");
    card_2->setStyleSheet("background-image: url(:/image/blank.gif);");
    card_3->setStyleSheet("background-image: url(:/image/blank.gif);");
    card_4->setStyleSheet("background-image: url(:/image/blank.gif);");

    Comp_player->addWidget(card_1, 0, Qt::AlignCenter);
    Comp_player->addWidget(card_2, 0, Qt::AlignCenter);
    Comp_player->addWidget(card_3, 0, Qt::AlignCenter);
    Comp_player->addWidget(card_4, 0, Qt::AlignCenter);
    Comp_player->addWidget(comp_score, 0, Qt::AlignCenter);


    game_container->addWidget(compPlayerContainer);

  // Troisième partie d'interface qui est la partie de place de jeu (Play Area)
    QWidget *playArea = new QWidget(this);
    QHBoxLayout *play_AreaLayout = new QHBoxLayout(playArea);
    deckButton = new QPushButton;
    playerButton = new QPushButton;
    compButton = new QPushButton;

    deckButton->setFixedSize(90, 135);
    deckButton->setStyleSheet("background-image: url(:/image/back.gif);");

    playerButton->setFixedSize(90, 135);
    compButton->setFixedSize(90, 135);

    playerButton->setStyleSheet("QPushButton {"
                                "border-radius: 10px;"
                                "background-color: gray;"

                                "}");

    compButton->setStyleSheet("QPushButton {"
                              "border-radius: 10px;"
                              "background-color: gray;"

                              "}");

    play_AreaLayout->addWidget(deckButton, 0, Qt::AlignLeft);
    play_AreaLayout->addWidget(playerButton, 0, Qt::AlignLeft);
    play_AreaLayout->addWidget(compButton, 0, Qt::AlignLeft);



    playArea->setStyleSheet("QWidget {"
                            "border-radius: 10px;"
                            "background-color: gray;"

                            "}");


    game_container->addWidget(playArea, 2);

    // Quatrième partie d'interface qui est la partie de Joueur Normal

    QWidget *PlayerContainer = new QWidget(this);
    QHBoxLayout *Player = new QHBoxLayout(PlayerContainer);
    card_11 = new QPushButton;
    card_22 = new QPushButton;
    card_33 = new QPushButton;
    card_44 = new QPushButton;
    player_score = new QLabel(" PLAYER SCORE: 0 ");


    player_score->setStyleSheet("QLabel {"
                                "    font-weight: bold;"
                                "    font-size: 30px;"
                                "    color: white;"
                                "}");

    card_11->setFixedSize(90, 135);
    card_22->setFixedSize(90, 135);
    card_33->setFixedSize(90, 135);
    card_44->setFixedSize(90, 135);

    card_11->setStyleSheet("background-image: url(:/image/blank.gif);");
    card_22->setStyleSheet("background-image: url(:/image/blank.gif);");
    card_33->setStyleSheet("background-image: url(:/image/blank.gif);");
    card_44->setStyleSheet("background-image: url(:/image/blank.gif);");

    Player->addWidget(card_11, 0, Qt::AlignCenter);
    Player->addWidget(card_22, 0, Qt::AlignCenter);
    Player->addWidget(card_33, 0, Qt::AlignCenter);
    Player->addWidget(card_44, 0, Qt::AlignCenter);
    Player->addWidget(player_score, 0, Qt::AlignCenter);


    game_container->addWidget(PlayerContainer);

    connect(deckButton, &QPushButton::clicked, this, &Hardmode::onDeckButtonClicked);
    connect(card_11, &QPushButton::clicked, this, [this]() { updatePlayerButton(card_11); playCompTurn(); });
    connect(card_22, &QPushButton::clicked, this, [this]() { updatePlayerButton(card_22); playCompTurn(); });
    connect(card_33, &QPushButton::clicked, this, [this]() { updatePlayerButton(card_33); playCompTurn(); });
    connect(card_44, &QPushButton::clicked, this, [this]() { updatePlayerButton(card_44); playCompTurn(); });


    // Connect checkGameEnd to the relevant signal
    connect(this, &Hardmode::checkGameEndSignal, this, &Hardmode::checkGameEnd);

    connect(back_button, &QPushButton::clicked, this, &Hardmode::onBackButtonClicked);


}

// Methode qui va etre envoqué lorsqu'on clique le back_button
void Hardmode::onBackButtonClicked()
{
    Difficulty *difficultyPage = new Difficulty();
    difficultyPage->setStyleSheet("background-color: #000080;");
    difficultyPage->show();
    this->close();
}

//Methode qui distribue les cartes lorsqu'on clique le deck_button
void Hardmode::onDeckButtonClicked()
{
    const int numCardsToDeal = 8;
    const int delayIncrement = 200; // milliseconds
    int currentDelay = 200;

    // Deal the highest cards to card_1, card_2, and card_3
    for (int i = 0; i < 5; ++i)
    {
        QTimer::singleShot(currentDelay, [this, i]() {
            // Deal a random card from the deck
            Card dealtCard = deck.dealRandomCard();

            // Update the corresponding card button
            switch (i)
            {
            case 0:
               updateCardButton(card_11, dealtCard);
               break;
            case 1:
                updateCardButton(card_22, dealtCard);
                break;
            case 2:
                updateCardButton(card_33, dealtCard);
                break;
            case 3:
                updateCardButton(card_44, dealtCard);
                break;
            case 4:
                updateCardButton(card_4, dealtCard);
                card_4->setStyleSheet("background-image: url(:/image/back.gif);");
                break;
            }
        });

        // Increment the delay for the next card
        currentDelay += delayIncrement;
    }

    // Deal random cards to the remaining buttons
    for (int i = 5; i < numCardsToDeal; ++i)
    {
        QTimer::singleShot(currentDelay, [this, i]() {
            // Deal the highest remaining card from the deck
            Card highestCard = deck.dealHighestRemainingCard();

            // Update the corresponding card button
            switch (i)
            {
            case 5:
                updateCardButton(card_3, highestCard);
                card_3->setStyleSheet("background-image: url(:/image/back.gif);");
                break;
            case 6:
                updateCardButton(card_2, highestCard);
                card_2->setStyleSheet("background-image: url(:/image/back.gif);");
                break;
            case 7:
                updateCardButton(card_1, highestCard);
                card_1->setStyleSheet("background-image: url(:/image/back.gif);");
                break;
            }
        });

        // Increment the delay for the next card
        currentDelay += delayIncrement;
}
 }


// Methode qui va mise à jour les boutons des cartes de l'ordinateur lorsqu'ils sont jouèe
 void Hardmode::updateCardButton(QPushButton *button, const Card &card)
{
// Update the appearance of the button based on the dealt card
button->setFixedSize(90, 135);
button->setStyleSheet(QString("background-image: url(%1);").arg(card.getCardImage()));

QString imageStyle = QString("background-image: url(%1);").arg(card.getCardImage());
button->setFixedSize(90, 135);
button->setStyleSheet(imageStyle);

// Update the corresponding member variable based on the button
if (button == card_1)
        card1ImageStyle = imageStyle;
else if (button == card_2)
        card2ImageStyle = imageStyle;
else if (button == card_3)
        card3ImageStyle = imageStyle;
else if (button == card_4)
        card4ImageStyle = imageStyle;

// Update the corresponding card value
if (button == card_1)
        card1Value = card.getCardValue();
else if (button == card_2)
        card2Value = card.getCardValue();
else if (button == card_3)
        card3Value = card.getCardValue();
else if (button == card_4)
        card4Value = card.getCardValue();
}


// Methode qui va mise à jour les boutons des cartes de joueur lorsqu'ils sont cliquer
void Hardmode::updatePlayerButton(QPushButton *cardButton)
{
    // Set the playerButton's background image based on the clicked card
QString backgroundImage = cardButton->styleSheet();
backgroundImage.replace("background-image:", "").trimmed(); // Remove "background-image:" and trim spaces

// Set the playerButton's background image
playerButton->setStyleSheet(QString("background-image: %1;").arg(backgroundImage));

// Reset the clicked card's background image to the default
cardButton->setStyleSheet("background-color: green;");

}

// Methode qui va prendre la valuer des cartes
int Hardmode::getCardValue(QPushButton *cardButton)
{
// Extract the card value from the background image path
QString imagePath = cardButton->styleSheet();
imagePath.replace("background-image:", "").trimmed(); // Remove "background-image:" and trim spaces

// Use the Card class to get the value
Card card = getCardFromButton(cardButton);
return card.getCardValue();
}

//Methode qui va etre invoquer pour mettre une carte dans la place de Jeu
Card Hardmode::getCardFromButton(QPushButton *cardButton)
{
// Extract the rank and suit from the background image path
QString imagePath = cardButton->styleSheet();
imagePath.replace("background-image:", "").trimmed(); // Remove "background-image:" and trim spaces

QRegularExpression regex(":/image/cards/(\\d+)_(\\w+).gif");
QRegularExpressionMatch match = regex.match(imagePath);

if (match.hasMatch())
{
        // Convert the matched strings to Rank and Suit enums
        Rank rank = static_cast<Rank>(match.captured(1).toInt());
        Suit suit;
        QString suitStr = match.captured(2);
        if (suitStr == "Hearts")
            suit = Hearts;
        else if (suitStr == "Diamonds")
            suit = Diamonds;
        else if (suitStr == "Clubs")
            suit = Clubs;
        else if (suitStr == "Spades")
            suit = Spades;

        // Create and return the Card object
        return Card(suit, rank);
}

return Card(); // Return a default-constructed Card if not matched
}

// Cette methode est la logique pour l'ordinateur
void Hardmode::playCompTurn()
{
// Check if playerButton has a background image or color
bool hasBackgroundImage = playerButton->styleSheet().contains("background-image");
bool hasBackgroundColor = playerButton->styleSheet().contains("background-color");

if (hasBackgroundImage && !hasBackgroundColor)
{
        // Get the value of the card clicked by the player
        int playerCardValue = getCardValue(playerButton);

        // Find the highest card among card_1, card_2, card_3, and card_4
        int highestCardValue = std::max({card1Value, card2Value, card3Value, card4Value});

        // Find a card higher than the player's card among card_1, card_2, card_3, and card_4
        QPushButton* compCardButton = nullptr;
        QString compCardImageStyle;
        if (highestCardValue > playerCardValue)
        {
            // Find the first card that is higher than the player's card
            if (card1Value > playerCardValue)
            {
                compCardButton = card_1;
                compCardImageStyle = card1ImageStyle;
            }
            else if (card2Value > playerCardValue)
            {
                compCardButton = card_2;
                compCardImageStyle = card2ImageStyle;
            }
            else if (card3Value > playerCardValue)
            {
                compCardButton = card_3;
                compCardImageStyle = card3ImageStyle;
            }
            else if (card4Value > playerCardValue)
            {
                compCardButton = card_4;
                compCardImageStyle = card4ImageStyle;
            }
        }

        // If no card is higher, use the highest card
        if (!compCardButton)
        {
            if (highestCardValue == card1Value)
            {
                compCardButton = card_1;
                compCardImageStyle = card1ImageStyle;
            }
            else if (highestCardValue == card2Value)
            {
                compCardButton = card_2;
                compCardImageStyle = card2ImageStyle;
            }
            else if (highestCardValue == card3Value)
            {
                compCardButton = card_3;
                compCardImageStyle = card3ImageStyle;
            }
            else if (highestCardValue == card4Value)
            {
                compCardButton = card_4;
                compCardImageStyle = card4ImageStyle;
            }
        }

        // Update compButton with the chosen card
        if (compCardButton)
        {
            QTimer::singleShot(800, [this, compCardButton, compCardImageStyle]() {
                // Check if playerButton still has a background image before updating compButton
                if (playerButton->styleSheet().contains("background-image") || compButton->styleSheet().contains("background-image"))
                {
                    // Use the stored image style for compButton
                    compButton->setStyleSheet(compCardImageStyle);

                    // Update the corresponding card button to the default blank image
                    compCardButton->setStyleSheet("background-color: green;");
                    compareCardsAndScore();
                }
            });
        }
}
// If playerButton has a background color, do nothing
}


// Cette methode va comparer les cartes mis sur la place de Jeux et afficher le score
void Hardmode::compareCardsAndScore()
{
// Get the values of the cards in compButton and playerButton
int compCardValue = getCardValue(compButton);
int playerCardValue = getCardValue(playerButton);

// Compare the values and update scores
if (compCardValue > playerCardValue)
{
        // Computer wins, update comp_score
        int currentCompScore = comp_score->text().split(":").back().trimmed().toInt();
        comp_score->setText(" CPU SCORE: " + QString::number(currentCompScore + 2));

        comp_score->setStyleSheet("QLabel {"
                                  "    font-weight: bold;"
                                  "    font-size: 30px;"
                                  "    color: white;"
                                  "}");
        // Add an 800 ms delay before updating both playerButton and compButton
        QTimer::singleShot(800, [this]() {
            playerButton->setStyleSheet("background-color: gray;");
            compButton->setStyleSheet("background-color: gray;");
        });
}
else
{
        // Player wins, update player_score
        int currentPlayerScore = player_score->text().split(":").back().trimmed().toInt();
        player_score->setText(" PLAYER SCORE: " + QString::number(currentPlayerScore + 2));

        player_score->setStyleSheet("QLabel {"
                                    "    font-weight: bold;"
                                    "    font-size: 30px;"
                                    "    color: white;"
                                    "}");

        // Add an 800 ms delay before updating both playerButton and compButton
        QTimer::singleShot(800, [this]() {
            playerButton->setStyleSheet("background-color: gray;");
            compButton->setStyleSheet("background-color: gray;");
        });


}

// You may want to check for a tie and handle it accordingly
// Add your tie handling logic here if needed

checkGameEnd();

emit checkGameEndSignal();
}

// Cette methode invoque pour afficher le gagnant, perdant et donner la possiblité de recommencer ou bien quitter le Jeu
void Hardmode::checkGameEnd()
{
static int numComparisons = 0;

// Increment the number of comparisons
numComparisons++;

// Check if 20 comparisons have been reached
if (numComparisons >= 40)
{
        // Display a message box indicating game over
        QString winnerMessage;
        int compScore = comp_score->text().split(":").back().trimmed().toInt();
        int playerScore = player_score->text().split(":").back().trimmed().toInt();

        if (compScore > playerScore)
        {
            winnerMessage = "Game Over! CPU Wins!";
        }
        else if (compScore < playerScore)
        {
            winnerMessage = "Game Over! Player Wins!";
        }
        else
        {
            winnerMessage = "Game Over! It's a Tie!";
        }

        QMessageBox gameOverMessageBox;
        gameOverMessageBox.setWindowTitle("Game Over");
        gameOverMessageBox.setText(winnerMessage);
        gameOverMessageBox.setStandardButtons(QMessageBox::Retry | QMessageBox::Abort);

        int result = gameOverMessageBox.exec();

        // Handle the user's choice
        if (result == QMessageBox::Retry)
        {
            numComparisons = 0;
            resetGame();
        }
        else if (result == QMessageBox::Abort)
        {
            // Quit the game
            QApplication::quit();
        }
}
}

// Cette méthode réinitialise chaque aspect du jeu à ce qu'il était avant le début du jeu.
void Hardmode::resetGame()
{
// Reset all variables and UI elements to their initial state

// Reset scores
comp_score->setText(" CPU SCORE: 0 ");
player_score->setText(" PLAYER SCORE: 0 ");

// Reset card buttons
card_1->setStyleSheet("background-color: green;");
card_2->setStyleSheet("background-color: green;");
card_3->setStyleSheet("background-color: green;");
card_4->setStyleSheet("background-color: green;");

card_11->setStyleSheet("background-color: green;");
card_22->setStyleSheet("background-color: green;");
card_33->setStyleSheet("background-color: green;");
card_44->setStyleSheet("background-color: green;");

// Reset deck button
deckButton->setStyleSheet("background-image: url(:/image/back.gif);");

// Reset player and computer buttons
playerButton->setStyleSheet("background-image: none;");
compButton->setStyleSheet("background-image: none;");

// Reset the deck
deck.resetDeck();
}

