//
// Created by 15165 on 2026/2/5.
//


#include "Square.h"
#include "Polygon.h"
#include <string>

Square::Square()
    : Polygon("Square", 4)   // calls Polygon constructor
{
    std::cout << "Square constructor\n";
}