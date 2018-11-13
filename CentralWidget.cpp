//
// Created by Erik Sevre on 11/6/18.
//

#include "CentralWidget.hpp"


#include <QSpacerItem>

//
//  Constructor
//
//  Create and set the layout
//  Setup the UI
//
CentralWidget::CentralWidget(QWidget *parent)
    : QWidget(parent)
{
    layout = new QGridLayout(this);
    this->setLayout(layout);
    this->setupUI();
}

//
//  Method to manage the layout of the widget
//
void CentralWidget::setupUI()
{
    pushButton1 = new QPushButton(tr("Push Me"), this);
    label1 = new QLabel(tr("Label: "), this);

    layout->addWidget(pushButton1, 1, 0);
    layout->addWidget(label1, 1, 1);

    updateLabel();
}

//
//  When the values have changed, the label will need to update with the correct text
//
void CentralWidget::updateLabel()
{
    QString label_string = QString(tr("Button pushed: "))
                           + QString::number(count)
                           + QString(tr(" times"));
    label1->setText(label_string);
}

// Method to handle the connections used by this widget
//   The button Click Signal will run the buttonActivated method in this object
//   The innerCounter will send a signal when the value has changed,
//      this will be connected to the method externalUpdate in this object
//
void CentralWidget::setupSignalsSlots(Counter *counter)
{
    innerCounter = counter;
    QObject::connect(pushButton1, SIGNAL(clicked()), this, SLOT(buttonActivated()));
    QObject::connect(innerCounter, SIGNAL(valueChanged(int)), this, SLOT(externalUpdate(int)));

}

void CentralWidget::buttonActivated()
{
    //
    //  Set the value in the Counter,
    //    This will trigger ALL widgets to update via externalUpdate
    //
    innerCounter->setValue(count + 1);

    //updateLabel();
}

void CentralWidget::externalUpdate(int newValue)
{
    //
    //  This is called when the counter object has changed its value
    //
    count = newValue;
    updateLabel();
}




