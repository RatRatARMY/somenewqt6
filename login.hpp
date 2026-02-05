//
// Created by ratratarmy on 05/02/2026.
//

#ifndef SOMENEWQT6_LOGIN_HPP
#define SOMENEWQT6_LOGIN_HPP

#include <QWidget>


QT_BEGIN_NAMESPACE

namespace Ui {
    class LoginWND;
}

QT_END_NAMESPACE

class LoginWND : public QWidget {
    Q_OBJECT

public:
    explicit LoginWND(QWidget *parent = nullptr);

    ~LoginWND() override;

private:
    Ui::LoginWND *ui;
    int num_of_failed_login_attempts_left = 8;
    void login();
    void go_to_register();
};


#endif //SOMENEWQT6_LOGIN_HPP