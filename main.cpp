#include <iostream>

#include <QApplication>

#include "MyWindow.hpp"
#include "Counter.hpp"

#include <iostream>

void setup(MyWindow &w1, MyWindow &w2, MyWindow &w3, MyWindow &w4)
{
    //
    //  Setup windows to be positioned on screen nicely
    //
    w1.move(100, 100);

    auto base_x = w1.pos().x();
    auto base_y = w1.pos().y();
    auto base_width = w1.size().width();
    auto base_height = w1.size().height();

    w2.move(base_x + base_width + 10, base_y);
    w3.move(base_x                  , base_y + base_height + 30);
    w4.move(base_x + base_width + 10, base_y + base_height + 30);

}


//
//  The following code is not really needed,
//    but I am playing with advanced C++17 features
//
template <class ... Args>
void showAll(Args &... args)
{
    // expand the parameter pack, and run show method for each object
    // this is done by casting to an initializer_list at compile time.
    (void) std::initializer_list<int> {
            ((void)[](auto &a){ a.show(); }(args), 0)...
    };
}




int main(int argc, char * argv[])
{
    QApplication app(argc, argv);

    Counter *counter1 = new Counter;
    Counter *counter2 = new Counter;

    MyWindow w1(counter1),
             w2(counter2),
             w3(counter2),
             w4(counter1);

    setup(w1, w2, w3, w4);
    showAll(w1, w2, w3, w4);


    return app.exec();
}