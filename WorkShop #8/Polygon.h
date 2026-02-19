//
// Created by 15165 on 2026/2/5.
//

#ifndef WORKSHOP__8_POLYGON_H
#define WORKSHOP__8_POLYGON_H
#include "Shape.h"
#include "Point.h"

class Polygon : public Shape {
public:
    Polygon(const std::string& desc, int n);
    Polygon(const Polygon& other);
    ~Polygon();

protected:
    int size;
    Point* vertex;
};

#endif //WORKSHOP__8_POLYGON_H