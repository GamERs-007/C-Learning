//
// Created by 15165 on 2026/1/21.
//

#ifndef SRC_CODE_COORDINATE_H
#define SRC_CODE_COORDINATE_H

class Coordinate {

public:
    Coordinate();
    Coordinate(double x, double yValue);
    Coordinate(const Coordinate&);
    ~Coordinate();

    Coordinate& setX(double setX);
    double getX() const;

    Coordinate& setY(double setY);
    double getY() const;

private:
    double x;
    double y;
};

void testCoordinate();


#endif //SRC_CODE_COORDINATE_H