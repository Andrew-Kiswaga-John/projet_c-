#include "mainwindow.h"
#include<QLabel>
#include<QWidget>
#include <QVBoxLayout>
#include<QPushButton>
#include<QFrame>
#include "difficulty.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)

{
    this->setStyleSheet("background-color: #000080;"); // Set background color to navy blue

    // Declaration de tous les Widgets qui vont etre utilisée dans cette Page
    QWidget *my_window = new QWidget(this);
    QVBoxLayout *my_container = new QVBoxLayout(my_window);
    QLabel *my_text = new QLabel("HIGH OR LOW");
    QFrame *my_image = new QFrame;
    QPushButton *start_button = new QPushButton("Start Game");
    QPushButton *exit_button = new QPushButton("Exit Game");

    // Manipulation des Widgets declarer

    start_button->setFixedSize(200, 50);
    exit_button->setFixedSize(200, 50);

    my_image->setFixedSize(720, 400);
    my_image->setStyleSheet("background-image: url(:/image/logo.jpeg);");

    my_container->addWidget(my_text, 0, Qt::AlignCenter);
    my_container->addSpacing(30);
    my_container->addWidget(my_image, 0, Qt::AlignCenter);
    my_container->addWidget(start_button, 0, Qt::AlignCenter);
    my_container->addWidget(exit_button, 0, Qt::AlignCenter);

    start_button->setStyleSheet("QPushButton {"
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

    exit_button->setStyleSheet("QPushButton {"
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

    my_text->setStyleSheet("QLabel {"
                           "    font-weight: bold;"
                           "    font-size: 30px;"
                           "    color: white;"
                           "}");

    setCentralWidget(my_window);

    connect(start_button, &QPushButton::clicked, this, &MainWindow::startGame);
    connect(exit_button, &QPushButton::clicked, this, &MainWindow::close);




}

//Methode pour aller à la prochaine page

void MainWindow::startGame()
{
    Difficulty *difficultyPage = new Difficulty();//on cree  un nouveau objet de la classe suivante (page)
    setCentralWidget(difficultyPage);//on definit le nouveau widget central a celle de la nouvelle page
    this->update();//on effectuer les modification


}
MainWindow::~MainWindow()
{

}


