//
// Created by Erik Sevre on 11/5/18.
//
//  Counter object to hold the value that is common
//    to multiple components of the program
//
#pragma once

#include <QObject>

class Counter : public QObject
{
    Q_OBJECT
public:
    Counter() { m_value = 0; }
public slots:
    void setValue(int value);
signals:
    void valueChanged(int newValue);
private:
    int m_value;
};


