//
// Created by ratratarmy on 05/02/2026.
//

#ifndef SOMENEWQT6_REGISTER_HPP
#define SOMENEWQT6_REGISTER_HPP

#include <QWidget>


QT_BEGIN_NAMESPACE

namespace Ui {
    class RegisterWND;
}

QT_END_NAMESPACE

class RegisterWND : public QWidget {
    Q_OBJECT

public:
    explicit RegisterWND(QWidget *parent = nullptr);

    ~RegisterWND() override;

private:
    Ui::RegisterWND *ui;
    void register_();
    void ret_to_login();
};


#endif //SOMENEWQT6_REGISTER_HPP