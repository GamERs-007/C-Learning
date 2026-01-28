//
// Created by 15165 on 2026/1/21.
//

#include <iostream>
#include "Coordinate.h"


Coordinate::Coordinate():x(0), y(0) {
    std::cout << "default constructor of Coordinate invoked" << std::endl;

}

Coordinate::Coordinate(double xValue, double yValue) {
    std::cout << "parameter based constructor of Coordinate invoked" << std::endl;
}

Coordinate::Coordinate(const Coordinate& other):x(other.x), y(other.y) {
    std::cout << "copy constructor of Coordinate invoked" << std::endl;
}

Coordinate::~Coordinate() {
    std::cout << "destructure of Coordinate invoke" << std::endl;

}

Coordinate& Coordinate::setX(double xValue) {
    x = xValue;
    return *this; //the pointer to the class
}

Coordinate& Coordinate::setY(double yValue) {
    y = yValue;
    return *this; //the pointer to the class
}

double Coordinate::getX() const{
    std::cout << "x = " << x << std::endl;
    return x;
}

double Coordinate::getY() const{
    std::cout << "y = " << y << std::endl;
    return y;
}



void testCoordinate() {
    Coordinate point(3,2);
    // point.setX(5);
    // point.getX();
    //instead, u can do this,
    double val1 = point.setX(5).getX();
    double val2 = point.setY(5).getY();
    double val3 = point.setX(256.128).getX();
    double val4 = point.setY(1024.4096).getY();

}

