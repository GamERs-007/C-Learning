#include <iostream>
using namespace std;


class Shape{
public:
    virtual void fillArea() {
        cout << "Fill general\n";
    }
    virtual ~Shape() = default;
};

class Circle : public Shape {
public:
    void fillArea() override{
        cout << "Fill circle\n";
    }
};

class Square : public Shape {
public:
    void fillArea() override{
        cout << "Fill square\n";
    }
};

class Line : public Shape {
public:
    void fillArea() override{
        cout << "Fill line\n";
    }
};

class Panel {
public:
    void draw(Shape* ptr) {
        ptr->fillArea();
    }
};



int main() {
    Panel p;

    Shape g;
    Line l;
    Circle c;
    Square s;

    p.draw(&g); //general
    p.draw(&l); //line
    p.draw(&c); //circle
    p.draw(&s); //square
    return 0;
}
