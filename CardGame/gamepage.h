#ifndef GAMEPAGE_H
#define GAMEPAGE_H

#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include<QLabel>
#include "deck.h"
#include "cards.h"

class Gamepage : public QWidget
{
    Q_OBJECT

public:
    Gamepage(QWidget *parent = nullptr);


private slots:
    void onDeckButtonClicked();
    void checkGameEnd();


signals:
    void checkGameEndSignal();

public slots:
    void onBackButtonClicked();


private:
    Deck deck;
    QPushButton *deckButton;
    QPushButton *card_11;
    QPushButton *card_22;
    QPushButton *card_33;
    QPushButton *card_44;
    QPushButton *card_1;
    QPushButton *card_2;
    QPushButton *card_3;
    QPushButton *card_4;
    QPushButton *playerButton;
    QPushButton *compButton;
    QLabel *comp_score;
    QLabel *player_score;
    int card1Value;
    int card2Value;
    int card3Value;
    int card4Value;
    QString card1ImageStyle;
    QString card2ImageStyle;
    QString card3ImageStyle;
    QString card4ImageStyle;




    void updateCardButton(QPushButton *button, const Card &card );
    void updatePlayerButton(QPushButton *cardButton);
    void playCompTurn();
    int getCardValue(QPushButton *cardButton);
    Card getCardFromButton(QPushButton *cardButton);
    void compareCardsAndScore();
    void resetGame();


};

#endif // GAMEPAGE_H




