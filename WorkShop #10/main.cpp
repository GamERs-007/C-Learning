#include <iostream>
using namespace std;


class Shape{
public:
    virtual void fillArea() const = 0;
    virtual ~Shape() = default;
};

class Circle : public Shape {
public:
    void fillArea() const override {
        cout << "Fill circle\n";
    }
};

class Square : public Shape {
public:
    void fillArea() const override {
        cout << "Fill square\n";
    }
};

class Line : public Shape {
public:
    void fillArea() const override {
        cout << "Fill line\n";
    }
};

class Panel {
public:
    static void draw(Shape* ptr) {
        ptr->fillArea();
    }
};



int main() {
    Panel p;

    Line l;
    Circle c;
    Square s;

    p.draw(&l); //line
    p.draw(&c); //circle
    p.draw(&s); //square
    return 0;
}
