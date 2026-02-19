//
// Created by 15165 on 2026/2/5.
//

#include "Polygon.h"
#include "Shape.h"
#include <iostream>
#include <string>


Polygon::Polygon(const std::string& desc, int n)
    : Shape(desc),
      size(n),
      vertex(new Point[n])
{
    std::cout << "Polygon constructor\n";
}

Polygon::Polygon(const Polygon& other)
    : Shape(other.description),
      size(other.size),
      vertex(new Point[other.size])
{
    std::cout << "Polygon copy constructor\n";
}

Polygon::~Polygon() {
    delete[] vertex;
    std::cout << "Polygon destructor\n";
}