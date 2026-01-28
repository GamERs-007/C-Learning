//
// Created by 15165 on 2026/1/28.
//


#include "switch.h"
#include <iostream>

using namespace std;

//initialized at the class level;
int Switch::objectCounter{0};


//default constructor
// member initialization list

//NO direct assignment of pointers!!!
Switch::Switch() : state(false), id(new int(0)) {
    ++objectCounter;
    std::cout << "class Switch Default constructor called\n";
}


// Parameterized constructor
Switch::Switch(bool value) : state(value), id(new int(0)) {
    ++objectCounter;
    std::cout << "class Switch Parameterized constructor called\n";
}

// Copy constructor // midterm programming questions
Switch::Switch(const Switch& other) : state(other.state), id(new int(*(other.id))) {
    ++objectCounter;
    std::cout << "class Switch Copy constructor called\n";
}

// Destructor
Switch::~Switch() {

    delete id; //for the case creating only one element;

    //delete[] id; // for the case creating more than one elements;

    --objectCounter;
    std::cout << "class Switch Destructor called\n";
}

// Function overloading: setState
Switch& Switch::setState(bool value) {
    state = value;
    return *this;
}

Switch& Switch::setId(int id) {

    *(this->id) = id;
    return *this;
}

// Getter for state
bool Switch::getState() const {
    return state;
}

// Getter for id
int Switch::getId() const {
    return *id;
}

//clone itself;
Switch Switch::clone() const{
    return *this;
}

//clone the object passed by reference;
Switch Switch::clone(const Switch& other) const{
    return Switch(other);
}

