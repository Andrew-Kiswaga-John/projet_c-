#ifndef DIFFICULTY_H
#define DIFFICULTY_H
#include "gamepage.h"
#include "hardmode.h"

#include <QMainWindow>
#include <QWidget>

class Difficulty : public QMainWindow
{
    Q_OBJECT

public:
    Difficulty(QWidget *parent = nullptr);

private slots:
    void actualGame();
    void hardGame();

public slots:
    void oBackButtonClicked();




private:
    Gamepage *gamePage;
    Hardmode *hardPage;
    Difficulty *d ;

};

#endif // DIFFICULTY_H
