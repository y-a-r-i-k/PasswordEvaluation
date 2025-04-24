#include "mainwindow.h"
#include "ui_mainwindow.h"

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

    bool isNumper = true;
    for (int i = 0; i < passtext.size(); ++i) {
        if (!passtext[i].isDigit()) {
            isNumper = false;
        }
    }

    if (!isNumper) {
        protection_points += 1;
    }


    if (protection_points < 2) {
        ui->resLabel->setText("Password is too weak!");
    } else if (protection_points >= 2 && protection_points < 4) {
        ui->resLabel->setText("Your password is not very hard!");
    } else if (protection_points >= 4 && protection_points < 6) {
        ui->resLabel->setText("Your password is quite advanced!");
    } else {
        ui->resLabel->setText("You have excellent password!");
    }
}

