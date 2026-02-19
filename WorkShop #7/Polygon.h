//
// Created by 15165 on 2026/2/2.
//

#ifndef WORKSHOP__7_POLYGON_H
#define WORKSHOP__7_POLYGON_H
#include <cstdlib>

class Polygon
{
public:
    Polygon(int n);
    Polygon(const Polygon&);
    ~Polygon(){};

private:
    int n;
    Point* points; //array of points

};

Polygon::Polygon(int sides): n(sides), points(new Point[n]){}

Polygon::Polygon(const Polygon& other): n(other.n), points(new Point[n])
{
    //separate address of points
    for (int i = 0; i < n; i++)
    {
        points[i] = other.points[i];
    }
}
// Polygon::Polygon(const Polygon& other): n(other.n), points(other.points)//wrong solution
// {
//
// }

Polygon::~Polygon()
{
    delete [] points;
}

class Rectangle: public Polygon
{
public:
    Rectangle(double w, double l) :Polygon(4), width(w), length(l){};
    Rectangle(const Rectangle& other): Polygon(other), width(other.width), length(other.length){}
    ~Rectangle();

private:
    double width;
    double length;
};

#endif //WORKSHOP__7_POLYGON_H