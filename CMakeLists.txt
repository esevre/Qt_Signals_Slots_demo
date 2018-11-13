cmake_minimum_required(VERSION 3.12)
project(Qt_Signals_Slots_demo)


set(CMAKE_CXX_STANDARD 14)

#
#  Qt loading features
#
find_package(Qt5 REQUIRED widgets)
set(CMAKE_AUTOMOC ON)



add_executable(Qt_Signals_Slots_demo main.cpp Counter.cpp Counter.hpp MyWindow.cpp MyWindow.hpp CentralWidget.cpp CentralWidget.hpp)

# link the Qt libraries
target_link_libraries(Qt_Signals_Slots_demo Qt5::Widgets)