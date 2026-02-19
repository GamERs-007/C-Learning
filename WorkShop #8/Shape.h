//
// Created by 15165 on 2026/2/5.
//

#ifndef WORKSHOP__8_SHAPE_H
#define WORKSHOP__8_SHAPE_H

#include <string>
#include <iostream>
using namespace std;

class Shape {
public:
    Shape(const std::string& desc);

protected:
    std::string description;
};

#endif //WORKSHOP__8_SHAPE_H