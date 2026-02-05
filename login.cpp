//
// Created by ratratarmy on 05/02/2026.
//

// You may need to build the project (run Qt uic code generator) to get "ui_login.h" resolved

#include "login.hpp"
#include "ui_login.h"
#include "home.hpp"
#include "register.hpp"
#include <QMessageBox>


LoginWND::LoginWND(QWidget *parent) : QWidget(parent), ui(new Ui::LoginWND) {
    ui->setupUi(this);
    connect(ui->pushButton, &QPushButton::clicked, this, &LoginWND::login);
    connect(ui->pushButton_2, &QPushButton::clicked, this, &LoginWND::go_to_register);
}

LoginWND::~LoginWND() {
    delete ui;
}

void LoginWND::login() {
    if ((ui->lineEdit->text() == "admin" or ui->lineEdit->text() == "admin@gmail.com")
        and ui->lineEdit_2->text() == "admin123") {
        HomeWND* home = new HomeWND();
        home->show();
        this->close();
    } else {
        auto btn = QMessageBox::critical(this, "Error", "Some information you entered is incorrect.\n"
            "Number of failed login attempts left: " + QString::number(num_of_failed_login_attempts_left - 1),
            QMessageBox::Ok | QMessageBox::Cancel);
        if (btn == QMessageBox::Ok) num_of_failed_login_attempts_left -= 1;
        else if (btn == QMessageBox::Cancel) num_of_failed_login_attempts_left = 0;
        if (num_of_failed_login_attempts_left == 0) {
            ui->lineEdit->setEnabled(false);
            ui->lineEdit_2->setEnabled(false);
            ui->pushButton->setEnabled(false);
            ui->pushButton_2->setEnabled(false);
        }
    }
}

void LoginWND::go_to_register() {
    RegisterWND* wind = new RegisterWND();
    wind->show();
    this->close();
}
