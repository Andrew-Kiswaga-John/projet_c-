#include "difficulty.h"
#include "mainwindow.h"
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>
#include<QWidget>
#include "gamepage.h" // Include the header file for your GamePage widget

Difficulty::Difficulty(QWidget *parent)
    : QMainWindow(parent)
{
    // Create the difficulty selection page content
    QWidget *difficulty_window = new QWidget(this);


    QLabel *titleLabel = new QLabel("Choose Level");
    titleLabel->setAlignment(Qt::AlignCenter);

    QPushButton *easyButton = new QPushButton("Easy");
    easyButton->setFixedSize(200, 50);

    QPushButton *difficultButton = new QPushButton("Hard");
    difficultButton->setFixedSize(200, 50);

    QPushButton *backButton = new QPushButton("Back");
    backButton->setFixedSize(200, 50);



    easyButton->setStyleSheet("QPushButton {"
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

    backButton->setStyleSheet("QPushButton {"
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


    difficultButton->setStyleSheet("QPushButton {"
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

    titleLabel->setStyleSheet("QLabel {"
                           "    font-weight: bold;"
                           "    font-size: 30px;"
                           "    color: white;"
                           "}");

    // Create a layout for the difficulty selection page (you can choose QVBoxLayout or others)
    QVBoxLayout *layout = new QVBoxLayout(difficulty_window);
    layout->addWidget(titleLabel);
    layout->addSpacing(50); // Add some space between the title and buttons
    layout->addWidget(easyButton);
    layout->addWidget(difficultButton);
    layout->addWidget(backButton);
    layout->setAlignment(Qt::AlignCenter);

    setLayout(layout);


    connect(easyButton, &QPushButton::clicked, this, &Difficulty::actualGame);
    connect(difficultButton, &QPushButton::clicked, this, &Difficulty::hardGame);
    connect(backButton, &QPushButton::clicked, this, &Difficulty::oBackButtonClicked);






    setCentralWidget(difficulty_window);

}


void Difficulty::oBackButtonClicked()
{
    MainWindow *mainPage = new MainWindow();
    Difficulty *d = new Difficulty();
    mainPage->setStyleSheet("background-color: #000080;");
    mainPage->show();
    d->hide();
}


void Difficulty::actualGame()
{
    Gamepage *gamePage = new Gamepage();//on cree  un nouveau objet de la classe suivante (page)
    setCentralWidget(gamePage);//on definit le nouveau widget central a celle de la nouvelle page
    this->update();//on effectuer les modification


}

void Difficulty::hardGame()
{
    Hardmode *hardPage = new Hardmode();//on cree  un nouveau objet de la classe suivante (page)
    setCentralWidget(hardPage);//on definit le nouveau widget central a celle de la nouvelle page
    this->update();//on effectuer les modification

}

