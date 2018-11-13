//
// Created by Erik Sevre on 11/5/18.
//

#pragma once

#include <QLabel>
#include <QPushButton>
#include <QMainWindow>
#include <QString>


#include <string>
#include <sstream>

#include "CentralWidget.hpp"
#include "Counter.hpp"


class MyWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MyWindow(QWidget *parent = 0);
    explicit MyWindow(Counter *counter, QWidget *parent = 0);

    virtual ~MyWindow();

private:
    void setupUI();

private:
    int button_push_count = 0;

    CentralWidget *centralWidget = nullptr;

    Counter *counter        = nullptr;
};



