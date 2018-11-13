//
// Created by Erik Sevre on 11/6/18.
//

#pragma once

#include <QWidget>

#include <QLabel>
#include <QLayout>
#include <QPushButton>
#include <QGridLayout>

#include "Counter.hpp"

//
//  Central widget to manage buttons and update information with
//
class CentralWidget : public QWidget
{
    Q_OBJECT
public:
    explicit CentralWidget(QWidget *parent);

    void updateLabel();
    void setupSignalsSlots(Counter *counter);

public slots:
    void buttonActivated();
    void externalUpdate(int newValue);

private:
    void setupUI();

    Counter *innerCounter;
    int count = 0;
    QGridLayout *layout;
    QLabel *label1           = nullptr;
    QPushButton *pushButton1 = nullptr;
};


