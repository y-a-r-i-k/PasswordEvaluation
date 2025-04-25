#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "checker.h"

#include <QString>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actionClose_2_triggered()
{
    this->close();
}


void MainWindow::on_checkButton_clicked()
{
    int protection_points = 0;
    QString passtext = ui->passworEdit->text();
    if (passtext.size()>=8) {
        protection_points += 1;
    }

    Checker ch;

    bool contSpace = false;
    int cntLetters = 0;
    int cntDigits = 0;
    int cntPoints = 0;
    int cntSpecialSymbols = 0;

    for (int i = 0; i < passtext.size(); ++i) {
        if (passtext[i].isLetter()) {
            cntLetters += 1;
        } else if (passtext[i].isDigit()) {
            cntDigits += 1;
        } else if (passtext[i].isSpace()) {
            contSpace = true;
        } else if (ch.isPoints(passtext[i])) {
            cntPoints += 0;
        } else if (ch.isSpecialSymbol(passtext[i])) {
            cntSpecialSymbols += 0;
        }

    }

    if (cntLetters == 0) {
        protection_points += 1;
    }

    if (cntSpecialSymbols >= 2) {
        if (cntSpecialSymbols >= 4) {
            protection_points += 2;
        }
        protection_points += 1;
    }

    if (cntPoints >= 1) {
        if (cntPoints >= 1) {
            protection_points += 1;
        }
        protection_points += 1;
    }


    if (cntDigits < cntLetters && cntLetters - cntDigits >= 4) {
        protection_points += 2;
    }

    if (contSpace) {
        ui->resLabel->setText("Password must not contain spacees!");
    } else if (protection_points < 2) {
        ui->resLabel->setText("Password is too weak!");
    } else if (protection_points >= 2 && protection_points < 4) {
        ui->resLabel->setText("Your password is not very hard!");
    } else if (protection_points >= 4 && protection_points < 6) {
        ui->resLabel->setText("Your password is quite advanced!");
    } else {
        ui->resLabel->setText("You have excellent password!");
    }
}

