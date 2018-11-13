//
// Created by Erik Sevre on 11/5/18.
//

#include "MyWindow.hpp"

#include <iostream>

#include <QVBoxLayout>

MyWindow::MyWindow([[maybe_unused]] QWidget *parent)
    : button_push_count(0)
{
    counter = new Counter;
    centralWidget = new CentralWidget(this);
    setupUI();
}

MyWindow::MyWindow(Counter *counter, [[maybe_unused]] QWidget *parent)
    : button_push_count(0)
    , counter(counter)
{
    centralWidget = new CentralWidget(this);
    setupUI();
}

void MyWindow::setupUI()
{

    this->setCentralWidget(centralWidget);

    this->setWindowTitle(tr("The Window Title"));
    this->resize(400, 260);

    centralWidget->setupSignalsSlots(counter);

}

MyWindow::~MyWindow()
{
    delete centralWidget;
}







