//
// Created by Erik Sevre on 11/5/18.
//

#include "Counter.hpp"

#include <iostream>

// When the value is set in the counter
//   a signal needs to be sent (with emit) to connected widgets
//
void Counter::setValue(int value)
{
    if (value != m_value) {
        m_value = value;
        emit valueChanged(value);
    }
}

// void Counter::valueChanged(int); // not implemented, just a placeholder for Qt



