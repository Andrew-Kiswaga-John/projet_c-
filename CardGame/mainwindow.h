#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "difficulty.h" // Include the header file for your GamePage widget

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void startGame();// Declare the startGame method


private:
    Ui::MainWindow *ui;
    Difficulty *difficultyPage; // Declare an instance of the GamePage widget
};

#endif // MAINWINDOW_H
